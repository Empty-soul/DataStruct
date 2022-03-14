#include"SqStack.h"
#include<iostream>
using namespace std;

char EvaluateExpression() {//算术表达式求值的运算符有限算法，设OPTR和OPND分别为运算符栈和操作数栈
	SqStack OPND,OPTR;
	InitSqStack(&OPND);//初始化OPND栈
	InitSqStack(&OPTR);//初始化OPTR栈
	Push(&OPTR, '#');//将表达式起始符'#'压入OPTR栈
	char ch;
	cin >> ch;
	while (ch != '#' || GetTop(&OPTR) != '#')//表达式没有扫描完毕或OPTR的栈顶元素不为'#'
	{
		if (!In(ch)) {
			Push(&OPND, ch);
			cin >> ch;
		}
		else
		{
			switch (Orecede(GetTop(OPTR, ch))) {
			case'<':Push(&OPTR, ch);//当前字符ch压入OPTR栈，读入下一
			}
		}
	}

}

int main() {
	
	
	return 0;
}