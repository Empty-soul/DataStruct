#pragma once
typedef int TElemType;
//- - - -��������˳��洢��ʾ- - - - 
#define MAXSIZE 100 //���������������
typedef TElemType SqBiTree[MAXSIZE];//0�ŵ�Ԫ�洢�����

//- - - -�������Ķ�������洢��ʾ- - - - 
typedef struct BiNode {
	TElemType data;//���������
	struct BiNode* lchild, * rchild;//���Һ���ָ��
}BiTNode,*BiTree;

void InOrderTraverse(BiTree T);//�������������T�ĵݹ��㷨