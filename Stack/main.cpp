#include"SqStack.h"
#include<iostream>
using namespace std;

char EvaluateExpression() {//�������ʽ��ֵ������������㷨����OPTR��OPND�ֱ�Ϊ�����ջ�Ͳ�����ջ
	SqStack OPND,OPTR;
	InitSqStack(&OPND);//��ʼ��OPNDջ
	InitSqStack(&OPTR);//��ʼ��OPTRջ
	Push(&OPTR, '#');//�����ʽ��ʼ��'#'ѹ��OPTRջ
	char ch;
	cin >> ch;
	while (ch != '#' || GetTop(&OPTR) != '#')//���ʽû��ɨ����ϻ�OPTR��ջ��Ԫ�ز�Ϊ'#'
	{
		if (!In(ch)) {
			Push(&OPND, ch);
			cin >> ch;
		}
		else
		{
			switch (Orecede(GetTop(OPTR, ch))) {
			case'<':Push(&OPTR, ch);//��ǰ�ַ�chѹ��OPTRջ��������һ
			}
		}
	}

}

int main() {
	
	
	return 0;
}