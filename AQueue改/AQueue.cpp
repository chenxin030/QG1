#include "AQueue.h"
#include"menu.h"
#include<iostream>
#include<string.h>
/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
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
	puts("初始化成功\n");
}

/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
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
	puts("队列已销毁\n");
}

/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
int IsFullAQueue(const AQueue* Q)
{
	if (Q->b)
		return (LengthAQueue(Q) == (MAXQUEUE - 1) ? 1 : 0);
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
int IsEmptyAQueue(const AQueue* Q)
{
	if (Q->b)
		return (LengthAQueue(Q) == 0 ? 1 : 0);
	else
	{
		puts("没有队列\n");
		return 0;
	}
}

/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
bool GetHeadAQueue(AQueue* Q, void* e,int type)
{
	if (!Q->b)
	{
		puts("没有队列\n");
		return false;
	}
	if (IsEmptyAQueue(Q))
	{
		puts("队列为空,没有头元素\n");
		return false;
	}
	datacpy(e, Q->data[Q->front], type);
	return true;
}

/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(const AQueue* Q)
{
	if (!Q->b)
	{
		puts("没有队列\n");
		return 0;
	}
	return (Q->rear - Q->front + Q->length) % Q->length;
}

/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
int EnAQueue(AQueue* Q, void* data,int type)
{
	if (IsFullAQueue(Q))
	{
		puts("队列已满\n");
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
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int DeAQueue(AQueue* Q)
{
	if (!Q->b)
	{
		puts("没有队列\n");
		return 0;
	}
	if (IsEmptyAQueue(Q))
	{
		puts("队列为空，无法出队\n");
		return 0;
	}
	Q->front = (Q->front + 1) % Q->length;
	return 1;
}

/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue* Q)
{
	if (!Q->b)
	{
		puts("没有队列\n");
		return;
	}
	if (IsEmptyAQueue(Q))
	{
		puts("队列已空\n");
		return;
	}
	Q->front = Q->rear = 0;
	puts("队列已清空\n");
}

/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
int TraverseAQueue(const AQueue* Q, void (*foo)(void* q,int type),int type)
{
	if (IsEmptyAQueue(Q))
	{
		puts("队列为空\n");
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
 *    @description : 操作函数
 *    @param         q 指针q
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