#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>


static void sig_int(int);

int main(void)
{
	sigset_t newmask,oldmask,waitmask;
	printf("program start:");
	
	if(signal(SIGINT,sig_int) == SIG_ERR)
	{
		err_sys("signal(SIGINT) error ");
	}

	sigemptyset(&waitmask);
	sigaddset(&waitmask,SIGUSR1);
	sigemptyset(&newmask);
	sigaddset(&newmask,SIGINT);

	/*
	 *Block SIGINT and save current signal mask.
	 * */
	if(sigprocmask(SIG_BLOCK,&newmask,&oldmask) < 0 )
	{
		err_sys("SIG_BLOCK error");
	}

	/*
	 *Critial region of code.
	 * */

	printf("in critical region: ");
	
	/*
	 *pause,allowing all signals except SIGUSR1
	 * */
	
	if(sigsuspend(&waitmask) != -1 )
	{
		err_sys("sigsuspend error");
	}

	printf("after return from sigsuspend: ");

	/**
	 *Reset signal mask which unblocks SIGINT.
	 * */
	if(sigprocmask(SIG_SETMASK,&oldmask,NULL) < 0 )
	{
		err_sys("SIG_SETMASK  error");
	}

	/*
	 *And continue processing....
	 */

	exit(0);

}

static void sig_int(int signo)
{
	printf("\n in sig_int: ");
}
