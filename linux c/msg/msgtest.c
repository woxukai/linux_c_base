#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/msg.h>
#include <fcntl.h>
#icnlude <unistd.h>
#include <error.h>



int main(int argc,char **argv)
{
	int l,msgid;
	msgid =msgget(IPC_PRIVATE,IPC_CREAT|SVMSG_MODE);
	printf("msgid=%d\n",msgid);
	msgctl(msgid,IPC_RMID,NULL);	
	system("pause");	
	return 0;
}
