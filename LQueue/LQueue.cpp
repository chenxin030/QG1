#include"menu.h"
#include"LQueue.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//初始化队列
void InitLQueue(LQueue* Q)
{
	Q->front = Q->rear = new Node;
	Q->front->next = Q->rear = NULL;
	Q->length = 0;
	puts("队列已初始化\n");
}
// 销毁队列
void DestoryLQueue(LQueue* Q)
{
	if (Q->front)
	{
		ClearLQueue(Q);
		delete(Q->front);
		delete(Q->rear);
		Q->rear = Q->front = NULL;
		puts("队列已销毁\n");
	}
	
}
//检查队列是否为空
Status IsEmptyLQueue(const LQueue* Q)
{
	if (Q->length == 0)
	{
		return TRUE;
	}
	return FALSE;
}
//检查队列是否已满
Status IsFullLQueue(const LQueue* Q)
{
	if (Q->length == MAX)
		return TRUE;
	else
		return FALSE;
}
//查看队头元素
Status GetHeadLQueue(LQueue* Q,void* e,int type)
{
	if (IsEmptyLQueue(Q))
	{
		puts("队列为空,没有头元素");
		return FALSE;
	}
	datacpy(e, Q->front->next->data , type);
	return TRUE;
}
//确定队列长度
int LengthLQueue(LQueue* Q)
{
	return Q->length;
}
//入队操作
Status EnLQueue(LQueue* Q,void* data,int type)
{
	if (Q->length == MAX)
	{
		puts("队列已满，无法入队");
		return FALSE;
	}
	Node* pnew;
	pnew = new Node;
	switch (type)
	{
	case 1:
		pnew->data = (int*)malloc(sizeof(int));
		break;
	case 2:
		pnew->data = (double*)malloc(sizeof(double));
		break;
	case 3:
		pnew->data = (char*)malloc(sizeof(char));
		break;
	}
	datacpy(pnew->data, data, type);
	pnew->next = NULL;
	if (IsEmptyLQueue(Q))
	{
		Q->front->next = pnew;
		Q->rear = pnew;
		Q->length++;
	}
	else
	{
		Q->rear->next = pnew;
		Q->length++;
		Q->rear = Q->rear->next;
	}
	return TRUE;
}
//出队操作
Status DeLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
	{
		puts("队列为空，无法出队");
		return FALSE;
	}
	Node* pt = Q->front->next;
	Q->front->next = pt->next;
	delete pt;
	Q->length--;
	return TRUE;
}
//清空队列
void ClearLQueue(LQueue* Q)
{
	Node* pt = Q->front->next;
	while (!IsEmptyLQueue(Q))
	{
		Q->front->next = pt->next;
		delete pt;
		Q->length--;
		pt = Q->front->next;
	}
	puts("队列已清空");
}
//遍历函数操作
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q,int type),int type)
{
	if (IsEmptyLQueue(Q))
	{
		puts("队列为空");
		return FALSE;
	}
	Node* pt = Q->front->next;
	while (pt)
	{
		foo(pt->data,type);
		pt = pt->next;
	}
	return TRUE;
}
//操作函数
void LPrint(void* ptr,int type)
{
	s_printf(ptr, type);
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