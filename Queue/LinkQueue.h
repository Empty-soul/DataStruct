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
	QNode *front;//��ͷָ��
	QNode *rear;//��βָ��
}LinkQueue;

Status InitQueue(LinkQueue *lq);//����һ��ֻ��һ��ͷ���Ŀն�
Status EnQueue(LinkQueue *lq, ElemType e);//��Ԫ��e�����β
Status DeQueue(LinkQueue *lq, ElemType *e);//���ӣ�e��������
ElemType GetHead(LinkQueue const *lq);//���ض�ͷԪ�ص�ֵ