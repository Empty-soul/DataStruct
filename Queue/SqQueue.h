#pragma once
#define MAXSIZE 100
#include<stdlib.h>
#define OK 0
#define ERROR 1
#ifdef PERSON
	typedef struct {
		char name[20];//����
		char sex;//�Ա�'F'��ʾŮ�ԣ�'M'��ʾ����
	}Person;

	typedef Person ElemType;
	typedef int Status;

	typedef  struct {
		Person* base;
		int front;
		int rear;
	}SqQueue;
#else
	typedef int ElemType;
	typedef int Status;

	typedef struct {
		ElemType* base;//�洢�ռ�Ļ���ַ
		int front;//ͷָ��
		int rear;//βָ��
	}SqQueue;//�ǿն����У�ͷָ��ʼ��ָ�����ͷԪ�أ���βָ��ʼ��ָ�����βԪ�ص���һλ��
#endif // !PERSON







Status InitQueue(SqQueue *sq);//����һ��Ԥ�����СΪMAXSIZE������ռ�
int QueueLength(SqQueue sq);//��ѭ�����г���
Status EnQueue(SqQueue *sq, ElemType e);//�ڶ�β����һ���µ�Ԫ��e
Status DeQueue(SqQueue *sq, ElemType *e);//����ͷԪ��ɾ��
ElemType GetHead(SqQueue sq);//ȡ��ͷԪ��
int QueueEmpty(SqQueue sq);//�����пգ��򷵻�1�����򷵻�0
void DancePartner(ElemType dancer[], int num);//�ṹ����dancer�д���������Ů��numʱ���������
ElemType* LoadDancers(int* num);//�����ˣ������������Ա�num���ܽṹ���鳤�ȣ���������ָ��
