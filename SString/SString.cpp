#include"SString.h"

int Index_BF(SString S, SString T, int pos)
{//返回模式T在主串S中第pos个字符开始第一次出现的位置。若不存在，则返回值为0
	//其中，T非空，1<=pos<=S.length
	int i = pos; int j = 1;	//初始化
	while (i <= S.length && j <= T.length)//两个串均未比较串尾
	{
		if (S.ch[i] == T.ch[j]) { ++i; ++j; }	//继续比较后继字符
		else { i = i - j + 2; j = 1; }	//指针后退重新开始匹配
	}
	if (j > T.length) return i - T.length;//匹配成功
	else return 0;	//匹配失败
}
