#ifndef __CSQLIST_H__
#define __CSQLIST_H__

// 头文件
#include<stdio.h>
#include<stdlib.h>

// 函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

// Status 是函数的类型
typedef int Status;
typedef int ElemType;

// 初始化时有容纳多少个元素的空间容量
#define CAPACITY 1
// 扩容时扩多少个元素的空间
#define EXPAND 1

typedef struct{
	ElemType* elem;	// 存放元素
	int length;		// 记录顺序表长度(元素个数)
	int capacity;	// 记录顺序表容量
}SqList;

// #define SqList(type) typedef type ElemType;SqList

// 初始化顺序表
Status InitList_Sq(SqList* L);
// 销毁顺序表
void DestroyList_Sq(SqList* L);
// 清空顺序表
void ClearList_Sq(SqList* L);
// 获得顺序表长度(元素个数)
int GetLength_Sq(SqList* L);
// 判断顺序表是否为空
int isEmpty_Sq(SqList* L);
// 获取顺序表中第 i 个数据元素的内容
int GetElem_Sq(SqList* L,int i, ElemType* e);
// 在顺序表中查找某一个等于(非自定义类型的)给定值的元素(非自定义类型的)并返回其位置序号，如果找不到返回0
int LocateElem_Sq(SqList* L, const ElemType e);
// 在顺序表第 i 个位置插入元素
Status ListInsert_Sq(SqList* L, int i, const ElemType e);
// 删除顺序表的第 i 个元素
Status ListDelete_Sq(SqList* L, int i);


#endif