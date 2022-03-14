#include"SqList.h"
#include<iostream>
using namespace std;
int main() {
	SqList l;
	InitSqList(&l);
	for (int i = 0; i < 10; i++)
	{
		InsertElem(&l, 1, i + 1);
	}
	for (int i = 0; i < l.length; i++)
	{
		cout << l.elem[i]<<'\t';
	}
	cout << endl;
	return 0;
}