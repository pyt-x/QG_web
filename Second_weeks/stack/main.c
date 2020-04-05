#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <windows.h>

void pri()
{
	printf("\n                |-------1 : init-------------|\n");      
	printf("                |-------2 : isEmptyStack-----|\n");
	printf("                |-------3 : getTopStack------|\n");
	printf("                |-------4 : clearStack-------|\n");
	printf("                |-------5 : destroyStack-----|\n");
	printf("                |-------6 : stackLength------|\n");
	printf("                |-------7 : pushStack--------|\n");
	printf("                |-------8 : popStack---------|\n");
	printf("                |-------0 : exit-------------|\n");
}

int main() {
	ElemType i,n,data,is_init=0,sure;
    SqStack *s,stack;
    s = &stack;
	ElemType *e;
	e=(ElemType*)malloc(sizeof(ElemType));
	is_init = initStack(s,100);
	printf("\n***********************WELCOME TO USE***********************");
	pri();
	while(1)
	{
		switch(n = check())
		{
			case '1':
					system("cls");
					pri();
					if(is_init ==1)
					{
						printf("�Ѿ���ʼ����\n");
						break;
					}
					else
					{
						is_init = initStack(s,100);
					}

			case '2':
					system("cls");
					pri();
					if(is_init == 0)
					{
						printf("���ʼ��\n");
						break;
					}
					isEmptyStack(s) == 1 ? printf("Empty\n") : printf("no empty\n");		
					break;
			case '3':
					system("cls");
					pri();
					if(is_init == 0)
					{
						printf("���ʼ��\n");
						break;
					}
					if(getTopStack(s, e)==1)
						printf("ջ��Ԫ��Ϊ��%d", *e);
					break;
			case '4':
					system("cls");
					pri();
					if(is_init == 0)
					{
						printf("���ʼ��\n");
						break;
					}
					clearStack(s);
					break;
			case '5':
					system("cls");
					pri();
					if(is_init == 0)
					{
						printf("���ʼ��\n");
						break;
					}
					destroyStack(s);
					is_init = 0;	
			case '6':
					system("cls");
					pri();
					if(is_init == 0)
					{
						printf("���ʼ��\n");
						break;
					}
					printf("����Ϊ��%d",stackLength(stack));		
					break;
			case '7':
					system("cls");
					pri();
					if(is_init == 0)
					{
						printf("���ʼ��\n");
						break;
					}
					printf("������������֣�");
					n = input_check();
					for(i=0;i<n;i++)
					{
						data = input_check();
						pushStack(s,data);
					}
					break;
			case '8':
					system("cls");
					pri();
					if(is_init == 0)
					{
						printf("���ʼ��\n");
						break;
					}
					popStack(s);
					break;
			case '0':
					printf("Are you sure? yes[1659874563] no[1]");
					sure = input_check();
					if(sure == 1659874563)
					{	
						printf("\n*******************ллʹ�ã�*******************\n");
						Sleep(2000);
						return 0;
					}
					else if(sure == 1)
					{
						printf("\n*****WELCOME BACK*****");
						break;
					}						
					else 
						break;		    
		}		
	}
	return 0;
}
