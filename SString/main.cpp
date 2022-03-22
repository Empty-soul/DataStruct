#include "SString.h"
#include<string>

void myStrCat(char* des, const char* source) 
{
	for (int i = 0; i < strlen(source); i++)
	{
		des[i] = source[i];
	}
}

int main() {
	SString s,t;
	const char* sd = "aaaaaba";
	myStrCat(s.ch, sd);
	s.length = strlen(sd);
	const char* ss = "ba";
	myStrCat(t.ch, ss);
	t.length = strlen(ss);
	Index_BF(s, t, 1);
	return 0;
}
