#pragma once
#include<stdlib.h>
#define MAXSIZE 100
#define OK 0
#define ERROR 1
typedef int ElemTpye;
typedef int Status;

typedef struct {
	ElemTpye *base;//ջ��ָ��
	ElemTpye *top;//ջ��ָ��
	int stack_size;//ջ���õ��������
}SqStack;

void InitSqStack(SqStack *s);//��ʼ��ջ
Status Push(SqStack *s,ElemTpye e);//��ջ������һ���µ�Ԫ��
Status Pop(SqStack *s,ElemTpye *e);//��ջ����e����ջ��Ԫ��
ElemTpye GetTop(SqStack const* s);//����ջ��Ԫ��
void DecToOct(int dec);//ʮ����ת�˽������
Status Matching(const char *str);//�����ַ���ƥ�䣬�������ⷵ��0�����򷵻�1