#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/times.h>


#include "sortingAlgorithms.h"
#include "utils.h"

/*-------------- Same as quicksort.c ----------*/

int main(int argc,char ** argv){

	/*------- Timers initialization -----------*/
	double t1,t2,cpu_time,ticspersec,real_time;
	struct tms tb1,tb2;
	ticspersec = (double) sysconf(_SC_CLK_TCK);
	t1 = times(&tb1);
	/*------------- Variables initialization ------------------*/
	int i=1,fileDesc,columnId,offset,numOfRecords,endRecord,pipefd;
	
	while(argv[i]!=NULL){

		if(!strcmp(argv[i],"-f")){
			fileDesc = open(argv[i+1],O_RDWR,O_CREAT);

			if(fileDesc<0)
				perror("File didn't open ");

			i++;
		}else if(!strcmp(argv[i],"-c")){
			columnId = atoi(argv[i+1]);
			i++;
		}else if(!strcmp(argv[i],"-lim")){

			offset = atoi(argv[i+1]);
			endRecord = atoi(argv[i+2]);
			i=i+2;
		}else if(!strcmp(argv[i],"-p")){
			pipefd = atoi(argv[i+1]);
			i++;
		}else
			printf("Something unexpected happen while reading heapsort's arguments\n");
		
		i++;
	}

	numOfRecords = endRecord - offset ;
	lseek(fileDesc,offset*sizeof(Record),SEEK_SET);

	Record **array = malloc(numOfRecords*sizeof(Record *));
	
	if(array == NULL)
		perror("Memory allocation in heapsort failed");

	for(int r=0;r<numOfRecords;r++){
		array[r] = malloc(sizeof(Record));
		if(read(fileDesc,array[r],sizeof(Record))==0){
			printf("Number of records inserted is bigger than the file numOfRecords\n");
			printf("File reading out of bounds,EOF reached\n");
			printf("Exiting from the program\n");
			exit(1);
		}
	}

	heapsort((void **)array,numOfRecords,columnId);
	
	for(int r=0;r<numOfRecords;r++)
		write(pipefd,array[r],sizeof(Record));
	
	/*----------- Time mesurement -------------- */	
	
	t2 = (double) times(&tb2);
	cpu_time = (double) ((tb2.tms_utime + tb2.tms_stime) - ((tb1.tms_utime + tb1.tms_stime)))/ticspersec;
	real_time = (t2-t1)/ticspersec;
	sorterStatistics * node = malloc(sizeof(sorterStatistics));
	node->real_time = real_time;
	node->cpu_time = cpu_time;
	
	write(pipefd,node,sizeof(sorterStatistics));

	close(pipefd);
	close(fileDesc);

	for(int r=0;r<numOfRecords;r++){
		free(array[r]);array[r]=NULL;
	}free(array);array=NULL;
	free(node);
	kill(getppid(),SIGUSR2);

return 0;
}
