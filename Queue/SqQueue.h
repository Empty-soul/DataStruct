#pragma once
#define MAXSIZE 100
#include<stdlib.h>
#define OK 0
#define ERROR 1
typedef int ElemType;
typedef int Status;

typedef struct {
	ElemType *base;//存储空间的基地址
	int front;//头指针
	int rear;//尾指针
}SqQueue;//非空队列中，头指针始终指向队列头元素，而尾指针始终指向队列尾元素的下一位置

Status InitQueue(SqQueue *sq);//分配一个预定义大小为MAXSIZE的数组空间
int QueueLength(SqQueue sq);//求循环队列长度
Status EnQueue(SqQueue *sq, ElemType e);//在队尾插入一个新的元素e
Status DeQueue(SqQueue *sq, ElemType *e);//将队头元素删除
ElemType GetHead(SqQueue sq);//取队头元素
