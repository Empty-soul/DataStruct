#pragma once
#include<stdlib.h>
#define OK 0
#define ERROR 1
#define MAXSIZE 100
typedef int Status;
typedef int ElemType;

typedef struct {
	int top[2], bot[2];//ջ����ջ��ָ��
	ElemType* V;//ջ����
	int m;//ջ��������Ԫ�ظ���

}DblStack;

Status InitDblStack(DblStack* dbs);
int DblStackZEmpty(DblStack dbs);//��ջ0Ϊ���򷵻�true�����򷵻�false
int DblStackFEmpty(DblStack dbs);//��ջ1Ϊ���򷵻�true�����򷵻�false
int DblStackEmpty(DblStack dbs);

int DblStackFull(DblStack const *dbs);
Status InsertDblStack(DblStack* dbs,ElemType e);
