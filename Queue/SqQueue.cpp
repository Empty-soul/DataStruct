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

void DancePartner(ElemType dancer[], int num) {//�ṹ����dancer�д���������Ů��numʱ���������
	SqQueue Mdancers;//��ʿ
	SqQueue Fdancers;//Ůʿ

	InitQueue(&Mdancers);//��ʿ���г�ʼ��
	InitQueue(&Fdancers);//Ůʿ���г�ʼ��
	ElemType p;
	for (int i = 0; i < num; i++)
	{
		p = dancer[i];
		if (p.sex == 'F') EnQueue(&Fdancers, p);//����Ů��
		else EnQueue(&Mdancers, p);//�����ж�

	}
	cout << "The dancing parners are:\n";
	while (!QueueEmpty(Fdancers) && !QueueEmpty(Mdancers)) {//���������Ů��������
		DeQueue(&Mdancers, &p);//��ʿ����
		cout << p.name << " ";//���������ʿ����
		DeQueue(&Fdancers, &p);//Ůʿ����
		cout << p.name << endl;//�������Ůʿ����
	}
	if (!QueueEmpty(Fdancers))//Ůʿ���зǿգ������ͷŮʿ������
	{
		p = GetHead(Fdancers);//ȡŮʿ��ͷ
		cout << "The first woman to get a partner is: " << p.name << endl;
	}
	else if (!QueueEmpty(Mdancers))//Ůʿ���зǿգ������ͷŮʿ������
	{
		p = GetHead(Mdancers);//ȡŮʿ��ͷ
		cout << "The first man to get a partner is: " << p.name << endl;
	}
}

#endif // PERSON
