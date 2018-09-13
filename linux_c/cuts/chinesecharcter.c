#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char sText[]="1234ÄãºÃ!";
	int iLen=strlen(sText);
	unsigned char c=0;
	int i=0;
/*
	for(i=0;i<iLen;i++)
	{
		c=(unsigned char)sText[i];
		//printf("sText[%d]=%c\n",i,(unsigned char)sText[i]);
		printf("sText[%d]=%u\n",i,c);
		printf("sText[%d]=0x%02x\n",i,(unsigned char)sText[i]);
		printf("sText[%d]=%02d\n",i,(unsigned char)sText[i]);
	}*/
	int a=128;
	char cc=37;
	printf("cc==%c\n",cc);
	
}
