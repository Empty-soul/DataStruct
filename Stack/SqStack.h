#pragma once
#include<stdlib.h>
#define MAXSIZE 100
#define OK 0
#define ERROR 1
typedef int ElemTpye;
typedef int Status;

typedef struct {
	ElemTpye *base;//栈底指针
	ElemTpye *top;//栈顶指针
	int stack_size;//栈可用的最大容量
}SqStack;

void InitSqStack(SqStack *s);//初始化栈
Status Push(SqStack *s,ElemTpye e);//在栈顶插入一个新的元素
Status Pop(SqStack *s,ElemTpye *e);//出栈，用e接收栈顶元素
ElemTpye GetTop(SqStack const* s);//返回栈顶元素
void DecToOct(int dec);//十进制转八进制输出
Status Matching(const char *str);//括号字符串匹配，若无问题返回0，否则返回1
int In(char ch);
char Orecede(char a, char b);
ElemTpye Oreate(ElemTpye a, ElemTpye theta, ElemTpye b);
char EvaluateExpression();
int IsPlaindrome(char str[], int num);

int SqStackEmpty(SqStack const* sq);//若栈空，则返回1，否则返回0
int SqStackFull(SqStack const* sq);//若栈满，则返回1，否则返回0
void IOByStack();//从键盘读入一整数序列，当为-1时，出栈；当不为-1时，入栈