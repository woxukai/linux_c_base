#include<stdio.h>
#include<stdlib.h>

/*---------------------------------------------------------
* ��  ����cuts
* ˵  ����ʹ�÷ָ��ַ������ԭ�ַ���,����ֽ�����浽�ַ�������
* ��������:��
* ��  ����
          char *s1  ���ֵ�ԭ�ַ���
          char *sp  �ָ��ַ���
* ��  ����char *a[] ���ص��ַ�����
* ��  ��: ��
---------------------------------------------------------*/
int cuts(char *s1,char *sp,char *a[])
{
	int i=0,j=0,k=0,m=0,n=0;
 	int cFlag=0;
  k=strlen(sp); /*�ָ��ַ�������*/
  a[0]=s1;      /*����ֵ�ԭ�ַ���*/
  while(s1[i])  /*�ж�s1[i] �ַ��Ƿ�ΪNULL*/
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
