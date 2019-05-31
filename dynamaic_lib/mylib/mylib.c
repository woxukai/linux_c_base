#include <stdio.h>

void fun()
{
	printf("<func = %s,line = %d>\n",__FUNCTION__,__LINE__);
}

int add(int a,int b)
{
	int c = a+b;	
	printf("c = %d\n",c);
	return c;
}
