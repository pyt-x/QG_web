#include<stdio.h>
#include "computer.h"

int main()
{
	Elemtype str[MAXBUFFER];
	Elemtype cpy[MAXBUFFER] = {'\0'};
	int data[20];
	int i;
	SqStack S;
	printf("��ʱ�����ܽ��д�������Ŷ\n");
	gets(str);
	Change(&S,str,cpy,data);
	printf("----------------------\n");
	calculate(cpy,data);
	return 0;
}
