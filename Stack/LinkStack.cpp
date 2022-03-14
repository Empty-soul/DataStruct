#include "LinkStack.h"

Status InitStack(LinkStack * s)
{
	*s = NULL;

	return OK;
}

Status Push(LinkStack * s,ElemType e)
{
	StackNode *p = (StackNode*)malloc(sizeof(StackNode));
	p->data = e;
	p->next = *s;
	*s = p;
	return OK;
}

Status Pop(LinkStack * s, ElemType * e)
{
	if (*s) return ERROR;
	*e = (*s)->data;
	StackNode *p = *s;//临时保存待释放的结点
	(*s) = (*s)->next;
	free(p);
	return OK;
}

ElemType GetTop(LinkStack s)
{
	if(s!=NULL)
	return s->data;
}
