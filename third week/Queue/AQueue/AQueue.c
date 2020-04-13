#include "AQueue.h"
#include <stdio.h> 
#include <stdlib.h>
/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
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
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, int *e){
	if(Q->data[Q->front] == 0)
		return FALSE;
	else
		*e = Q->data[Q->front+1];
}		



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q){
	return (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE;
}	



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
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
 *    @description : ��������
 *    @param         q ָ��q
 *  @notice      : None
 */
void APrint(void *q);
