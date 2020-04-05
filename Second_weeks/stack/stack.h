#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define INIT_SIZE 100

typedef int ElemType;

typedef enum Status {
	ERROR=0,
	SUCCESS=1
} Status;
 
typedef struct {
    ElemType *base;   //在构造之前和销毁之后，base的值为NULL
    ElemType *top;    //栈顶指针
    int size;     //当前已分配的存储空间，以元素为单位
}SqStack;

char check();
int input_check();

//基于数组的顺序栈
Status initStack(SqStack *s,int sizes);//初始化栈
Status isEmptyStack(SqStack *s);//判断栈是否为空
Status getTopStack(SqStack *s,ElemType *e); //得到栈顶元素
Status clearStack(SqStack *s);//清空栈
Status destroyStack(SqStack *s);//销毁栈
int stackLength(SqStack s);//检测栈长度
Status pushStack(SqStack *s,ElemType data);//入栈
Status popStack(SqStack *s);//出栈

#endif
