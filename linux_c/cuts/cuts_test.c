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
	//int bHighBit=0; /*判断分隔符之前的前一位是否是高位*/
	int iFlag=false; /*未发现分隔符*/
	k=strlen(sp); /*分割字符串长度*/
	a[0]=s1;      /*待拆分的原字符串，用于存放原待拆分内容*/

	
	while(s1[i])  /*判断s1[i] 字符是否为NULL*/
	{
		m=0; //分隔符的下标索引
		n=i; //原字符串下标index标记
	
		/*
    	if(cFlag==0 && s1[i]>=0x80)
    	{
        	cFlag=1;
        	i++;
        	continue;
    	}

		//判断字节的高位是否大于128，如果大于，说明是多字节
    	if(cFlag==1)
    	{
    		cFlag=0;
        	i++;
        	continue;
    	}
		*/     
		
		//判断是否大于等于128,不是ascii字符
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
		︻樊珅||1111||珅一||樊###珅||
		*/
		//判断是否找到了对应的截取字符
		while(s1[i]==sp[m])
		{
			//printf("s1[%d]=%x\n",i-1,s1[i-1]);
			//printf("s1[%d]=%c\n",i,s1[i]);
			
			//printf("i=%d\n",i); 
			//printf("value=%c\n",s1[i-1]);
			//判断前一位是否是高位	  	
			/*if(i > 0 && (unsigned char)s1[i-1] >=0x80) //判断索引位置是否大于0
			{
				printf("i=%d\n",i); 
				printf("111 s1[%d]=%c\n",i-1,s1[i-1]);
				printf("111 s1[%d]=%c\n",i,s1[i]);
				i++; //跳过一次
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
		
		//判断是否找到了	  
		if(iFlag)
		{
			//获取分割的内容
			s1[i-k]='\0';
			printf("a[%d]=%s\n",j,a[j]);
			j++;
			a[j]=&s1[i]; //存放的多维数组，指向下一个数组内容，索引从1...开始
			iFlag=false;
		}
		else
		{
			i=n+1; //没有找到，指向下一个字符
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
	char sTemp[]="22樊珅||1111||珅一||樊###|";
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
