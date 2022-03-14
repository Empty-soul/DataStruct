#pragma once
#define MAXSIZE 100
#include<stdlib.h>
#define OK 0
#define ERROR 1
typedef int ElemType;
typedef int Status;

typedef struct {
	ElemType *base;//�洢�ռ�Ļ���ַ
	int front;//ͷָ��
	int rear;//βָ��
}SqQueue;//�ǿն����У�ͷָ��ʼ��ָ�����ͷԪ�أ���βָ��ʼ��ָ�����βԪ�ص���һλ��

Status InitQueue(SqQueue *sq);//����һ��Ԥ�����СΪMAXSIZE������ռ�
int QueueLength(SqQueue sq);//��ѭ�����г���
Status EnQueue(SqQueue *sq, ElemType e);//�ڶ�β����һ���µ�Ԫ��e
Status DeQueue(SqQueue *sq, ElemType *e);//����ͷԪ��ɾ��
ElemType GetHead(SqQueue sq);//ȡ��ͷԪ��
