#pragma once
typedef int TElemType;
//- - - -二叉树的顺序存储表示- - - - 
#define MAXSIZE 100 //二叉树的最大结点数
typedef TElemType SqBiTree[MAXSIZE];//0号单元存储根结点

//- - - -二叉树的二叉链表存储表示- - - - 
typedef struct BiNode {
	TElemType data;//结点数据域
	struct BiNode* lchild, * rchild;//左右孩子指针
}BiTNode,*BiTree;

void InOrderTraverse(BiTree T);//中序便利二叉树T的递归算法