#pragma once
//- - - - ���Ķ���˳��洢�ṹ - - - -
#define MAXLEN 255 //������󳤶�
typedef struct {
	char ch[MAXLEN + 1]; //�洢����һά����
	int length; //���ĵ�ǰ����
}SString;

//- - - - ���Ķ�ʽ˳��洢�ṹ - - - -
typedef struct {
	char* ch;	//���Ƿǿմ����򰴴�������洢��������chΪNULL
	int length;	//���ĵ�ǰ����
}HString;

//- - - - ������ʽ�洢�ṹ - - - -
#define CHUNKSIZE 80	//�����û��Զ���Ŀ��С
typedef struct Chunk {
	char ch[CHUNKSIZE];
	struct Chunk* next;
}Chunk;
typedef struct {
	Chunk* head, * tail;	//����ͷ��βָ��
	int length;	//���ĵ�ǰ����
}LString;

int Index_BF(SString S, SString T, int pos);
