#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef __TYPES__
#define __TYPES__
#define false 0
#define true 1
#endif

int cuts(char *s1,char *sp,char *a[])
{
	int i=0,j=0,k=0,m=0,n=0;
	//int bHighBit=0; /*�жϷָ���֮ǰ��ǰһλ�Ƿ��Ǹ�λ*/
	int iFlag=false; /*δ���ַָ���*/
	k=strlen(sp); /*�ָ��ַ�������*/
	a[0]=s1;      /*����ֵ�ԭ�ַ��������ڴ��ԭ���������*/

	
	while(s1[i])  /*�ж�s1[i] �ַ��Ƿ�ΪNULL*/
	{
		m=0; //�ָ������±�����
		n=i; //ԭ�ַ����±�index���
	
		/*
    	if(cFlag==0 && s1[i]>=0x80)
    	{
        	cFlag=1;
        	i++;
        	continue;
    	}

		//�ж��ֽڵĸ�λ�Ƿ����128��������ڣ�˵���Ƕ��ֽ�
    	if(cFlag==1)
    	{
    		cFlag=0;
        	i++;
        	continue;
    	}
		*/     
		
		//�ж��Ƿ���ڵ���128,����ascii�ַ�
		//if((unsigned char)s1[i]>=0x80)
		if((unsigned char)s1[i]>=0x80)
		{
			printf("s1[%d]=%x\n",i,s1[i]);
 			i=i+2;
    		continue;
		}
   		
		printf("s1[%d]=%x\n",i,s1[i]);
		
		//printf("i=%d\n",i); 
		/*
		��|||1111||�|һ||��###�|||
		*/
		//�ж��Ƿ��ҵ��˶�Ӧ�Ľ�ȡ�ַ�
		while(s1[i]==sp[m])
		{
			//printf("s1[%d]=%x\n",i-1,s1[i-1]);
			//printf("s1[%d]=%c\n",i,s1[i]);
			
			//printf("i=%d\n",i); 
			//printf("value=%c\n",s1[i-1]);
			//�ж�ǰһλ�Ƿ��Ǹ�λ	  	
			/*if(i > 0 && (unsigned char)s1[i-1] >=0x80) //�ж�����λ���Ƿ����0
			{
				printf("i=%d\n",i); 
				printf("111 s1[%d]=%c\n",i-1,s1[i-1]);
				printf("111 s1[%d]=%c\n",i,s1[i]);
				i++; //����һ��
				continue;
			}*/
			
			
			i++;
			m++;
			if(m==k)
			{
				iFlag=true;
				break;
			}     
		}
		
		//�ж��Ƿ��ҵ���	  
		if(iFlag)
		{
			//��ȡ�ָ������
			s1[i-k]='\0';
			printf("a[%d]=%s\n",j,a[j]);
			j++;
			a[j]=&s1[i]; //��ŵĶ�ά���飬ָ����һ���������ݣ�������1...��ʼ
			iFlag=false;
		}
		else
		{
			i=n+1; //û���ҵ���ָ����һ���ַ�
		}
	  
	  	
  	}

  	printf("j=[%d],a[0]=[%s]\n",j,a[0]);
  	return j+1;
}

int main()
{
	int nsize=0;
	int i=0;
	char *sDes[200];
	char sbuf[10000]="";
	char sTemp[]="22���|||1111||�|һ||��###|";
	//char sTemp[]="aaa||bbb||ccc||";
	/*char sTemp[1000]="";
	FILE *fp = NULL;
	fp=fopen("test2.txt","r");
	size_t bytes_read;
	bytes_read=fread(sTemp,sizeof(sTemp),1,fp);
	fclose(fp);
	printf("sTemp[]=%s,sTemp[] len=%d\n",sTemp,strlen(sTemp));*/

	nsize=cuts(sTemp,"||",sDes);
	/*fp=fopen("cutcontent.txt","wb+");
	for(i=0;i<nsize;i++)
	{
		printf("sDes[%d]=[%s]\n",i,sDes[i]);
		memset(sbuf,0x00,sizeof(sbuf));
		sprintf(sbuf,"%s\n",sDes[i]);
		fwrite(sbuf,strlen(sbuf),1,fp);
	}
	//fwrite(sbuf,sizeof(sbuf),1,fp);
	fclose(fp);*/
	system("pause");
}
