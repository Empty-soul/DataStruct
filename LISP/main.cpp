#include<stdio.h>

int main() {
	FILE* fpi,*fpo;
	fpi = fopen("������Ⱦ�����������.txt", "r");
	fpo = fopen("������Ⱦ���������.txt", "w");
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