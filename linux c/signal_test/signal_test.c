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

int main(void)
{
	unsigned int unslept;
	sleep2(1);
	exit(0);

}
