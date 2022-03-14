#include"SqQueue.h"

Status InitQueue(SqQueue *sq) {
	sq->base = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
	if (sq->base == NULL) return ERROR;
	sq->front = sq->rear = 0;
	return OK;
}

int QueueLength(SqQueue sq)
{
	return (sq.rear+MAXSIZE-sq.front)%MAXSIZE;
}

Status EnQueue(SqQueue * sq, ElemType e)
{
	if ((sq->rear + 1) % MAXSIZE == sq->front) return ERROR;
	//*(sq->base + sq->rear) = e;
	sq->base[sq->rear] = e;
	sq->rear = (sq->rear + 1) % MAXSIZE;
	return OK;
}

Status DeQueue(SqQueue * sq, ElemType * e)
{
	if (sq->front == sq->rear) return ERROR;
	*e = sq->base[sq->front];
	sq->front = (sq->front + 1) % MAXSIZE;
	return OK;
}

ElemType GetHead(SqQueue sq)
{
	if(sq.front!=sq.rear)
	return sq.base[sq.front];
}

int QueueEmpty(SqQueue sq) {
	int flag = 1;
	if (sq.front != sq.rear) flag = 0;
	return flag;
}

#ifdef PERSON
ElemType* LoadDancers(int* num) {
	*num = 0;
	ElemType* dancers = (Person*)malloc(sizeof(ElemType) * MAXSIZE);
	while (cin >> dancers[i].name >> dancers[i].sex)
	{
		*num++;
	}
	return dancers;
}

void DancePartner(ElemType dancer[], int num) {//结构数组dancer中存放跳舞的男女，num时跳舞的人数
	SqQueue Mdancers;//男士
	SqQueue Fdancers;//女士

	InitQueue(&Mdancers);//男士队列初始化
	InitQueue(&Fdancers);//女士队列初始化
	ElemType p;
	for (int i = 0; i < num; i++)
	{
		p = dancer[i];
		if (p.sex == 'F') EnQueue(&Fdancers, p);//插入女队
		else EnQueue(&Mdancers, p);//插入男队

	}
	cout << "The dancing parners are:\n";
	while (!QueueEmpty(Fdancers) && !QueueEmpty(Mdancers)) {//依次输出男女舞伴的姓名
		DeQueue(&Mdancers, &p);//男士出队
		cout << p.name << " ";//输出出队男士姓名
		DeQueue(&Fdancers, &p);//女士出队
		cout << p.name << endl;//输出出队女士姓名
	}
	if (!QueueEmpty(Fdancers))//女士队列非空，输出队头女士的姓名
	{
		p = GetHead(Fdancers);//取女士队头
		cout << "The first woman to get a partner is: " << p.name << endl;
	}
	else if (!QueueEmpty(Mdancers))//女士队列非空，输出队头女士的姓名
	{
		p = GetHead(Mdancers);//取女士队头
		cout << "The first man to get a partner is: " << p.name << endl;
	}
}

#endif // PERSON
