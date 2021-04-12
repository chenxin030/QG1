#include "AQueue.h"
#include"menu.h"
#include<iostream>
#include<string.h>
/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitAQueue(AQueue* Q,int type)
{
	int i;
	Q->length = MAXQUEUE;
	Q->front = Q->rear = 0;
	switch (type)
	{
	case 1:
		for (i = 0; i < MAXQUEUE; i++)
			Q->data[i] = (int*)malloc(sizeof(int));
		break;
	case 2:
		for (i = 0; i < MAXQUEUE; i++)
			Q->data[i] = (double*)malloc(sizeof(double));
		break;
	case 3:
		for (i = 0; i < MAXQUEUE; i++)
			Q->data[i] = (char*)malloc(sizeof(char));
		break;
	}
	Q->b = 1;
	puts("��ʼ���ɹ�\n");
}

/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue* Q)
{
	int i;
	Q->b = 0;
	for (i = 0; i < MAXQUEUE; i++)
	{
		free(Q->data[i]);
	}
	puts("����������\n");
}

/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
int IsFullAQueue(const AQueue* Q)
{
	if (Q->b)
		return (LengthAQueue(Q) == (MAXQUEUE - 1) ? 1 : 0);
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
int IsEmptyAQueue(const AQueue* Q)
{
	if (Q->b)
		return (LengthAQueue(Q) == 0 ? 1 : 0);
	else
	{
		puts("û�ж���\n");
		return 0;
	}
}

/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
bool GetHeadAQueue(AQueue* Q, void* e,int type)
{
	if (!Q->b)
	{
		puts("û�ж���\n");
		return false;
	}
	if (IsEmptyAQueue(Q))
	{
		puts("����Ϊ��,û��ͷԪ��\n");
		return false;
	}
	datacpy(e, Q->data[Q->front], type);
	return true;
}

/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(const AQueue* Q)
{
	if (!Q->b)
	{
		puts("û�ж���\n");
		return 0;
	}
	return (Q->rear - Q->front + Q->length) % Q->length;
}

/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
int EnAQueue(AQueue* Q, void* data,int type)
{
	if (IsFullAQueue(Q))
	{
		puts("��������\n");
		return 0;
	}
	if (IsEmptyAQueue(Q))
	{
		datacpy(Q->data[Q->front], data, type);
		Q->rear = (Q->rear + 1) % Q->length;
		return 1;
	}
	datacpy(Q->data[Q->rear], data, type);
	Q->rear = (Q->rear + 1) % Q->length;
	return 0;
}

/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int DeAQueue(AQueue* Q)
{
	if (!Q->b)
	{
		puts("û�ж���\n");
		return 0;
	}
	if (IsEmptyAQueue(Q))
	{
		puts("����Ϊ�գ��޷�����\n");
		return 0;
	}
	Q->front = (Q->front + 1) % Q->length;
	return 1;
}

/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue* Q)
{
	if (!Q->b)
	{
		puts("û�ж���\n");
		return;
	}
	if (IsEmptyAQueue(Q))
	{
		puts("�����ѿ�\n");
		return;
	}
	Q->front = Q->rear = 0;
	puts("���������\n");
}

/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
int TraverseAQueue(const AQueue* Q, void (*foo)(void* q,int type),int type)
{
	if (IsEmptyAQueue(Q))
	{
		puts("����Ϊ��\n");
		return 0;
	}
	int i = 0;
	while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE)
	{
		foo(Q->data[Q->front + i],type);
		i = (i + 1) % MAXQUEUE;
	}
	return 1;
}

/**
 *  @name        : void APrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 *  @notice      : None
 */
void APrint(void* q,int type)
{
	s_printf(q, type);
	puts("");
}
void datacpy(void* ptr, void* data, int type)
{
	switch (type)
	{
	case 1:
		memcpy(ptr, data, sizeof(int));
		break;
	case 2:
		memcpy(ptr, data, sizeof(double));
		break;
	case 3:
		memcpy(ptr, data, sizeof(char));
		break;
	}
}