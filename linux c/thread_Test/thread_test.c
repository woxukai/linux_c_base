#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define THREAD_NUMBER 3
#define REPEAT_NUMBER 5
#define DELAY_TIME_LEVELS 2.0
pthread_mutex_t mutex;

void *thrd_func(void* arg)
{
	int thrd_num = (int)arg;
	int delay_time =0;
	int count=0;
	int res;

	res=pthread_mutex_lock(&mutex);//互斥上锁
	if(res)
	{
		printf("Thread %d lock failed \n",thrd_num);
		pthread_exit(NULL);
	}
	printf("Thread %d is starting \n",thrd_num);
	
	for(count=0;count< REPEAT_NUMBER;++count)
	{
		delay_time=(int)(rand()*DELAY_TIME_LEVELS/(RAND_MAX))+1;
		printf("delay_time=[%d]\n",delay_time);
		sleep(delay_time);
	}

	printf("Thread %d is finished \n",thrd_num);
	pthread_exit(NULL);	
	
}


int main()
{
	pthread_t thread[THREAD_NUMBER];
	int no=0,res;
	void *thrd_ret;
	srand(time(NULL)); //随机数种子
	pthread_mutex_init(&mutex,NULL); //互斥锁初始化
	
	for(no=0;no<THREAD_NUMBER;no++)
	{
		res=pthread_create(&thread[no],NULL,thrd_func,(void*)no);
		if(0 != res)
		{
			printf("thread create failed,no=%d \n",no);
			exit(res);
		}
	}	
	
	for(no=0;no<THREAD_NUMBER;no++)
	{
		res=pthread_join(thread[no],&thrd_ret);
		if(0 != res)
		{
			printf("thread join failed,no=%d \n",no);
		}
		pthread_mutex_unlock(&mutex); //互斥锁解锁
	}	
	
	pthread_mutex_destroy(&mutex);
	return 0;	
}
