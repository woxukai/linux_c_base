#ifndef _SEQ_LIST_H_
#define _SEQ_LIST_H_

#include "datatype.h"

#define MAX 100

typedef struct {
	data_t data[MAX];
	int last; 
}seqlist_t;

/*
*¹¦ÄÜ:create a list and init it as empty
*input: void
*output:void
*return new list,NULL when failed
*/
seqlist_t *CreateEmptyList();

/*
*function:destroy list
*input: list*
*output:void
*return void
*/
void DestroyList(seqlist_t *pList);

/*
*function:clear list
*input: list*
*output:void
*return void
*/
void ClearList(seqlist_t *pList);


/*
*function:judge list is if NULL
*input: list*
*output:void
*return int : 1:null 0:not null -l:error
*/
int IsEmpty(seqlist_t *pList);

/*
*function:judge list is if full
*input: list*
*output:void
*return int : 1:full 0:not full -l:error
*/
int IsFull(seqlist_t *pList);

/*
*function:get length
*input: list*
*output:void
*return int : >=0 length -l:error
*/
int GetLengthSeqList(seqlist_t *pList);



/*
*function:get data of seqlist
*input: list*,int,data_t *
*output:data*
*return 0:success -l:fail
*/
int GetEle(seqlist_t *pList,int at,data_t *x);

/*
*function:set data of seqlist
*input: list*,int,data_t *
*output:data*
*return 0:success -l:fail
*/
int SetElem(seqlist_t *pList,int at,data_t *x);

/*
*function:Ins elem of seqlist
*input: list*,int,data_t *
*output:data*
*return 0:success -l:fail
*/
int InsElem(seqlist_t *pList,int at,data_t *x);

/*
*function:del elem of seqlist
*input: list*,int
*output:void
*return 0:success -l:fail
*/
int DelElem(seqlist_t *pList,int at);


#endif /*_SEQ_LIST_H_*/
