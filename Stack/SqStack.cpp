#include "SqStack.h"
#include<iostream>
using namespace std;
void InitSqStack(SqStack * s)
{
	
	s->base = (ElemTpye*)malloc(MAXSIZE * sizeof(ElemTpye));
	s->top = s->base;
	s->stack_size = MAXSIZE;
	
}

Status Push(SqStack * s,ElemTpye e)
{
	if (s->stack_size < 0 || s->top - s->base >= s->stack_size)
		return ERROR;
	*((s->top)++) = e;
	return OK;
}


Status Pop(SqStack * s,ElemTpye *e)
{
	if (s->top == s->base) return ERROR;
	
	*e=*(--s->top);
	return OK;
}

ElemTpye GetTop(SqStack const * s)
{
	if (s->base != s->top) 
	return *(s->top-1);
}

void DecToOct(int dec) {
	SqStack oct;
	InitSqStack(&oct);
	while (dec > 0) {
		Push(&oct, dec % 8);
		dec /= 8;
	}
	int temp;
	while (oct.base != oct.top) {
		Pop(&oct, &temp);
		cout << temp;
	}
	cout << endl;
	free(&oct);
}

Status Matching(const char *str) {
	int length = strlen(str);
	SqStack s;
	InitSqStack(&s);
	int status = 0;
	int temp;
	for (int i = 0; i < length; i++) {
		if (i == 0 && str[i] == '(' || str[i] == '[' || str[i] == '{') Push(&s, str[i]);

		else if (i != 0) {
			switch (str[i])
			{
			case')':if (*(s.top - 1) != '(') status = 1; else Pop(&s, &temp); break;
			case']': if (*(s.top - 1) != '[') status = 1; else Pop(&s, &temp); break;
			case'}': if (*(s.top - 1) != '{') status = 1; else Pop(&s, &temp); break;
			default:
				Push(&s, str[i]);
				break;
			}
		}
		else {
			status = 1;
		}
		if (status == 1) break;


	}
	if (s.base != s.top) status = 1;
	return status;
}