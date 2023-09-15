#define _CRT_SECURE_NO_WARNINGS 1

#include "cSqList.h"

static Status exCapacity(SqList* L)
{
	ElemType* tmp = NULL;
	if(L->length < L->capacity)
		return OK;
	tmp = (ElemType*)realloc( L->elem,sizeof(ElemType) * (L->length+EXPAND) );
	if(tmp == NULL)
		return OVERFLOW;
	L->elem = tmp;
	L->capacity = L->length+EXPAND;
	return OK;
}

Status InitList_Sq(SqList* L)
{
	ElemType* tmp = (ElemType*)malloc(sizeof(ElemType) * CAPACITY);
	if(tmp == NULL)
		return OVERFLOW;
	L->elem = tmp;
	L->length = 0;
	L->capacity = 0;
	return OK;
}

void DestroyList_Sq(SqList* L)
{
	free(L->elem);
	L->elem = NULL;
	L->length = 0;
}

void ClearList_Sq(SqList* L)
{
	L->length = 0;
}

int GetLength_Sq(SqList* L)
{
	return L->length;
}

int isEmpty_Sq(SqList* L)
{
	if(L->length == 0)
		return 1;
	return 0;
}

// T(n) = O(1)
int GetElem_Sq(SqList* L,int i, ElemType* e)
{
	if( (i<1) || (i>L->length) )	// 判断位置i的合理性
		return ERROR;
	*e = L->elem[i-1];
	return OK;
}

// T(n) = O(n)
int LocateElem_Sq(SqList* L, const ElemType e)
{
	int i = 0;
	for(i=0;i<L->length;i++)
	{
		if(L->elem[i] == e)
			return i+1;
	}
	return 0;
}

// T(n) = O(n)
Status ListInsert_Sq(SqList* L, int i, const ElemType e)
{
	int j = 0;
	if( (i<1) || (i>L->length+1) )	// 判断位置i的合理性
		return ERROR;
	if(OVERFLOW == exCapacity(L))	// 判断容量是否已满
		return OVERFLOW;	

	for(j = L->length;j > i-1;j--)	// 将元素往后移动
	{
		L->elem[j] = L->elem[j-1];
	}
	L->elem[i-1] = e;	// 给指定位置赋值
	++(L->length);
	return OK;
}

// T(n) = O(n)
Status ListDelete_Sq(SqList* L, int i)
{
	int j = 0;
	if( (i<1) || (i>L->length+1) )	// 判断位置i的合理性
		return ERROR;
	for(j=i ; j < L->length ;j++)	// 将被删除元素之后的元素前移
	{
		L->elem[j-1] = L->elem[j];
	}
	--(L->length);	// 表长减一
	return OK;
}