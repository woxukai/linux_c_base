#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>
#include <sys/stat.h>



int main(int argc,char **argv)
{
	struct stat statbuf;
	
	if(argc != 2)
	{	
		perror("参数不对");
		exit(-1);
	}
	
	stat(argv[1],&statbuf);
	printf("st_dev:%lx,st_ino:%lx,key:%x\n",
	(u_long)statbuf.st_dev,(ulong)statbuf.st_ino,
	ftok(argv[1],0x57));
	
	system("pause");	
	return 0;
}
