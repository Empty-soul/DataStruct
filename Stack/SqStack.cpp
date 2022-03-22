#include "SqStack.h"
#include<iostream>
using namespace std;
void InitSqStack(SqStack * s)
{
	
	s->base = (ElemTpye*)malloc(MAXSIZE * sizeof(ElemTpye));
	s->top = s->base;
	s->stack_size = MAXSIZE;
	
}

Status Push(SqStack * s,ElemTpye e)
{
	if (s->stack_size < 0 || s->top - s->base >= s->stack_size)
		return ERROR;
	*((s->top)++) = e;
	return OK;
}


Status Pop(SqStack * s,ElemTpye *e)
{
	if (s->top == s->base) return ERROR;
	
	*e=*(--s->top);
	return OK;
}

ElemTpye GetTop(SqStack const * s)
{
	if (s->base != s->top) 
	return *(s->top-1);
}

void DecToOct(int dec) {
	SqStack oct;
	InitSqStack(&oct);
	while (dec > 0) {
		Push(&oct, dec % 8);
		dec /= 8;
	}
	int temp;
	while (oct.base != oct.top) {
		Pop(&oct, &temp);
		cout << temp;
	}
	cout << endl;
	free(&oct);
}

Status Matching(const char *str) {
	int length = strlen(str);
	SqStack s;
	InitSqStack(&s);
	int status = 0;
	int temp;
	for (int i = 0; i < length; i++) {
		if (i == 0 && str[i] == '(' || str[i] == '[' || str[i] == '{') Push(&s, str[i]);

		else if (i != 0) {
			switch (str[i])
			{
			case')':if (*(s.top - 1) != '(') status = 1; else Pop(&s, &temp); break;
			case']': if (*(s.top - 1) != '[') status = 1; else Pop(&s, &temp); break;
			case'}': if (*(s.top - 1) != '{') status = 1; else Pop(&s, &temp); break;
			default:
				Push(&s, str[i]);
				break;
			}
		}
		else {
			status = 1;
		}
		if (status == 1) break;


	}
	if (s.base != s.top) status = 1;
	return status;
}

int IsPlaindrome(char str[], int num)
{
	if (num < 2) return 0;
	int flag = 1,half=num/2;
	ElemTpye temp;
	SqStack pd;
	InitSqStack(&pd);
	
	for (int i = 0; i < half; i++) {
		Push(&pd, str[i]);
	}
	if(num%2){
		for (int i = 0; i < half; i++)
		{
			Pop(&pd, &temp);
			if (temp != str[half +1+ i]) {
				flag = 0;
				break;
			}
		}
	}
	else{
		for (int i = 0; i < half; i++)
		{
			Pop(&pd, &temp);
			if (temp != str[half + i]) {
				flag = 0;
				break;
			}
		}
	}
	
	return flag;
}


int In(char ch) {

	int flag = 0;

	if (ch < '0' || ch > '9') {
		flag = 1;
	}

	return flag;
}

char Orecede(char a, char b) {
	char result = 0;

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
	ElemTpye result = 0;
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
	SqStack OPND, OPTR;
	InitSqStack(&OPND);//初始化OPND栈
	InitSqStack(&OPTR);//初始化OPTR栈
	Push(&OPTR, '#');//将表达式起始符'#'压入OPTR栈
	char ch;
	ElemTpye theta, a, b, x;
	cin >> ch;
	while (ch != '#' || GetTop(&OPTR) != '#')//表达式没有扫描完毕或OPTR的栈顶元素不为'#'
	{
		if (!In(ch)) {
			Push(&OPND, ch - 48);
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

int SqStackEmpty(SqStack const* sq) {
	int flag = 1;
	if (sq->base != sq->top) {
		flag = 0;
	}
	return flag;
}

int SqStackFull(SqStack const* sq) {
	int flag = 1;
	if (sq->top - sq->base != sq->stack_size) {
		flag = 0;
	}
	return flag;
}

void IOByStack() {
	ElemTpye e, num = 0;
	SqStack sq;
	InitSqStack(&sq);
	while (1) {
		if (!(cin >> num)) break;
		if (SqStackEmpty(&sq) && num == -1) {
			cout << "There isn't any number." << endl;
		}
		else if (SqStackFull(&sq) && num != -1) {
			cout << "It can't contain more number." << endl;
		}
		else if (num == -1) {
			Pop(&sq, &e);
			cout << "Pop " << e << endl;
		}
		else if (num != -1) {
			Push(&sq, num);
			cout << num << " has been push into stack." << endl;
		}
	}
}