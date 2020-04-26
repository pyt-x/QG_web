#include "BinaryTree.h"
#include<stdio.h>
#include <stdlib.h>

Status print(TElemType e){
	printf("[%c] ",e);
}

Status InitBiTree(BiTree T){
	if(T!=NULL){
		printf("�Ѿ���ʼ��\n");
		return SUCCESS;
	}
	T = (BiTree)malloc(sizeof(BiTNode));
	if (!T) {
		printf("����ʧ��\n");
		return ERROR;
	}
	T->lchild = (BiTree)malloc(sizeof(BiTNode));
	T->rchild = (BiTree)malloc(sizeof(BiTNode));
	printf("�ɹ���ʼ��\n");
	return SUCCESS;
}
//�������������ն�����T
Status DestroyBiTree(BiTree T){
	BiTree pl,pr;
	pl = pr = NULL;
	if (T == NULL){
		printf("�����Ƕ������Ƿ����\n"); 
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
//��ʼ������������T����
//����������ݻٶ�����T
char* CreateBiTree(BiTree *T, char* definition){
	BiTree T1;
	if ('#' == *definition)        //#��ʾ������ 
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
//��ʼ������ definition�����������Ķ���
//�����������definition���������T
void create(BiTree *T)
{
	char ch[100];
	int i,char_num,null_sum;
	if(*T != NULL){
		DestroyBiTree(*T);
	    *T = NULL;
	} 
	printf("\n�������뽨���ַ���(����'#'Ϊ������): ");
	fflush(stdin);		//��ϴ������ 
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
		printf("\n��������\n");
}


//���²��ֺ�������δָ����������
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
//��ʼ������������T���ڣ�visitΪ�Խ��Ĳ�����Ӧ�ú���
//����������������T����ÿ��������visit����һ���ҽ�һ�Σ�һ��visitʧ�ܣ������ʧ��
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
}	//�������

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
}	//�������

Status LDR(BiTree T){
	if(T != NULL){
		printf("\n�������: ");
		InOrderTraverse(T,print);
	}
}
Status DLR(BiTree T){
	if(T == NULL)
		printf("\n���������Ƿ����\n");
	else{
		printf("\n�������: ");
		PreOrderTraverse(T,print);
	}
}
Status LRD(BiTree T){
	if(T != NULL){
		printf("\n�������: ");
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
		printf("\n�������: ");
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
}	//�������

int Value(BiTree T){
	if(T->data <= '9'  &&  T->data >= '0')
		return (T->data - '0');		//ԭ����ͨ��ASCII��ת��Ϊint�ͣ�����ͨ���ݹ�õ����ӽڵ������ֵ 
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
}			//������Ķ�������ֵ

void count_DLR_BiTree(BiTree *T)
{
	char ch[100];
	int i,num, c_num;
	if(*T != NULL){
		DestroyBiTree(*T);
	    *T = NULL;	
	}
	printf("\n����ǰ׺���ʽ: ");
	fflush(stdin);
	scanf("%s",ch);	

	for(num = c_num = i = 0; ch[i] != 0; i++)
	{
		if('0' <= ch[i] && ch[i] <= '9') 
			num ++;
		if('+' == ch[i] || '-' == ch[i] || '*' == ch[i] || '/' == ch[i]) 
			c_num ++;
	}
	if(num + c_num == i  &&  num -1 == c_num)  //��ª�������Ŵ�
	{
		CreateBiTree(T,ch);    
		printf("\n���Ϊ: %d \n",Value(*T));
	}
	else
		printf("\n��������\n");	
}
