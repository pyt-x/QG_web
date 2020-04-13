#include <stdio.h>
#include <stdlib.h>
#include "AQueue.h"
#include <windows.h>

char check()
{
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
        printf("请输入有效数字：");
    }
    return '\0';
}

int input_check()
{
	int v,init;
	while(1)
	{
		printf("输入有效值：");
		v = scanf("%d",&init);
		if(v==1)
		{
			return init;
			break;			
		}
		else
		{
			printf("给出数字！\n"); 
			while(1)
			{
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
	printf("                ||-------2 : IsEmptyAQueue------||\n");
	printf("                ||-------3 : GetHeadAQueue------||\n");
	printf("                ||-------4 : clear--------------||\n");
	printf("                ||-------5 : DestoryAQueue------||\n");
	printf("                ||-------6 : EnAQueue-----------||\n");
	printf("                ||-------7 : DeAQueue-----------||\n");
	printf("                ||-------8 : TraverseAQueue-----||\n");
	printf("                ||-------0 : exit---------------||\n");
}

int main() {
	int n=0,e,d,is_init=0;
	AQueue q,*Q;
	Q = &q;
	InitAQueue(Q);
	is_init = 1;
	pri();
	while(1)
	{
		printf("Please give the number to continue:\n");
		switch(n = check())
		{	
			case '1':
					system("cls");
					pri();
					InitAQueue(Q);
					is_init = 1;
					break;	
			case '2':
					system("cls");
					pri();
					if(is_init = 0)
					{
						printf("please init\n");
						break;	
					}
					if(IsEmptyAQueue(Q)==TRUE)
						printf("full\n");
					else
						printf("no full\n");
					break;
			case '3':
					system("cls");
					pri();
					if(is_init = 0)
					{
						printf("please init\n");
						break;	
					}
					GetHeadAQueue(Q,&e);
					printf("元素为：%d\n",e);
					break;
			case '4':
					system("cls");
					pri();
					if(is_init = 0)
					{
						printf("please init\n");
						break;	
					}
					ClearAQueue(Q);
					break;
			case '5':
					system("cls");
					pri();
					if(is_init = 0)
					{
						printf("please init\n");
						break;	
					}
					DestoryAQueue(Q);
					break;
			case '6':
					system("cls");
					pri();
					d = input_check();
					EnAQueue(Q,d);
					break;
			case '7':
					system("cls");
					pri();
					if(is_init = 0)
					{
						printf("please init\n");
						break;	
					}
					DeAQueue(Q);
					break;
			case '8':
					system("cls");
					pri();
					if(is_init = 0)
					{
						printf("please init\n");
						break;	
					}
					TraverseAQueue(Q);
					break;
			case '9':
					system("cls");
					pri();
					if(is_init = 0)
					{
						printf("please init\n");
						break;	
					}
					printf("%d",LengthAQueue(Q));
					break;
			case '0':
					printf("\n*******************谢谢使用！*******************\n");
					Sleep(2000);
					return 0;
		}
	}
	return 0;
}
