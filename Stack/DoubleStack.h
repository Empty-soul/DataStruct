#pragma once
#include<stdlib.h>
#define OK 0
#define ERROR 1
#define MAXSIZE 100
typedef int Status;
typedef int ElemType;

typedef struct {
	int top[2], bot[2];//栈顶和栈底指针
	ElemType* V;//栈数组
	int m;//栈最大可容纳元素个数

}DblStack;

Status InitDblStack(DblStack* dbs);
int DblStackEmpty(DblStack dbs);
int DblStackFull(DblStack const *dbs);
Status InsertDblStack(DblStack* dbs,ElemType e);