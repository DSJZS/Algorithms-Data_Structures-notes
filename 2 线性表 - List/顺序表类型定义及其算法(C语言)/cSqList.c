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
	if( (i<1) || (i>L->length) )	// �ж�λ��i�ĺ�����
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
	if( (i<1) || (i>L->length+1) )	// �ж�λ��i�ĺ�����
		return ERROR;
	if(OVERFLOW == exCapacity(L))	// �ж������Ƿ�����
		return OVERFLOW;	

	for(j = L->length;j > i-1;j--)	// ��Ԫ�������ƶ�
	{
		L->elem[j] = L->elem[j-1];
	}
	L->elem[i-1] = e;	// ��ָ��λ�ø�ֵ
	++(L->length);
	return OK;
}

// T(n) = O(n)
Status ListDelete_Sq(SqList* L, int i)
{
	int j = 0;
	if( (i<1) || (i>L->length+1) )	// �ж�λ��i�ĺ�����
		return ERROR;
	for(j=i ; j < L->length ;j++)	// ����ɾ��Ԫ��֮���Ԫ��ǰ��
	{
		L->elem[j-1] = L->elem[j];
	}
	--(L->length);	// ����һ
	return OK;
}