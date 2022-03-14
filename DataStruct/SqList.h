#pragma once
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAXSIZE 100
typedef int ElemType;
typedef int Status;
typedef struct {
	ElemType *elem;	//�洢�ռ����ַ
	int length;		//��ǰ����
}SqList;			//˳���Ľṹ����ΪSqList

Status InitSqList(SqList *l);//��ʼ��˳�����ǰ����Ϊ0
Status GetElem(const SqList *l, int i, ElemType *e);//��ȡָ��λ��i����Ԫ��
int LocateElem(const SqList *l, ElemType e);//����ָ��Ԫ��ֵe������˳����е�һ����e��ȵ�Ԫ�ء�������ţ�ʧ�ܷ���0
Status InsertElem(SqList *l, int i, ElemType e);//��ָ��λ��i������Ԫ��e
Status DeleteElem(SqList *l, int i);//ɾ��ָ��λ��i��Ԫ��
void MergeList(SqList *la, const SqList *lb);//�����������Ա�lb�е�����la�е�����Ԫ�ز��뵽la��