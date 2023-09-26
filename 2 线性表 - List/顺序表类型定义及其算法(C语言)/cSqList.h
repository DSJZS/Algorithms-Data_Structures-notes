#ifndef __CSQLIST_H__
#define __CSQLIST_H__

// ͷ�ļ�
#include<stdio.h>
#include<stdlib.h>

// �������״̬����
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

// Status �Ǻ���������
typedef int Status;
typedef int ElemType;

// ��ʼ��ʱ�����ɶ��ٸ�Ԫ�صĿռ�����
#define CAPACITY 1
// ����ʱ�����ٸ�Ԫ�صĿռ�
#define EXPAND 1

typedef struct{
	ElemType* elem;	// ���Ԫ��
	int length;		// ��¼˳�����(Ԫ�ظ���)
	int capacity;	// ��¼˳�������
}SqList;

// #define SqList(type) typedef type ElemType;SqList

// ��ʼ��˳���
Status InitList_Sq(SqList* L);
// ����˳���
void DestroyList_Sq(SqList* L);
// ���˳���
void ClearList_Sq(SqList* L);
// ���˳�����(Ԫ�ظ���)
int GetLength_Sq(SqList* L);
// �ж�˳����Ƿ�Ϊ��
int isEmpty_Sq(SqList* L);
// ��ȡ˳����е� i ������Ԫ�ص�����
int GetElem_Sq(SqList* L,int i, ElemType* e);
// ��˳����в���ĳһ������(���Զ������͵�)����ֵ��Ԫ��(���Զ������͵�)��������λ����ţ�����Ҳ�������0
int LocateElem_Sq(SqList* L, const ElemType e);
// ��˳���� i ��λ�ò���Ԫ��
Status ListInsert_Sq(SqList* L, int i, const ElemType e);
// ɾ��˳���ĵ� i ��Ԫ��
Status ListDelete_Sq(SqList* L, int i);


#endif