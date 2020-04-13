#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"
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
	printf("                ||-------2 : IsEmptyLQueue------||\n");
	printf("                ||-------3 : GetHeadLQueue------||\n");
	printf("                ||-------4 : clear--------------||\n");
	printf("                ||-------5 : DestoryLQueue------||\n");
	printf("                ||-------6 : EnLQueue-----------||\n");
	printf("                ||-------7 : DeLQueue-----------||\n");
	printf("                ||-------8 : TraverseLQueue-----||\n");
	printf("                ||-------9 : LengthLQueue-------||\n");
	printf("                ||-------0 : exit---------------||\n");
}
int main()
{
	int n=0,e,d,is_init=0;
	LQueue q,*Q;
	Q = &q;
	InitLQueue(Q);
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
					InitLQueue(Q);
					printf("success\n");
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
					if(IsEmptyLQueue(Q)==TRUE)
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
					GetHeadLQueue(Q,&e);
					break;
			case '4':
					system("cls");
					pri();
					if(is_init = 0)
					{
						printf("please init\n");
						break;	
					}
					ClearLQueue(Q);
					break;
			case '5':
					system("cls");
					pri();
					if(is_init = 0)
					{
						printf("please init\n");
						break;	
					}
					DestoryLQueue(Q);
					break;
			case '6':
					system("cls");
					pri();	
					if(is_init = 0)
					{
						printf("please init\n");
						break;	
					}
					d = input_check();
					EnLQueue(Q,&d);
					break;
			case '7':
					system("cls");
					pri();
					if(is_init = 0)
					{
						printf("please init\n");
						break;	
					}
					DeLQueue(Q);
					break;
			case '8':
					system("cls");
					pri();
					if(is_init = 0)
					{
						printf("please init\n");
						break;	
					}
					TraverseLQueue(Q);
					break;
			case '9':
					system("cls");
					pri();
					if(is_init = 0)
					{
						printf("please init\n");
						break;	
					}
					printf("%d\n",LengthLQueue(Q));
					break;
			case '0':
					printf("\n*******************谢谢使用！*******************\n");
					Sleep(2000);
					return 0;
		}
	}
	return 0;
}
