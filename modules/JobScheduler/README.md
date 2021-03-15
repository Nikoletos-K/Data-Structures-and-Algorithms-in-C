# Job Scheduler - Threads implementation
Created a multi-thread job scheduler using Unix pthreads.

The module in the folder /modules/JobScheduler consists of:

- A scheduler, which actually accepts jobs and assigns them to threads, uses a priority queue to temporarily store the jobs. 
- I have a thread pool and a continuous flow of independent jobs. When a task is created, it enters the scheduler's priority queue and waits to be executed. 
- The work is performed in the order they were created (first-in-first-out - FIFO). Each thread waits in line until it is assigned a task and, after performing it, returns to the queue to undertake a new task. 
- For the proper operation of a scheduler, it is necessary to use semaphores in the queue, in order to block the threads there, and the critical section, so that tasks can be properly imported and exported from the queue.

Benefits of this module:

- The number of threads is not abused (as they are reused) and we take advantage of all the acceleration they can offer.
- Independent tasks such as those mentioned above are parallelized resulting in acceleration.


## Link with other modules
For using this module follow these steps:
1. Download this directory ```JobScheduler``` which contains file ```JobScheduler.c```
2. Go to directory ```include``` and download also ```JobScheduler.h```
3. __Repeat the same steps for ```Queue```__
4. Fix the ```#include``` paths
5. Ready!


## Structure
```
typedef struct JobScheduler {

	size_t pool_size;   // number of execution threads
	pthread_t * threads;
	Queue * jobsQueue;
	int jobScheduler_shutDown;
	int numOfJobs;

	pthread_mutex_t queue_mtx;
	pthread_cond_t queue_not_empty;
	pthread_cond_t queue_empty;
	pthread_cond_t cond_barrier;
	
} JobScheduler;


typedef struct Job {

	void * args;
	void (*routine)(void*);

} Job;
```

## Main Functionality
```
JobScheduler * initialize_scheduler(int execution_threads);
Job * new_job(void * args,void (*routine)(void*));
void destroy_job(Job *  job);
void submit_job(JobScheduler* scheduler,void (*routine)(void*),void * args);
void execute_job(JobScheduler * scheduler);
void wait_activeJobs_finish(JobScheduler* scheduler);
void shutdown_JobScheduler(JobScheduler* scheduler);
void destroy_scheduler(JobScheduler* scheduler);
```
