#include "AQueue.h"
#include <stdio.h> 
#include <stdlib.h>
/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q){
	Q->data = (int*)malloc(MAXQUEUE * sizeof(int));
    if (Q->data ==NULL)
        exit(-1);
    Q->front = Q->rear = 0;
    printf("init success");
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q){
	Q->data = NULL;
	Q->rear = 0;
	Q->front = 0;
	free(Q->data);
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(AQueue *Q){
	if((Q->rear + 1) % MAXQUEUE == Q->front)
		return TRUE;
	else
		return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(AQueue *Q){
	if(Q->rear == Q->front)
		return TRUE;
	else
		return FALSE;
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, int *e){
	if(Q->data[Q->front] == 0)
		return FALSE;
	else
		*e = Q->data[Q->front+1];
}		



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q){
	return (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE;
}	



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, int data){
	if (IsFullAQueue(Q))
		return FALSE;
	Q->data[Q->rear + 1] = data;
	Q->rear = (Q->rear + 1) % MAXQUEUE;
	return TRUE;
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q){
	if(IsEmptyAQueue(Q))
		return FALSE;
	Q->front = (Q->front + 1) % MAXQUEUE;
	return TRUE;
}	



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q){
	if(Q->front==Q->rear){
		printf("null");
		return;
	}
	while(Q->front!=Q->rear){
		Q->front=(Q->front+1)%MAXQUEUE;
	}
	printf("success");
}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(AQueue *Q){
	int i=Q->front;
	
	while(i!=Q->rear){
		i=(i+1)%MAXQUEUE;
		printf("[%d] ",Q->data[i]);
	}
}	



/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q);
