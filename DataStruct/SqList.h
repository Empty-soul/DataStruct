#pragma once
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAXSIZE 100
typedef int ElemType;
typedef int Status;
typedef struct {
	ElemType *elem;	//存储空间基地址
	int length;		//当前长度
}SqList;			//顺序表的结构类型为SqList

Status InitSqList(SqList *l);//初始化顺序表，当前长度为0
Status GetElem(const SqList *l, int i, ElemType *e);//获取指定位置i处的元素
int LocateElem(const SqList *l, ElemType e);//根据指定元素值e，查找顺序表中第一个与e相等的元素。返回序号，失败返回0
Status InsertElem(SqList *l, int i, ElemType e);//在指定位置i插入新元素e
Status DeleteElem(SqList *l, int i);//删除指定位置i的元素
void MergeList(SqList *la, const SqList *lb);//将所有在线性表lb中但不在la中的数据元素插入到la中