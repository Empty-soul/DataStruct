#include"SqStack.h"
#include<iostream>
using namespace std;

int In(char ch) {

	int flag = 0;

	if (ch < '0' || ch > '9') {
		flag = 1;
	}

	return flag;
}

char Orecede(char a, char b) {
	char result=0;

	switch (a)
	{
	case '+':
		switch (b) {
		case'+': result = '>'; break;
		case'-': result = '>'; break;
		case'*': result = '<'; break;
		case'/': result = '<'; break;
		case'(': result = '<'; break;
		case')': result = '>'; break;
		case'#': result = '>'; break;
		}
		break;
	case '-':
		switch (b) {
		case'+': result = '>'; break;
		case'-': result = '>'; break;
		case'*': result = '<'; break;
		case'/': result = '<'; break;
		case'(': result = '<'; break;
		case')': result = '>'; break;
		case'#': result = '>'; break;
		}
		break;
	case '*':
		switch (b) {
		case'+': result = '>'; break;
		case'-': result = '>'; break;
		case'*': result = '>'; break;
		case'/': result = '>'; break;
		case'(': result = '<'; break;
		case')': result = '>'; break;
		case'#': result = '>'; break;
		}
		break;
	case '/':
		switch (b) {
		case'+': result = '>'; 	break;
		case'-': result = '>';	break;
		case'*': result = '>';	break;
		case'/': result = '>';	break;
		case'(': result = '<';	break;
		case')': result = '>';	break;
		case'#': result = '>';	break;
		}
		break;
	case '(':
		switch (b) {
		case'+': result = '<'; 	break;
		case'-': result = '<';	break;
		case'*': result = '<';	break;
		case'/': result = '<';	break;
		case'(': result = '<';	break;
		case')': result = '=';	break;
		case'#': result = ' ';	break;
		}
		break;
	case ')':
		switch (b) {
		case'+': result = '>';	break;
		case'-': result = '>';	break;
		case'*': result = '>';	break;
		case'/': result = '>';	break;
		case'(': result = ' ';	break;
		case')': result = '>';	break;
		case'#': result = '>';	break;
		}
		break;
	case'#':
		switch (b) {
		case'+': result = '<';	break;
		case'-': result = '<';	break;
		case'*': result = '<';	break;
		case'/': result = '<';	break;
		case'(': result = '<';	break;
		case')': result = ' ';	break;
		case'#': result = '=';	break;
		}
		break;
	}

	return result;
}


ElemTpye Oreate(ElemTpye a, ElemTpye theta, ElemTpye b) {
	ElemTpye result=0;
	switch (theta)
	{
	case '+':result = a + b; break;
	case '-':result = a - b; break;
	case '*':result = a * b; break;
	case '/':result = a / b; break;

	}
	return result;
}
char EvaluateExpression() {//算术表达式求值的运算符有限算法，设OPTR和OPND分别为运算符栈和操作数栈
	SqStack OPND,OPTR;
	InitSqStack(&OPND);//初始化OPND栈
	InitSqStack(&OPTR);//初始化OPTR栈
	Push(&OPTR, '#');//将表达式起始符'#'压入OPTR栈
	char ch;
	ElemTpye theta,a,b,x;
	cin >> ch;
	while (ch != '#' || GetTop(&OPTR) != '#')//表达式没有扫描完毕或OPTR的栈顶元素不为'#'
	{
		if (!In(ch)) {
			Push(&OPND, ch-48);
			cin >> ch;
		}//ch不是运算符则进OPND栈
		else
		{
			switch (Orecede(GetTop(&OPTR), ch)) {
			case'<':Push(&OPTR, ch); cin >> ch;//当前字符ch压入OPTR栈，读入下一字符ch
				break;
			case '>':Pop(&OPTR, &theta);//弹出OPTR栈顶的运算符
				Pop(&OPND, &b); Pop(&OPND, &a);//弹出OPND栈顶的两个运算数
				Push(&OPND, Oreate(a, theta, b));//将运算结过压入OPND栈
				
				break;
			case '='://OPTR的栈顶元素是"("且ch是")"
				Pop(&OPTR, &x); cin >> ch;//弹出OPTR栈顶的"("，读入下一字符ch
				break;
			}
		}
	}
	return GetTop(&OPND);//OPND栈顶元素即为表达式求值结果
}

int main() {
	int result = EvaluateExpression();
	cout << result << endl;
	return 0;
}