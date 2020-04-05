#include "linkstack.h"
#include <stdio.h>
#include <stdlib.h> 
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

void pri()
{
	printf("\n***********************WELCOME TO USE***************************");
	printf("\n                ||-------1 : init-------------||\n");      
	printf("                ||-------2 : isEmptyLStack----||\n");
	printf("                ||-------3 : getTopLStack-----||\n");
	printf("                ||-------4 : clearLStack------||\n");
	printf("                ||-------5 : destroyLStack----||\n");
	printf("                ||-------6 : LStackLength-----||\n");
	printf("                ||-------7 : pushLStack-------||\n");
	printf("                ||-------8 : popLStack--------||\n");
	printf("                ||-------0 : exit-------------||\n");
}

void land()
{
	int n=0,is_init=1,length;
	int i,total,data;
	LinkStack *s,stack;
	ElemType *e;
	s = &stack;
	is_init = initLStack(s);
	pri();
	while(1)
	{
		printf("Please give the number to continue:\n");
		switch(n = check())
		{	
			case '1':
					system("cls");
					pri();
					if(is_init == 1)
					{
						printf("已经初始化\n");
						break;	
					}	
					initLStack(s);
					break;	
			case '2':
					system("cls");
					pri();
					if(is_init == 0)
					{
						printf("请初始化\n");
						break;	
					}
					isEmptyLStack(s);
					break;
			case '3':
					system("cls");
					pri();
					if(is_init == 0)
					{
						printf("请初始化\n");
						break;	
					}
					getTopLStack(s,e);
					printf("栈顶元素为：%d\n",*e);
					break;
			case '4':
					system("cls");
					pri();
					if(is_init == 0)
					{
						printf("请初始化\n");
						break;	
					}
					clearLStack(s);
					break;
			case '5':
					system("cls");
					pri();
					if(is_init == 0)
					{
						printf("请初始化\n");
						break;	
					}
					destroyLStack(s);
					is_init = 0;
					break;
			case '6':
					system("cls");
					pri();
					if(is_init == 0)
					{
						printf("请初始化\n");
						break;	
					}
					length = LStackLength(s);
					printf("长度是%d\n", length);
					break;
			case '7':
					system("cls");
					pri();
					if(is_init == 0)
					{
						printf("请初始化\n");
						break;	
					}
					printf("你想插入多少个数字：");
					total =  input_check();
					for(i=0;i<total;i++)
					{
						data = input_check();
				    	pushLStack(s,data);	
					}
				    break;
			case '8':
					system("cls");
					pri();
					if(is_init == 0)
					{
						printf("请初始化\n");
						break;	
					}
					popLStack(s,e);
					printf("倒出的栈顶元素%d\n",*e);
					break;
			case '0':
					system("cls");
					pri();
					printf("\n*******************谢谢使用！*******************\n");
					Sleep(1500);
				    exit(0);
			default:
              		printf("采集参数失败");   
		}	
	}
}

int main()
{
	land();
	return 0;
}
