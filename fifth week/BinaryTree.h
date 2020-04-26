#ifndef BINARYTERR_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include<stdio.h>
#include <stdlib.h>

typedef char TElemType;     // �������������Ԫ������Ϊ�ַ�

typedef struct  BiTNode {
    TElemType      data;     // ������
    struct BiTNode  *lchild,*rchild;  // ���Һ���ָ��
} BiTNode,*BiTree;   // ��������

typedef enum Status{
	SUCCESS,
	ERROR
}Status;

typedef struct QueueNode{  //��α������϶������� 
	BiTree data;
	struct QueueNode *next;
}QueueNode,*pQueueNode;
 
typedef struct Queue{
	pQueueNode front;
	pQueueNode rear;
}Queue,*pQueue;

Status print(TElemType e);
void count_DLR_BiTree(BiTree *T);
void create(BiTree *T);
BiTree dequeue(pQueue pqueue);
void enqueue(pQueue pqueue,BiTree t);
pQueue init_queue(pQueue pqueue);
Status LRD(BiTree T);
Status LDR(BiTree T);
Status DLR(BiTree T);

Status InitBiTree(BiTree T);
//�������������ն�����T
Status DestroyBiTree(BiTree T);
//��ʼ������������T����
//����������ݻٶ�����T
char* CreateBiTree(BiTree *T, char* definition);
//��ʼ������ definition�����������Ķ���
//�����������definition���������T


//���²��ֺ�������δָ����������
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));
//��ʼ������������T���ڣ�visitΪ�Խ��Ĳ�����Ӧ�ú���
//����������������T����ÿ��������visit����һ���ҽ�һ�Σ�һ��visitʧ�ܣ������ʧ��
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));	//�������
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e));	//�������
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));	//�������
int Value(BiTree T);			//������Ķ�������ֵ
/*
��ʾ�����ڽ��ṹ�������ø�Tagֵ��־������������������������
�ɸ�����Ҫ�������Ӳ���.
*/

#endif 
