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
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
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
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(LQueue *Q){
	if(Q->rear==Q->front)
		return TRUE;
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, int *e){
	if(Q->rear==Q->front){
		printf("空\n");
		return FALSE;
	}
	*e = Q->front->next->data;
	printf("%d\n",*e);
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
 
int LengthLQueue(LQueue *Q){
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
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
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
    if(Q->front == Q->rear) 
    {
    	printf("空\n");
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
 *    @description : 清空队列
 *    @param         Q 队列指针Q
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
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(LQueue *Q){
    printf("队列内的元素为：\n");
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

