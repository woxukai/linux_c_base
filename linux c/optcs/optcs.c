#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc,char **argv)
{
  printf("argc=[%d]\n",argc);
	char ch;
//	char optarg[100];
	char sFile[100];
	int iPort=0;
	printf("aaaaaaaaa\n");
	 while ((ch = getopt(argc,argv,"p:f:h")) != EOF) {
				printf("ch=%c\n",ch);
                switch (ch) {
                case 'f' :
                        (void)sscanf (optarg,"%s",sFile);
                        break;
                case 'p' :
                        iPort=atoi(optarg);
                        break;
                case '?' :
                case 'h' :
                        fprintf(stderr,"USGE swCliGT <-f file.dat> [-h]\n");
                        return(1);
                }
        }	
	printf("iport=%d,filename=%s\n",iPort,sFile);
}
