#include"SqQueue.h"

Status InitQueue(SqQueue *sq) {
	sq->base = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
	if (sq->base == NULL) return ERROR;
	sq->front = sq->rear = 0;
	return OK;
}

int QueueLength(SqQueue sq)
{
	return (sq.rear+MAXSIZE-sq.front)%MAXSIZE;
}

Status EnQueue(SqQueue * sq, ElemType e)
{
	if ((sq->rear + 1) % MAXSIZE == sq->front) return ERROR;
	//*(sq->base + sq->rear) = e;
	sq->base[sq->rear] = e;
	sq->rear = (sq->rear + 1) % MAXSIZE;
	return OK;
}

Status DeQueue(SqQueue * sq, ElemType * e)
{
	if (sq->front == sq->rear) return ERROR;
	*e = sq->base[sq->front];
	sq->front = (sq->front + 1) % MAXSIZE;
	return OK;
}

ElemType GetHead(SqQueue sq)
{
	if(sq.front!=sq.rear)
	return sq.base[sq.front];
}
