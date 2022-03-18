#include"SqStack.h"
#include<iostream>
using namespace std;



int main() {
	char str[MAXSIZE] = {};
	int i = 0;
	while (cin >> str[i]) {
		i++;
	}
	
	if (IsPlaindrome(str, i)) cout << "this string is plaindrome." << endl;
	else cout << "this string is't plaindrome." << endl;
	
	return 0;
}