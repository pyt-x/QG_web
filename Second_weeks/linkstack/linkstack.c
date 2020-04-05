#include <stdlib.h>
#include <stdio.h>
#include "linkstack.h"


Status initLStack(LinkStack *s)
{
    s->base = (LinkStackPtr)malloc(sizeof(LinkStackPtr));
    if(s->base == NULL)
    	return ERROR;
  	s->base->next = NULL;
    s->top = s->base;
    printf("init success\n");
    return SUCCESS;
}//初始化栈

Status isEmptyLStack(LinkStack *s)
{	
    if(s->base == NULL)
   		exit(0);
    s->top == s->base ? printf("Empty!\n") : printf("no empty\n");
    return SUCCESS;
}//判断栈是否为空

Status getTopLStack(LinkStack *s,ElemType *e)
{
    if(s->top == s->base)
		return ERROR;
    LinkStackPtr p = s->base;
    while(p->next != s->top)
	{
    	p = p->next;
	}
    *e = p->data;
    return SUCCESS;
}//得到栈顶元素

Status clearLStack(LinkStack *s)
{
	if(s->base == NULL)
		return ERROR;
    s->top = s->base;
    LinkStackPtr p = s->base->next;
    s->base->next = NULL;
    while(p != NULL){
    	LinkStackPtr q = p->next;
    	free(p);
    	p = q;
  }
  return SUCCESS;
}//清空栈

Status destroyLStack(LinkStack *s)
{
	if(s->base == NULL)
		exit(0);
    LinkStackPtr p, q;
    p = s->base;
    while(p != NULL)
	{
    	q = p->next;
    	free(p);
    	p = q;
    }
  s->base = NULL;
  return SUCCESS;
}//销毁栈

int LStackLength(LinkStack *s)
{
	int length = 0;
	if(s->base == NULL)
		exit(0);
    LinkStackPtr p = s->base;
    while(p != s->top){
    length += 1;
    p = p->next;
    }
    return length;
}//检测栈长度
Status pushLStack(LinkStack *s,ElemType data)
{
    if(s->base == NULL)
		exit(0);//栈结构不存在
    s->top->data = data;
    LinkStackPtr p_new = (LinkStackPtr)malloc(sizeof(LinkStackPtr));
    if(p_new == NULL)
		exit(0);
    p_new->next = NULL;
    s->top->next = p_new;
    s->top = p_new;
    return SUCCESS;
}//入栈
Status popLStack(LinkStack *s,ElemType *data)
{
	
    if(s->top == s->base)
		return ERROR;//空栈返回错误
    LinkStackPtr p = s->base;
    while(p->next != s->top){
        p = p->next;
    }
    *data = p->data;
 	return SUCCESS;
}//出栈

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
