#include<stdio.h>
#include<stdlib.h>

/*---------------------------------------------------------
* 函  数：cuts
* 说  明：使用分隔字符串拆分原字符串,将拆分结果保存到字符数组中
* 环境变量:无
* 参  数：
          char *s1  拟拆分的原字符串
          char *sp  分隔字符串
* 输  出：char *a[] 返回的字符数组
* 返  回: 无
---------------------------------------------------------*/
int cuts(char *s1,char *sp,char *a[])
{
	int i=0,j=0,k=0,m=0,n=0;
 	int cFlag=0;
  k=strlen(sp); /*分割字符串长度*/
  a[0]=s1;      /*待拆分的原字符串*/
  while(s1[i])  /*判断s1[i] 字符是否为NULL*/
  {
    m=0;
    n=i;
		if(cFlag==0 && s1[i]>=0x80)
		{
			cFlag=1;
			i++;
			continue;
		}

		if(cFlag==1)
		{
			cFlag=0;
			i++;
			continue;
		}

      while(s1[i]==sp[m])
      {
          i++;
          m++;
          if(m==k)
               break;
      }
      if(m==k)
      {
          s1[i-k]='\0';
          j++;
          a[j]=&s1[i];
      }else   i=n+1;
  }
  return j+1;
}

int main()
{
}
