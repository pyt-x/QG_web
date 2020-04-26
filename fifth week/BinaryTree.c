#include "BinaryTree.h"
#include<stdio.h>
#include <stdlib.h>

Status print(TElemType e){
	printf("[%c] ",e);
}

Status InitBiTree(BiTree T){
	if(T!=NULL){
		printf("已经初始化\n");
		return SUCCESS;
	}
	T = (BiTree)malloc(sizeof(BiTNode));
	if (!T) {
		printf("创建失败\n");
		return ERROR;
	}
	T->lchild = (BiTree)malloc(sizeof(BiTNode));
	T->rchild = (BiTree)malloc(sizeof(BiTNode));
	printf("成功初始化\n");
	return SUCCESS;
}
//操作结果：构造空二叉树T
Status DestroyBiTree(BiTree T){
	BiTree pl,pr;
	pl = pr = NULL;
	if (T == NULL){
		printf("请检查是二叉树是否存在\n"); 
		return ERROR;
	} 
	pl = T->lchild;
	pr = T->rchild;
	T->lchild = NULL;
	T->rchild = NULL;
	free(T);
	T = NULL;
	DestroyBiTree(pl);
	DestroyBiTree(pr);
	return SUCCESS;
	
}
//初始条件：二叉树T存在
//操作结果：摧毁二叉树T
char* CreateBiTree(BiTree *T, char* definition){
	BiTree T1;
	if ('#' == *definition)        //#表示空子数 
		*T = NULL;
	else{
		*T = (BiTree)malloc(sizeof(BiTNode));	
		if (!T){
			exit(1);
		}
		(*T)->data = *definition;
		definition = CreateBiTree(&((*T)->lchild),definition+1);
		definition = CreateBiTree(&((*T)->rchild),definition+1);
	}
	return definition;
}
//初始条件： definition给出二叉树的定义
//操作结果：按definition构造二叉树T
void create(BiTree *T)
{
	char ch[100];
	int i,char_num,null_sum;
	if(*T != NULL){
		DestroyBiTree(*T);
	    *T = NULL;
	} 
	printf("\n先序输入建树字符串(输入'#'为空子树): ");
	fflush(stdin);		//冲洗输入流 
	scanf("%s",ch);

	for(char_num = null_sum = i = 0; ch[i] != 0; i++){
		if('0' <= ch[i] && ch[i] <= '9') 
			char_num ++;
		if('#' == ch[i] ) 
			null_sum ++;
	}
	if(char_num + null_sum == i && char_num + 1 == null_sum && ch[0] != '#') 
		CreateBiTree(T,ch);
	else
		printf("\n输入有误\n");
}


//以下部分函数定义未指定参数类型
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
	if (T==NULL)
		return SUCCESS;
	(*visit)(T->data);
	if (PreOrderTraverse(T->lchild,visit)==SUCCESS)
	{
		if (PreOrderTraverse(T->rchild,visit)==SUCCESS)
			return SUCCESS;
	}
	return ERROR;
}
//初始条件：二叉树T存在，visit为对结点的操作的应用函数
//操作结果：先序遍历T，对每个结点调用visit函数一次且仅一次，一旦visit失败，则操作失败
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
	if(T==NULL){
		return SUCCESS;
	}
	if(InOrderTraverse(T->lchild,visit)==SUCCESS){
		(*visit)(T->data);
		if(InOrderTraverse(T->rchild,visit)==SUCCESS){
			return SUCCESS;
		}
	}
}	//中序遍历

Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
	if(T==NULL){
		return SUCCESS;
	} 
	if(PostOrderTraverse(T->lchild, visit)==SUCCESS){
		if ( PostOrderTraverse(T->rchild, visit)==SUCCESS){
			(*visit)(T->data);
			return SUCCESS;
		}
	}
	return ERROR;
}	//后序遍历

Status LDR(BiTree T){
	if(T != NULL){
		printf("\n中序遍历: ");
		InOrderTraverse(T,print);
	}
}
Status DLR(BiTree T){
	if(T == NULL)
		printf("\n检查二叉树是否存在\n");
	else{
		printf("\n先序遍历: ");
		PreOrderTraverse(T,print);
	}
}
Status LRD(BiTree T){
	if(T != NULL){
		printf("\n后序遍历: ");
		PostOrderTraverse(T,print);
	}
}

pQueue init_queue(pQueue pqueue){
	pqueue->front=(pQueueNode)malloc(sizeof(QueueNode));
	pqueue->front->next=NULL;
	pqueue->rear=pqueue->front;
	return pqueue;
}
void enqueue(pQueue pqueue,BiTree t){
	pQueueNode pNew=(pQueueNode)malloc(sizeof(QueueNode));
	pNew->data=t;
	pNew->next=NULL;
	pqueue->rear->next=pNew;
	pqueue->rear=pNew;
}
BiTree dequeue(pQueue pqueue){
	BiTree t;
	pQueueNode pTemp=(pQueueNode)malloc(sizeof(QueueNode));
	pTemp=pqueue->front->next;
	if(pTemp->next==NULL){
		pqueue->rear=pqueue->front;
	}else{
		pqueue->front->next=pTemp->next;
	}
	t=pTemp->data;
	free(pTemp);
	return t;
}

Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
	pQueue pqueue=(pQueue)malloc(sizeof(Queue));
	pqueue=init_queue(pqueue);
	
	if(T != NULL)
	{
		printf("\n层序遍历: ");
		enqueue(pqueue,T);
	    while(pqueue->rear!=pqueue->front){
		    BiTree t=dequeue(pqueue);		
			visit(t->data);		
			if(t->lchild){			
				enqueue(pqueue,t->lchild);		
			}
			if(t->rchild){
				enqueue(pqueue,t->rchild);
			}
		}
	}	
}	//层序遍历

int Value(BiTree T){
	if(T->data <= '9'  &&  T->data >= '0')
		return (T->data - '0');		//原理还是通过ASCII码转换为int型，后面通过递归得到孩子节点的运算值 
	else
	{
		switch(T->data)
		{
     		case'+':  
			 		return Value(T->lchild) + Value(T->rchild);
			case'-':  
					return Value(T->lchild) - Value(T->rchild);
			case'*':  
					return Value(T->lchild) * Value(T->rchild);
			case'/':  
					return Value(T->lchild) / Value(T->rchild);
		}
	}
}			//构造出的二叉树求值

void count_DLR_BiTree(BiTree *T)
{
	char ch[100];
	int i,num, c_num;
	if(*T != NULL){
		DestroyBiTree(*T);
	    *T = NULL;	
	}
	printf("\n输入前缀表达式: ");
	fflush(stdin);
	scanf("%s",ch);	

	for(num = c_num = i = 0; ch[i] != 0; i++)
	{
		if('0' <= ch[i] && ch[i] <= '9') 
			num ++;
		if('+' == ch[i] || '-' == ch[i] || '*' == ch[i] || '/' == ch[i]) 
			c_num ++;
	}
	if(num + c_num == i  &&  num -1 == c_num)  //简陋的输入排错
	{
		CreateBiTree(T,ch);    
		printf("\n结果为: %d \n",Value(*T));
	}
	else
		printf("\n输入有误\n");	
}
