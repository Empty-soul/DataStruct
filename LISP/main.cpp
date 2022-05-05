#include<stdio.h>

int main() {
	FILE* fpi,*fpo;
	fpi = fopen("C:\\Users\\24400\\Desktop\\病毒感染检测输入数据.txt", "r");
	fpo = fopen("C:\\Users\\24400\\Desktop\\病毒感染检测输出结果.txt", "w");
	char person[30] = "";
	char virus[30] = "";
	char c;
	int num = fgetc(fpi);
	while(num>0){
	do 
	{
		c = fgetc(fpi);
		
	} while (c != ' ' );
	}
	fclose(fpi);
	fclose(fpo);
	return 0;
}