#include "SqList.h"

Status InitSqList(SqList * l)
{
	l->elem = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
	if (!l->elem) exit(OVERFLOW);
	l->length = 0;
	return OK;
}

Status GetElem(const SqList * l, int i, ElemType * e)
{
	if (i<1 || i>l->length) return ERROR;//判断i值是否合理，若不合理，返回ERROR
	*e = l->elem[i - 1];
	return OK;
}

int LocateElem(const SqList * l, ElemType e)
{
	for (int i = 0; i < l->length; i++)
	{
		if (l->elem[i] == e) return i + 1;
	}
	return 0;
}

Status InsertElem(SqList * l, int i, ElemType e)
{
	if (i < 1||i>l->length+1||l->length==MAXSIZE) return ERROR;
	for (int j = 0; j <= l->length-i; j++)
	{
		l->elem[l->length - j] = l->elem[l->length - j - 1];

	}
	l->elem[i - 1] = e;
	l->length ++;
	return OK;
}

Status DeleteElem(SqList * l, int i)
{
	if (i<1 || i>l->length) return ERROR;
	for (int j = i-1; j < l->length; j++)
	{
		l->elem[j] = l->elem[j + 1];
	}
	l->length--;
	return OK;
}

void MergeList(SqList * la, SqList * lb)
{
	int m = la->length, n = lb->length;
	for (int i = 0; i < n; i++)
	{
		ElemType e;
		GetElem(lb, i + 1, &e);
		if(!LocateElem(la,e)) InsertElem(la, ++m, e);
	}
	
}


