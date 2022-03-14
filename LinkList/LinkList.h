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

Status InitLinkList(LinkList* L);//构造空的单链表L
Status GetElem(const LinkList L, int i,ElemType *e);//取得单链表位置为i的数据元素
LNode* LocateElem(const LinkList L, ElemType e);//查找单链表L中数据元素，返回所处结点的指针
Status ListInsert(LinkList L,int i, ElemType e);//在带头结点的单链表L中第i个位置插入值为e的新结点
Status ListDelete(LinkList L, int i);//在带头结点的单链表L中，删除第i个元素
void CreateList_H(LinkList *L, int n);//逆位序输入n个元素的值，建立带头结点的单链表
void CreateList_R(LinkList *L, int n);//正位序输入n个元素的值，建立带头结点的单链表
void Combine_incremental(LinkList LA, LinkList LB);//将两个递增的有序链表合并为一个递增的有序链表
void Combine_nondecreasing(LinkList LA, LinkList LB);//将两个非递减的有序链表合并为一个非递减的有序链表
void ListIntersection(LinkList LA, LinkList LB);//将两个元素递增的链表取交集存放在LA中
int ListDifSet(LinkList LA, LinkList LB);//集合LA=LA-LB，返回LA的元素个数
void ListDempose(LinkList LA, LinkList LB, LinkList LC);//将带头结点的单链表A分解为具有相同结构的B和C，B中结点<0，C中结点>0
LNode MaxNode(LinkList L);//返回L中的最大结点（存在指针未释放）
LNode* ReverseList(LinkList *L);//接受需要逆转结点链接方向的链表L，返回逆转后的链表头结点指针，链表长度+1（存在一个尾结点）
void DeleteBetweenTwo(LinkList L, ElemType mink, ElemType maxk);//删除单链表中介于mink与maxk的结点
void TraverseList(LinkList L);//遍历输出链表中各个结点的递归算法
void ListPrint(LinkList L);//顺序遍历链表