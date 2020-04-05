#include "Stack.h"
#include<stdio.h>
#include <stdlib.h> 

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
        printf("��������Ч���֣�");
    }
    return '\0';
}

int input_check()
{
	int v,init;
	while(1)
	{
		printf("������Чֵ��");
		v = scanf("%d",&init);
		if(v==1)
		{
			return init;
			break;			
		}
		else
		{
			printf("��������"); 
			while(1)
			{
				char c = getchar();
				if(c == '\n')
					break;
			}			
		}
	}
}


Status initStack(SqStack *s,int sizes)
{
    s->base = (ElemType*)malloc(INIT_SIZE * sizeof(ElemType));
    if (s->base == NULL)
    {
    	printf("Failed to init\n"); 
    	return ERROR;	
	}
    s->top = s->base;     
    s->size = INIT_SIZE;
    printf("init success\n");
    return SUCCESS;
}

Status isEmptyStack(SqStack *s)
{
    if (s->top == s->base) 
		return SUCCESS;
	else 
		return ERROR;
}

Status getTopStack(SqStack *s,ElemType *e)
{
	if(isEmptyStack(s) == 1)
	{
		printf("��");
		return ERROR;
	}
    if (s->top > s->base) {
        *e = *(s->top - 1); 
		return SUCCESS;
    }
    else 
		return ERROR;
}

Status clearStack(SqStack *s)
{
	if(s->top== s->base)
    	printf("�Ѿ�����������ظ�\n");
    else
   		s->top = s->base;
    return SUCCESS;
}

Status destroyStack(SqStack *s)
{
	free(s->base);
    s->base = NULL;
    s->top = NULL;
    s->size = 0;
    printf("�ݻٳɹ�\n");
    return SUCCESS;
}

int stackLength(SqStack s)
{
	return s.top - s.base;
}//���ջ����

Status pushStack(SqStack *s,ElemType data)
{
    if ((s->top - s->base)>= s->size)
    {
        s->base = (ElemType*)realloc(s->base, (s->size + 10) * sizeof(ElemType));
        if (s->base == NULL)   return ERROR;
        s->top = s->base + s->size;
        s->size += 10;
    }
    *(s->top) = data;
    (s->top)++;
    return SUCCESS;
}//��ջ

Status popStack(SqStack *s)
{
    if (s->top == s->base)
	{
		printf("��"); 
		return ERROR;
	}
    --(s->top);
    printf("pop success\n");
    return SUCCESS;
}//��ջ
