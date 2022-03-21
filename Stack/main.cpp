#include"SqStack.h"
#include<iostream>
using namespace std;

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
	ElemTpye e,num;
	SqStack sq;
	InitSqStack(&sq);
	while (1) {
		cin >> num;
		if (SqStackEmpty(&sq) && num == -1) {
			cout << "There isn't any number." << endl;
		}
		else if (SqStackFull(&sq) && num != -1) {
			cout << "It can't contain more number." << endl;
		}
		else if (num == -1) {
			Pop(&sq, &e);
		}
		else if (num != -1) {
			Push(&sq, num);
		}
	}
}



int main() {
	IOByStack();
	
	return 0;
}