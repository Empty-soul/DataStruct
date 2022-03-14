#pragma once
#include<stdlib.h>
#define OK 0
#define ERROR 1
typedef int Status;
typedef int ElemType;
typedef struct StackNode{
	ElemType data;
	struct StackNode *next;

}StackNode,*LinkStack;

Status InitStack(LinkStack *s);//��ʼ����ջ
Status Push(LinkStack *s, ElemType e);//��ջ��ջ
Status Pop(LinkStack *s, ElemType *e);//��ջ��ջ
ElemType GetTop(LinkStack s);//ȡջ��Ԫ��

