#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>

static jmp_buf env_alrm;

static void sig_alrm(int signo)
{
	longjmp(env_alrm,1);
}

unsigned int sleep2(unsigned int seconds)
{
	if(signal(SIGALRM,sig_alrm) == SIG_ERR)
	{
		printf("fffffffff\n");
		return (seconds);
	}

	if(setjmp(env_alrm) == 0)
	{
		printf("seconds = %d\n",seconds);
		alarm(seconds); /*start the timer*/
		pause(); /*next caught signal wakes us up*/
	}
	
	return(alarm(0));
}


static void sig_int(int signo);

int main(void)
{
	unsigned int unslept;

	if(signal(SIGINT,sig_int) == SIG_ERR)
	{
		err_sys("signal(SIGINT) error");
	}

	unslept = sleep2(1);
	printf("sleep2 returned:%u\n",unslept);
	exit(0);

}


static void sig_int(int signo)
{
	int i,j;
	volatile int k;
	printf("\nsig_int starting\n");
	for(i=0; i < 300000; i++)
	{
		for(j=0; j < 4000; j++)
		{
			k+=i*j;
		}
	}

	printf("sig_int finished\n");
}
