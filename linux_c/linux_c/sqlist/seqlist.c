#include<stdio.h>
#include<stdlib.h>
#include "seqlist.h"

/*
*function:create a list and init it as empty
*input: void
*output:void
*return new list,NULL when failed
*/
seqlist_t *CreateEmptyList()
{
	seqlist_t *pList;
	pList = (seqlist_t*)malloc(sizeof(seqlist_t));
	if(!pList)
	{
		pList->last=-1;
	}

	return pList; 
}

/*
*function:destroy list
*input: list*
*output:void
*return void
*/
void DestroyList(seqlist_t *pList)
{
	if(pList !=NULL)
	{
		free(pList);
		pList = NULL;
	}
}

/*
*function:clear list
*input: list*
*output:void
*return void
*/
void ClearList(seqlist_t *pList)
{
	if(pList == NULL)
	{
		return;
	}
	
	pList->last=-1;
}


/*
*function:judge list is if NULL
*input: list*
*output:void
*return int : 1:null 0:not null -l:error
*/
int IsEmpty(seqlist_t *pList)
{
	if(pList == NULL)
	{
		return -1;
	}
	
	if(pList->last == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
*function:judge list is if full
*input: list*
*output:void
*return int : 1:full 0:not full -l:error
*/
int IsFull(seqlist_t *pList)
{
	if(pList == NULL)
	{
		return -1;
	}
	
	if(MAX==pList->last+1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
*function:get length
*input: list*
*output:void
*return int : >=0 length -l:error
*/
int GetLengthSeqList(seqlist_t *pList)
{
	if(pList ==NULL)
	{
		return -1;
	}
	else
	{
		return pList->last+1;
	}
}



/*
*function:get data of seqlist
*input: list*,int,data_t *
*output:data*
*return 0:success -l:fail
*/
int GetElem(seqlist_t *pList,int at,data_t *x)
{
	if(pList == NULL)
	{
		return -1;
	}
	
	if(at<0 ||at > pList->last)
	{
		return -1;
	}

	*x=pList->data[at];
	return 0;
}

/*
*function:set data of seqlist
*input: list*,int,data_t *
*output:data*
*return 0:success -l:fail
*/
int SetElem(seqlist_t *pList,int at,data_t *x)
{
	if(pList == NULL)
    {
        return -1;
    }

    if(at<0 ||at > pList->last)
    {
        return -1;
    }

    pList->data[at]=*x;
    return 0;
}

/*
*function:Ins elem of seqlist
*input: list*,int,data_t *
*output:data*
*return 0:success -l:fail
*/
int InsElem(seqlist_t *pList,int at,data_t *x)
{
	int i=0;
	if(pList == NULL)
    {
        return -1;
    }

    if(IsFull(pList) ||at < 0)
	{
		return -1;
	}

	if(at > pList->last)
	{
		at=pList->last+1;
	}
	else
	{
	    for(i=pList->last;i>at;i--)
        {
            pList->data[i+1]=pList->data[i];
        }
	}
    
    pList->data[at]=*x;
    pList->last++;
    
	return 0;
}

/*
*function:del elem of seqlist
*input: list*,int
*output:void
*return 0:success -l:fail
*/
int DelElem(seqlist_t *pList,int at)
{
	int i=0;
	if((pList ==NULL) || (at<0 || at>pList->last))
	{
		return -1;
	}
	
	for(i=0;i<pList->last;i++)
	{
		pList->data[i]=pList->data[i+1];
	}

	pList->data[pList->last]=0;
	pList->last--;
	return 0;
}

