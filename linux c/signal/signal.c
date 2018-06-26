#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void SignHandler(int iSignNum)
{
	printf("sign number is :%d\n",iSignNum);
    return;
}

int main()
{
	signal(SIGINT,SignHandler);
	while(1)
		sleep(1);

	return 0;
}
