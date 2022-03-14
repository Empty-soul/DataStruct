#include "LinkList.h"
#include<iostream>
using namespace std;
Status InitLinkList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	return OK;
}

Status GetElem(LinkList L, int i, ElemType * e)
{
	LNode * t = L->next;
	for (int j = 1; j < i; j++)
	{
		if (!t) return ERROR;
		t = t->next;
	}
	if (!t) return ERROR;
	*e = t->data;
	return OK;
}

LNode * LocateElem(const LinkList L, ElemType e)
{
	LNode *t = L->next;
	while (t&&t->data!=e) {
		t = t->next;
	}
	return t;
}

Status ListInsert(LinkList L, int i, ElemType e)
{
	LNode *p = L; 
	int j = 0;
	while (p&&j<i-1)
	{
		p = p->next;
		j++;

	}
	if (!p) return ERROR;
	LNode *t = (LNode*)malloc(sizeof(LNode));
	t->data = e;
	t->next = p->next;
	p->next = t;

	return OK;
}

Status ListDelete(LinkList L, int i)
{
	LNode *p = L; int j = 0;
	while (p->next&&j < i - 1) {
		p = p->next;
		j++;
	}
	if ( !p->next) return ERROR;
	LNode *t = p->next;
	p->next = p->next->next;
	free(t);
	return OK;
}

void CreateList_H(LinkList *L, int n)
{
	InitLinkList(L);
	
	for (int i = 0; i < n; i++)
	{
		
		LNode *t = (LNode *)malloc(sizeof(LNode));
		cin >> t->data;
		t->next = (*L)->next;
		(*L)->next = t;

	/*	ElemType e;
		cin >> e;
		ListInsert(L, 1, e);*/
	}
}

void CreateList_R(LinkList *L, int n)
{
	*L = (LNode*)malloc(sizeof(LNode));
	(*L)->next = NULL;
	LNode *tail = *L;
	for (int i = 0; i < n; i++)
	{
		LNode *p = (LNode *)malloc(sizeof(LNode));
		cin >> p->data;
		tail->next = p;
		p->next = NULL;
		tail = p;
	}
}

void Combine_incremental(LinkList LA, LinkList LB) {
	LNode *pa = LA->next;
	LNode *pb = LB->next;
	LNode *pc = LA;
	while (pa && pb) {
		if (pa->data < pb->data) {
			pa = pa->next;
			pc = pc->next;
		}
		else if (pa->data == pb->data) {
			pa = pa->next;
			pb = pb->next;
			pc = pc->next;
		}
		else {
			pc->next = pb;
			pb = pb->next;
			pc = pc->next;
		}
	}if (!pb) {
		pc->next = pa;
	}
	else
	{
		pc->next = pb;
	}
}

void Combine_nondecreasing(LinkList LA, LinkList LB) {
	LNode *pa = LA->next;
	LNode *pb = LB->next;
	LNode *pc = LA;
	while (pa&&pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;
			pa = pa->next;
			pc = pc->next;
		}
		else {
			pc->next = pb;
			pb = pb->next;
			pc = pc->next;
		}
	}
	if (!pa) {
		pc->next = pb;
	}
	else {
		pc->next = pa;
	}
}

void ListIntersection(LinkList LA, LinkList LB) {
	LNode* pa = LA->next;
	LNode* pb = LB->next;
	LNode* pc = LA;
	while (pa) {
		pb = LB->next;
		while (pb) {
			if (pa->data == pb->data) {
				pc->next = pa;
				pc = pc->next;
				break;
			}
			else {
				pb = pb->next;
			}
		}
		LNode *pt = pa;
		pa = pa->next;

		if (!pb) {
			pc->next = pa;
			free(pt);
		}

	}
}

int ListDifSet(LinkList LA, LinkList LB) {
	LNode *pa = LA->next;
	LNode *pb = LB->next;
	LNode *pc = LA;
	int count = 0;
	while (pa) {
		pb = LB->next;
		while (pb) {

			if (pa->data == pb->data) {
				break;
			}
			else {
				pb = pb->next;
			}
		}

		LNode *pt = pa;
		pa = pa->next;
		if (pb) {
			pc->next = pa;
			free(pt);
		}
		else count++;
	}
	return count;
}

void ListDempose(LinkList LA, LinkList LB, LinkList LC) {
	LNode* pa = LA->next;
	LNode* pb = LB;
	LNode* pc = LC;

	while (pa) {
		if (pa->data < 0) {
			pb->next = pa;
			pb = pb->next;
		}
		else {
			pc->next = pa;
			pc = pc->next;
		}
		pa = pa->next;
	}
	pb->next = NULL;
	pc->next = NULL;

}

LNode MaxNode(LinkList L) {
	LNode* p = L->next;
	LNode* pn = (LNode*)malloc(sizeof(LNode));
	pn = p;
	while (p) {
		if (p->data > pn->data) pn = p;
		p = p->next;
	}
	return *pn;
}

LNode* ReverseList(LinkList *L) {
	LNode* i = *L;
	LNode* j = (*L)->next;
	LNode* k = j->next;

	while (k) {
		j->next = i;
		i = j;
		j = k;
		k = k->next;
	}
	j->next = i;
	(*L)->next = NULL;
	LinkList LR = (LNode*)malloc(sizeof(LNode));
	LR->next = j;
	return LR;
}

void DeleteBetweenTwo(LinkList L, ElemType mink, ElemType maxk) {
	LNode* p = L->next;
	LNode* pl = L;
	while (p) {
		if (p->data > mink&&p->data < maxk) {
			LNode* pt = p;
			p = p->next;
			pl->next = p;
			free(pt);
		}
		else {
			p = p->next;
			pl = pl->next;
		}
	}
}

void TraverseList(LinkList L)
{
	LNode *p = L->next;
	if (p != NULL) {

		cout << p->data << endl;
		TraverseList(p->next);
	}
}

void ListPrint(LinkList L) {
	LNode* p = L->next;
	while (p) {
		cout << p->data << '\t';
		p = p->next;
	}
	cout << endl;
}
