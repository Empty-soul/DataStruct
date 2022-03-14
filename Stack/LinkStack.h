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

Status InitStack(LinkStack *s);//初始化链栈
Status Push(LinkStack *s, ElemType e);//链栈入栈
Status Pop(LinkStack *s, ElemType *e);//链栈出栈
ElemType GetTop(LinkStack s);//取栈顶元素

