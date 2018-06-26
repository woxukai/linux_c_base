#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>
#include<sys/syscall.h>

//define gettid() syscall(__NR_gettid)
//using namespace std;

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
	
	printf("pid=%d,threadid=%ld\n",getpid(),pthread_self());	
  /*	res=pthread_mutex_lock(&mutex);//��������
	if(res)
	{
		printf("Thread %d lock failed \n",thrd_num);
		pthread_exit(NULL);
	}
*/

	for(count=0;count< REPEAT_NUMBER;++count)
	{
		delay_time=(int)(rand()*DELAY_TIME_LEVELS/(RAND_MAX))+1;
		printf("thread [%d],delay_time=[%d]\n",thrd_num,delay_time);
		//sleep(delay_time);
	}
	
	printf("Thread %d is finished \n",thrd_num);
	//pthread_mutex_unlock(&mutex); //����������

	printf("Thread %d is exiting \n",thrd_num);
	pthread_exit(NULL);	
	
}


int main()
{
	pthread_t thread[THREAD_NUMBER];
	int no=0,res;
	void *thrd_ret=(void*)-1;
	srand(time(NULL)); //���������
//	pthread_mutex_init(&mutex,NULL); //��������ʼ��
	
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

		printf("thread join finish,no=%d \n",no);
		//pthread_mutex_unlock(&mutex); //����������
	}	
	
	printf("thread join all finish \n");
	//pthread_mutex_destroy(&mutex);
	return 0;	
}
