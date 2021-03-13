#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/times.h>

#include <pthread.h>
#include <unistd.h>

#include "./../../include/JobScheduler.h"


JobScheduler * initialize_scheduler(int execution_threads){

	JobScheduler * scheduler = malloc(sizeof(JobScheduler));
	scheduler->pool_size = execution_threads;
	scheduler->threads = malloc(sizeof(pthread_t)*scheduler->pool_size);
	scheduler->jobsQueue = createQueue();
	scheduler->jobScheduler_shutDown=false;
	scheduler->numOfJobs = 0;

	pthread_mutex_init(&(scheduler->queue_mtx),0);
	pthread_cond_init(&(scheduler->queue_not_empty),0);
	pthread_cond_init(&(scheduler->queue_empty),0);
	pthread_cond_init(&(scheduler->cond_barrier),0);

	int err;
	for(int t=0;t<execution_threads;t++){
		if( (err = pthread_create(&scheduler->threads[t],NULL,thread_function,(void*) scheduler))){
			perror2("pthread_create",err);
			exit(EXIT_FAILURE);
		}
	}

	return scheduler;
}

Job * new_job(void * args,void (*routine)(void*)){

	Job * job = malloc(sizeof(Job));
	job->args = args;
	job->routine = routine;

	return job;
}


void destroy_job(Job *  job){

	if(job->args != NULL) free(job->args);
	free(job);
}



void submit_job(JobScheduler* scheduler,void (*routine)(void*),void * args){

	pthread_mutex_lock(&(scheduler->queue_mtx));

	Job * job = new_job(args,routine);
	QueuePush(scheduler->jobsQueue,(void*)job);
	scheduler->numOfJobs++;

	pthread_cond_signal(&scheduler->queue_not_empty);
	pthread_cond_signal(&scheduler->cond_barrier);

	pthread_mutex_unlock(&(scheduler->queue_mtx));
}


void * thread_function(void * scheduler_arguments){

	JobScheduler * scheduler = (JobScheduler*) scheduler_arguments;

	while(true){

		pthread_mutex_lock(&(scheduler->queue_mtx));

		while(emptyQueue(scheduler->jobsQueue) && scheduler->jobScheduler_shutDown == false)
			pthread_cond_wait(&scheduler->queue_not_empty,&scheduler->queue_mtx);
	
		if(emptyQueue(scheduler->jobsQueue) && scheduler->jobScheduler_shutDown == true){
			pthread_mutex_unlock(&(scheduler->queue_mtx));
			pthread_exit(NULL);
		}else
			execute_job(scheduler);
	}
}


void execute_job(JobScheduler * scheduler){

	Job * job = (Job *) QueuePop(scheduler->jobsQueue);
	pthread_mutex_unlock(&(scheduler->queue_mtx));

	void (*routine)(void*) = job->routine;
	void * job_args = job->args;

 	routine(job_args);

 	pthread_mutex_lock(&(scheduler->queue_mtx));

 	destroy_job(job);
 	scheduler->numOfJobs--;

 	if(scheduler->numOfJobs == 0)
 		pthread_cond_signal(&scheduler->queue_empty);

 	pthread_mutex_unlock(&(scheduler->queue_mtx));
}

void wait_activeJobs_finish(JobScheduler* scheduler){

	pthread_mutex_lock(&(scheduler->queue_mtx));
	
	while(scheduler->numOfJobs > 0)
		pthread_cond_wait(&scheduler->queue_empty,&scheduler->queue_mtx);

	pthread_mutex_unlock(&(scheduler->queue_mtx));
}

void shutdown_JobScheduler(JobScheduler* scheduler){

	pthread_mutex_lock(&(scheduler->queue_mtx));
	scheduler->jobScheduler_shutDown = true;
	pthread_cond_broadcast(&scheduler->queue_not_empty);
	pthread_mutex_unlock(&(scheduler->queue_mtx));

	int err;
	for(int t=0;t<scheduler->pool_size;t++){
		if((err = pthread_join(scheduler->threads[t],NULL))){
			perror2("pthread_join",err);
			exit(EXIT_FAILURE);
		}
	}
}

void destroy_scheduler(JobScheduler* scheduler){

	shutdown_JobScheduler(scheduler);
	
	pthread_cond_destroy(&(scheduler->queue_not_empty));
	pthread_cond_destroy(&(scheduler->queue_empty));
	pthread_cond_destroy(&(scheduler->cond_barrier));
	pthread_mutex_destroy(&(scheduler->queue_mtx));

	deleteQueue(scheduler->jobsQueue);
	free(scheduler->threads);
	free(scheduler);
}