#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>

int main()
{
	int err;
	struct timespec tout;
	struct tm *tmp;
	char buf[24];
	pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&lock);
	printf("mutex is lock\n");
	clock_gettime(CLOCK_REALTIME,&tout);
	tmp=localtime(&tout.tv_sec);
	strftime(buf,sizeof(buf),"%r",tmp);
	printf("current time is %s\n",buf);
	tout.tv_sec+=10;
	err=pthread_mutex_timedlock(&lock,&tout);
	clock_gettime(CLOCK_REALTIME,&tout);
	tmp=localtime(&tout.tv_sec);
	strftime(buf,sizeof(buf),"%r",tmp);
	printf("the time is now  %s\n",buf);
	exit(0);

}
