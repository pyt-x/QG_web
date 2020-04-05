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
}//��ʼ��ջ

Status isEmptyLStack(LinkStack *s)
{	
    if(s->base == NULL)
   		exit(0);
    s->top == s->base ? printf("Empty!\n") : printf("no empty\n");
    return SUCCESS;
}//�ж�ջ�Ƿ�Ϊ��

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
}//�õ�ջ��Ԫ��

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
}//���ջ

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
}//����ջ

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
}//���ջ����
Status pushLStack(LinkStack *s,ElemType data)
{
    if(s->base == NULL)
		exit(0);//ջ�ṹ������
    s->top->data = data;
    LinkStackPtr p_new = (LinkStackPtr)malloc(sizeof(LinkStackPtr));
    if(p_new == NULL)
		exit(0);
    p_new->next = NULL;
    s->top->next = p_new;
    s->top = p_new;
    return SUCCESS;
}//��ջ
Status popLStack(LinkStack *s,ElemType *data)
{
	
    if(s->top == s->base)
		return ERROR;//��ջ���ش���
    LinkStackPtr p = s->base;
    while(p->next != s->top){
        p = p->next;
    }
    *data = p->data;
 	return SUCCESS;
}//��ջ

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
			printf("�������֣�\n"); 
			while(1)
			{
				char c = getchar();
				if(c == '\n')
					break;
			}			
		}
	}
}
