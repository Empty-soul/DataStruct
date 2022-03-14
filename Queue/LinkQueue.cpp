#include "LinkQueue.h"

Status InitQueue(LinkQueue * lq)
{
	QNode *p = (QNode*)malloc(sizeof(QNode));
	p->next = NULL;
	lq->front = lq->rear = p;
	return OK;
}

Status EnQueue(LinkQueue * lq, ElemType e)
{
	QNode *p = (QNode*)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	lq->rear->next=p;
	lq->rear = p;
	return OK;
}

Status DeQueue(LinkQueue * lq, ElemType *e)
{
	if (lq->front == lq->rear) return ERROR;
	QNode *temp = lq->front->next;
	*e = temp->data;
	lq->front->next = temp->next;
	if (lq->rear==temp) lq->rear = lq->front;
	free(temp);
	return OK;
}

ElemType GetHead(LinkQueue const * lq)
{
	if(lq->front!=lq->rear)
	return lq->front->next->data;
}
