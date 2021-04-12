#include"menu.h"
#include"LQueue.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//��ʼ������
void InitLQueue(LQueue* Q)
{
	Q->front = Q->rear = new Node;
	Q->front->next = Q->rear = NULL;
	Q->length = 0;
	puts("�����ѳ�ʼ��\n");
}
// ���ٶ���
void DestoryLQueue(LQueue* Q)
{
	if (Q->front)
	{
		ClearLQueue(Q);
		delete(Q->front);
		delete(Q->rear);
		Q->rear = Q->front = NULL;
		puts("����������\n");
	}
	
}
//�������Ƿ�Ϊ��
Status IsEmptyLQueue(const LQueue* Q)
{
	if (Q->length == 0)
	{
		return TRUE;
	}
	return FALSE;
}
//�������Ƿ�����
Status IsFullLQueue(const LQueue* Q)
{
	if (Q->length == MAX)
		return TRUE;
	else
		return FALSE;
}
//�鿴��ͷԪ��
Status GetHeadLQueue(LQueue* Q,void* e,int type)
{
	if (IsEmptyLQueue(Q))
	{
		puts("����Ϊ��,û��ͷԪ��");
		return FALSE;
	}
	datacpy(e, Q->front->next->data , type);
	return TRUE;
}
//ȷ�����г���
int LengthLQueue(LQueue* Q)
{
	return Q->length;
}
//��Ӳ���
Status EnLQueue(LQueue* Q,void* data,int type)
{
	if (Q->length == MAX)
	{
		puts("�����������޷����");
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
//���Ӳ���
Status DeLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
	{
		puts("����Ϊ�գ��޷�����");
		return FALSE;
	}
	Node* pt = Q->front->next;
	Q->front->next = pt->next;
	delete pt;
	Q->length--;
	return TRUE;
}
//��ն���
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
	puts("���������");
}
//������������
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q,int type),int type)
{
	if (IsEmptyLQueue(Q))
	{
		puts("����Ϊ��");
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
//��������
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