#include "BinaryTree.h"
#include<stdio.h>
#include <stdlib.h>

char check(){
    char c, flag;
    int i;
    while(1){
        for(i = 0; (c = getchar()) != '\n'; flag = c, ++i)
            ;
        if(i == 1){
            if('0'<=flag && flag<='9'){
                return flag;
            }
        }else if(i == 0){
            continue;
        }
        printf("��������Ч���֣�");
    }
    return '\0';
}

int input_check(){
	int v,init;
	while(1){
		printf("������Чֵ��");
		v = scanf("%d",&init);
		if(v==1){
			return init;
			break;			
		}
		else
		{
			printf("�������֣�\n"); 
			while(1){
				char c = getchar();
				if(c == '\n')
					break;
			}			
		}
	}
}

void pri()
{
	printf("\n***********************WELCOME TO USE***************************");
	printf("\n                ||-------1 : init---------------||\n");      
	printf("                ||-------2 : creat--------------||\n");
	printf("                ||-------3 : destroy-------------||\n");
	printf("                ||-------4 : travel--------------||\n");
	printf("                ||-------5 : count(ǰ׺)---------||\n");
	printf("                ||-------0 : exit----------------||\n");
}

int main() {
	BiTree T=NULL;
	int n;
	pri();
	while(1)
	{
		printf("Please give the number to continue:\n");
		switch(n = check())
		{	
			case '1':
					system("cls");
					pri();
					InitBiTree(T);
					break;	
			case '2':
					system("cls");
					pri();
					create(&T);
					break;
			case '3':
					system("cls");
					pri();
					DestroyBiTree(T);
					break;
			case '4':
					system("cls");
					pri();
					printf("\n��ѡ���������(1:����2:����3:����): "); 
					DLR(T);
					LDR(T);
					LRD(T);
					break;
			case '5':
					system("cls");
					pri();
					count_DLR_BiTree(&T);
					break;
			case '0':
					printf("\n*******************ллʹ�ã�*******************\n");
					Sleep(2000);
					return 0;
		}
	}
	return 0;
}
