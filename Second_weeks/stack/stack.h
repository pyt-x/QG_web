#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define INIT_SIZE 100

typedef int ElemType;

typedef enum Status {
	ERROR=0,
	SUCCESS=1
} Status;
 
typedef struct {
    ElemType *base;   //�ڹ���֮ǰ������֮��base��ֵΪNULL
    ElemType *top;    //ջ��ָ��
    int size;     //��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}SqStack;

char check();
int input_check();

//���������˳��ջ
Status initStack(SqStack *s,int sizes);//��ʼ��ջ
Status isEmptyStack(SqStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopStack(SqStack *s,ElemType *e); //�õ�ջ��Ԫ��
Status clearStack(SqStack *s);//���ջ
Status destroyStack(SqStack *s);//����ջ
int stackLength(SqStack s);//���ջ����
Status pushStack(SqStack *s,ElemType data);//��ջ
Status popStack(SqStack *s);//��ջ

#endif
