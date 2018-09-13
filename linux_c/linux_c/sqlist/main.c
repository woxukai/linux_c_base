#include<stdio.h>
#include<stdlib.h>
#include "seqlist.h"
//#include "datatype.h"

int main(int argc,const char* argv[])
{
	seqlist_t *pList = CreateEmptyList();
	DestroyList(pList);
	return 0;
}
