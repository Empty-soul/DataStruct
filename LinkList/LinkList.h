#pragma once
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 100
typedef int Status;
typedef  int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

Status InitLinkList(LinkList* L);//����յĵ�����L
Status GetElem(const LinkList L, int i,ElemType *e);//ȡ�õ�����λ��Ϊi������Ԫ��
LNode* LocateElem(const LinkList L, ElemType e);//���ҵ�����L������Ԫ�أ�������������ָ��
Status ListInsert(LinkList L,int i, ElemType e);//�ڴ�ͷ���ĵ�����L�е�i��λ�ò���ֵΪe���½��
Status ListDelete(LinkList L, int i);//�ڴ�ͷ���ĵ�����L�У�ɾ����i��Ԫ��
void CreateList_H(LinkList *L, int n);//��λ������n��Ԫ�ص�ֵ��������ͷ���ĵ�����
void CreateList_R(LinkList *L, int n);//��λ������n��Ԫ�ص�ֵ��������ͷ���ĵ�����
void Combine_incremental(LinkList LA, LinkList LB);//��������������������ϲ�Ϊһ����������������
void Combine_nondecreasing(LinkList LA, LinkList LB);//�������ǵݼ�����������ϲ�Ϊһ���ǵݼ�����������
void ListIntersection(LinkList LA, LinkList LB);//������Ԫ�ص���������ȡ���������LA��
int ListDifSet(LinkList LA, LinkList LB);//����LA=LA-LB������LA��Ԫ�ظ���
void ListDempose(LinkList LA, LinkList LB, LinkList LC);//����ͷ���ĵ�����A�ֽ�Ϊ������ͬ�ṹ��B��C��B�н��<0��C�н��>0
LNode MaxNode(LinkList L);//����L�е�����㣨����ָ��δ�ͷţ�
LNode* ReverseList(LinkList *L);//������Ҫ��ת������ӷ��������L��������ת�������ͷ���ָ�룬������+1������һ��β��㣩
void DeleteBetweenTwo(LinkList L, ElemType mink, ElemType maxk);//ɾ���������н���mink��maxk�Ľ��
void TraverseList(LinkList L);//������������и������ĵݹ��㷨
void ListPrint(LinkList L);//˳���������