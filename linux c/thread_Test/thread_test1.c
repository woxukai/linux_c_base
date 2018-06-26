#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>

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
	char sFilePath[512]="/gaps/xk/test/thread_Test/threadfile";
	char sFileFullPath[1024]="";
    FILE *fp = NULL;
	printf("Thread %d is starting \n",thrd_num);
	memset(sFileFullPath,0x00,sizeof(sFileFullPath));
	sprintf(sFileFullPath,"%s/threadtest_%d.txt",sFilePath,thrd_num);
	printf("sFileFullPath=%s \n",sFileFullPath);
	
	res=pthread_mutex_lock(&mutex);//ª•≥‚…œÀ¯
	if(res)
	{
		printf("Thread %d lock failed \n",thrd_num);
		pthread_exit(NULL);
	}

	fp=fopen(sFileFullPath,"w+");		
	for(count=0;count< REPEAT_NUMBER;++count)
	{
		delay_time=(int)(rand()*DELAY_TIME_LEVELS/(RAND_MAX))+1;
		printf("thread [%d],delay_time=[%d]\n",thrd_num,delay_time);
		fprintf(fp,"delay_time=[%d]\n",delay_time);
		sleep(delay_time);
	}
	
	//fflush(fp);	
	fclose(fp);

	printf("Thread %d is finished \n",thrd_num);
	pthread_mutex_unlock(&mutex); //ª•≥‚À¯Ω‚À¯

	printf("Thread %d is exiting \n",thrd_num);
	pthread_exit(NULL);	
	
}


int main()
{
	pthread_t thread[THREAD_NUMBER];
	int no=0,res;
	void *thrd_ret=(void*)-1;
	srand(time(NULL)); //ÀÊª˙ ˝÷÷◊”
	pthread_mutex_init(&mutex,NULL); //ª•≥‚À¯≥ı ºªØ
	
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
		//pthread_mutex_unlock(&mutex); //ª•≥‚À¯Ω‚À¯
	}	
	
	printf("thread join all finish \n");
	pthread_mutex_destroy(&mutex);
	return 0;	
}
