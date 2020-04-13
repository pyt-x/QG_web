#include "LQueue.h"
#include <stdio.h>
#include <stdlib.h>
	
void InitLQueue(LQueue *Q){
    Node *head = malloc(sizeof(Node));  // head node
    if (!head) 
		exit(1); // allocation failed
    head->data = 0;
    Q->front = head;
    Q->rear = head;
    Q->rear->next = NULL;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	while(Q->front){
		Q->rear=Q->front->next;
		free(Q->front);
		Q->front=Q->rear;
	}
	if(Q->rear==Q->front)
	printf("success\n");
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(LQueue *Q){
	if(Q->rear==Q->front)
		return TRUE;
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, int *e){
	if(Q->rear==Q->front){
		printf("��\n");
		return FALSE;
	}
	*e = Q->front->next->data;
	printf("%d\n",*e);
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
 
int LengthLQueue(LQueue *Q){
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, int *data){
    Queneptr New = malloc(sizeof(int));
    if (!New) exit(1);  
    New->data = *data;
    New->next = NULL;
    Q->rear->next=New;
    Q->rear = New;
    Q->length++;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
    if(Q->front == Q->rear) 
    {
    	printf("��\n");
		exit(1);
	}
    Node *temp = Q->front->next;
    Q->front->next = temp->next;
    if (Q->rear == temp) 
		Q->rear = Q->front;
    free(temp);
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
    Q->rear = Q->front;
    Queneptr temp = Q->front->next;
    while (temp){
        Queneptr p = temp->next;
        free(temp);
        temp = p;
    }
    InitLQueue(Q);
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(LQueue *Q){
    printf("�����ڵ�Ԫ��Ϊ��\n");
    int i;
	Node *p;
    p = Q->front->next;
    while(p->next != NULL)
    {
        printf("[%d] ", p->data);
        p=p->next;
    }
    printf("[%d] ",p->data);
    printf("\n");
}

