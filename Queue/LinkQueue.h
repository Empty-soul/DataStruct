#pragma once
#include<stdlib.h>
#define OK 0
#define ERROR 1
typedef int ElemType;
typedef int Status;

typedef struct QNode {
	ElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct {
	QNode *front;//队头指针
	QNode *rear;//队尾指针
}LinkQueue;

Status InitQueue(LinkQueue *lq);//构造一个只有一个头结点的空队
Status EnQueue(LinkQueue *lq, ElemType e);//将元素e插入队尾
Status DeQueue(LinkQueue *lq, ElemType *e);//出队，e接受数据
ElemType GetHead(LinkQueue const *lq);//返回队头元素的值