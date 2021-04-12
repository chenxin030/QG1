#include"LQueue.h"
#include"menu.h"
#include<stdio.h>
#include<iostream>
int main()
{
	int type;
	type = menu2();
	int b = 1;
	LQueue* Q = new LQueue;
	Q->rear = Q->front = NULL;
	while (b)
	{
		void* geti = (int*)malloc(sizeof(int));
		void* getd = (double*)malloc(sizeof(double));
		void* getc = (char*)malloc(sizeof(char));
		void* ptri = (int*)malloc(sizeof(int));
		void* ptrd = (double*)malloc(sizeof(double));
		void* ptrc = (char*)malloc(sizeof(char));
		void (*pfun)(void* ptr,int type);
		switch (menu())
		{
		case 1:
			InitLQueue(Q);
			break;
		case 2:
			if (!Q->front)
				puts("����δ��ʼ��\n");
			else
				DestoryLQueue(Q);
			break;
		case 3:
			if (!Q->front)
				puts("����δ��ʼ��\n");
			else if (IsFullLQueue(Q))
				puts("��������\n");
			else
				puts("����δ��\n");
			break;
		case 4:
			if (!Q->front)
				puts("����δ��ʼ��\n");
			else if (IsEmptyLQueue(Q))
				puts("����Ϊ��\n");
			else
				puts("��������Ԫ��\n");
			break;
		case 5:
			if (!Q->front)
				puts("����δ��ʼ��\n");
			else
			{
				switch (type)
				{
				case 1:
					if (GetHeadLQueue(Q, geti, type))
						s_printf(geti, type);
					break;
				case 2:
					if (GetHeadLQueue(Q, getd, type))
						s_printf(getd, type);
					break;
				case 3:
					if (GetHeadLQueue(Q, getc, type))
						s_printf(getc, type);
					break;
				}
			}
			puts("\n");
			break;
		case 6:
			if (!Q->front)
				puts("����δ��ʼ��\n");
			else
				printf("���еĳ���Ϊ��%d\n\n", LengthLQueue(Q));
			break;
		case 7:
			if (!Q->front)
				puts("����δ��ʼ��\n");
			else
			{
				printf("����������ӵ����� :");
				switch (type)
				{
				case 1:
					ss_scanf(ptri, type);
					EnLQueue(Q, ptri, type);
					break;
				case 2:
					ss_scanf(ptrd, type);
					EnLQueue(Q, ptrd, type);
					break;
				case 3:
					ss_scanf(ptrc, type);
					EnLQueue(Q, ptrc, type);
					break;
				}
				puts("��ӳɹ�\n");
			}
			break;
		case 8:
			if (!Q->front)
				puts("����δ��ʼ��\n");
			else if (DeLQueue(Q))
				puts("���ӳɹ�\n");
			else
				puts("����ʧ��\n");
			break;
		case 9:
			if (!Q->front)
				puts("����δ��ʼ��\n");
			else
				ClearLQueue(Q);
			puts("");
			break;
		case 10:
			if (!Q->front)
				puts("����δ��ʼ��\n");
			else
				switch (menu3())
				{
				case 1:
					pfun = LPrint;
					TraverseLQueue(Q, pfun,type);
					break;
				case 2:

					break;
				}
			puts("\n");
				break;
		case 11:
			b = 0;
			break;
		}
	}
}