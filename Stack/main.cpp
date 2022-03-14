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
char EvaluateExpression() {//�������ʽ��ֵ������������㷨����OPTR��OPND�ֱ�Ϊ�����ջ�Ͳ�����ջ
	SqStack OPND,OPTR;
	InitSqStack(&OPND);//��ʼ��OPNDջ
	InitSqStack(&OPTR);//��ʼ��OPTRջ
	Push(&OPTR, '#');//�����ʽ��ʼ��'#'ѹ��OPTRջ
	char ch;
	ElemTpye theta,a,b,x;
	cin >> ch;
	while (ch != '#' || GetTop(&OPTR) != '#')//���ʽû��ɨ����ϻ�OPTR��ջ��Ԫ�ز�Ϊ'#'
	{
		if (!In(ch)) {
			Push(&OPND, ch-48);
			cin >> ch;
		}//ch������������OPNDջ
		else
		{
			switch (Orecede(GetTop(&OPTR), ch)) {
			case'<':Push(&OPTR, ch); cin >> ch;//��ǰ�ַ�chѹ��OPTRջ��������һ�ַ�ch
				break;
			case '>':Pop(&OPTR, &theta);//����OPTRջ���������
				Pop(&OPND, &b); Pop(&OPND, &a);//����OPNDջ��������������
				Push(&OPND, Oreate(a, theta, b));//��������ѹ��OPNDջ
				
				break;
			case '='://OPTR��ջ��Ԫ����"("��ch��")"
				Pop(&OPTR, &x); cin >> ch;//����OPTRջ����"("��������һ�ַ�ch
				break;
			}
		}
	}
	return GetTop(&OPND);//OPNDջ��Ԫ�ؼ�Ϊ���ʽ��ֵ���
}

int main() {
	int result = EvaluateExpression();
	cout << result << endl;
	return 0;
}