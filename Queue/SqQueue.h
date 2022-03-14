#pragma once
#define MAXSIZE 100
#include<stdlib.h>
#define OK 0
#define ERROR 1
#ifdef PERSON
	typedef struct {
		char name[20];//姓名
		char sex;//性别，'F'表示女性，'M'表示男性
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
		ElemType* base;//存储空间的基地址
		int front;//头指针
		int rear;//尾指针
	}SqQueue;//非空队列中，头指针始终指向队列头元素，而尾指针始终指向队列尾元素的下一位置
#endif // !PERSON







Status InitQueue(SqQueue *sq);//分配一个预定义大小为MAXSIZE的数组空间
int QueueLength(SqQueue sq);//求循环队列长度
Status EnQueue(SqQueue *sq, ElemType e);//在队尾插入一个新的元素e
Status DeQueue(SqQueue *sq, ElemType *e);//将队头元素删除
ElemType GetHead(SqQueue sq);//取队头元素
int QueueEmpty(SqQueue sq);//若队列空，则返回1，否则返回0
void DancePartner(ElemType dancer[], int num);//结构数组dancer中存放跳舞的男女，num时跳舞的人数
ElemType* LoadDancers(int* num);//读入人，包括姓名、性别，num接受结构数组长度，返回数组指针
