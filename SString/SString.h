#pragma once
//- - - - 串的定长顺序存储结构 - - - -
#define MAXLEN 255 //串的最大长度
typedef struct {
	char ch[MAXLEN + 1]; //存储串的一维数组
	int length; //串的当前长度
}SString;

//- - - - 串的堆式顺序存储结构 - - - -
typedef struct {
	char* ch;	//若是非空串，则按串长分配存储区，否则ch为NULL
	int length;	//串的当前长度
}HString;

//- - - - 串的链式存储结构 - - - -
#define CHUNKSIZE 80	//可由用户自定义的块大小
typedef struct Chunk {
	char ch[CHUNKSIZE];
	struct Chunk* next;
}Chunk;
typedef struct {
	Chunk* head, * tail;	//串的头和尾指针
	int length;	//串的当前长度
}LString;

int Index_BF(SString S, SString T, int pos);
