#include<stdio.h>
#include<stdlib.h>
#include<ctype.h> 
#include<assert.h>

#define INITSIZE  20
#define INCREMENT 10
#define MAXBUFFER 20

 
typedef char Elemtype;
typedef struct{
	Elemtype *base;
	Elemtype *top;
	int size;
}SqStack;

void InitStack(SqStack *S);
void PushStack(SqStack *S,Elemtype c);
int PopStack(SqStack *S,Elemtype *c);
void Change(SqStack *S,Elemtype str[],Elemtype cpy[],int data[]);
int calculate(Elemtype cpy[],int data[]);
