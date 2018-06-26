#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/shm.h>
#include "shmdata.h"

int main()
{
	int running=1; //判断是否运行
	void *shm=NULL;//共享内存地址
	int shmid; //共享内存标识
	struct shared_use_st *shared=NULL;
	shmid=shmget((key_t)1234,sizeof(struct shared_use_st),0666|IPC_CREAT);
	if(shmid==-1)
	{
		fprintf(stderr,"shmget failed\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Memory attached at %X\n",(int)shm);
	
	//将共享内存连接到当前进程的地址空间
	shm=shmat(shmid,(void*)0,0);
	if(shm==(void*)-1)
	{
		fprintf(stderr,"shmat failed\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Memory attached at %X\n",(int)shm);
	
	shared=(struct shared_use_st*)shm;
	printf("writeten=%d,text=%s\n",shared->writeten,shared->text);
	
	shared->writeten=1;
	//shared->text=1;
	
	printf("writeten=%d,text=%s\n",shared->writeten,shared->text);
	
	//把共享内存从当前进程中分离
	if(shmdt(shm)==-1)
	{
		fprintf(stderr,"shmdt failed\n");
		exit(EXIT_FAILURE);
	}
	
	//删除共享内存
	if(shmctl(shmid,IPC_RMID,0)==-1)
	{
		fprintf(stderr,"shmctl IPC_RMID failed\n");
		exit(EXIT_FAILURE);
	}
	
	exit(EXIT_SUCCESS);
}

