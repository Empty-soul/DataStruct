#include "DoubleStack.h"

Status InitDblStack(DblStack* dbs)
{
	dbs->V = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	if (!dbs->V) return ERROR;
	dbs->m = MAXSIZE / 2;
	dbs->top[0] = dbs->bot[0] = -1;
	dbs->top[1] = dbs->bot[1] = dbs->m;

	return OK;
}

int DblStackEmpty(DblStack dbs)
{
	int flag = 0;
	if (dbs.top[0] == dbs.V[-1] && dbs.top[1] == dbs.V[dbs.m]) flag = 1;
	return flag;
}

int DblStackFull(DblStack const *dbs)
{
	int flag = 0;
	if (dbs->top[0] + 1 == dbs->top[1] && dbs->top[1] == -1 || dbs->top[0] == dbs->m) flag = 1;
	if (dbs->top[0] + 1 == dbs->top[1] && dbs->top[1] != -1 && dbs->top[0] != dbs->m) flag = 1;
	return flag;
}

Status InsertDblStack(DblStack* dbs, ElemType e)
{
	if (DblStackFull(dbs)) return ERROR;
	int i = rand() % 2;
	if (i) dbs->V[++(dbs->top[0])] = e;
	else dbs->V[--(dbs->top[1])] = e;
	return OK;
}
