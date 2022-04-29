#include<stdio.h>

int main() {
	FILE* fpi,*fpo;
	fpi = fopen("病毒感染检测输入数据.txt", "r");
	fpo = fopen("病毒感染检测输出结果.txt", "w");
	char person[30] = "";
	char virus[30] = "";
	char c;
	do {
		c = fgetc(fpi);
		if (c == EOF) break;
	} while (c != ' ' );
	
	fclose(fpi);
	fclose(fpo);
	return 0;
}