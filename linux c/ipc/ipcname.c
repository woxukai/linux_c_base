#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>

char *px_ipc_name(const char *name)
{
	char *dir,*dst,*slash;
	char sErrMsg[1024];
	if((dst = malloc(PATH_MAX))==NULL )
	{
		return NULL;
	}
	
	if((dir = getenv("PX_IPC_NAME")) == NULL)
	{
		#ifdef POSIX_IPC_PREFIX
			dir = POSIX_IPC_PREFIX;
		#else
			dir = "/tmp";
		#endif
	}

	slash = (dir[strlen(dir)-1] =='/') ? "":"/";
	snprintf(dst,PATH_MAX,"%s%s%s",dir,slash,name);
	printf("1111 dst=%s \n",dst);
	memset(sErrMsg,0x00,sizeof(sErrMsg));
	sprintf(sErrMsg,"dst =%s",dst);
	perror(sErrMsg);
	return dst;
}



int main(int argc,char **argv)
{
	px_ipc_name("test");
	system("pause");	
	return 0;
}
