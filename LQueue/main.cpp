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
				puts("队列未初始化\n");
			else
				DestoryLQueue(Q);
			break;
		case 3:
			if (!Q->front)
				puts("队列未初始化\n");
			else if (IsFullLQueue(Q))
				puts("队列已满\n");
			else
				puts("队列未满\n");
			break;
		case 4:
			if (!Q->front)
				puts("队列未初始化\n");
			else if (IsEmptyLQueue(Q))
				puts("队列为空\n");
			else
				puts("队列内有元素\n");
			break;
		case 5:
			if (!Q->front)
				puts("队列未初始化\n");
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
				puts("队列未初始化\n");
			else
				printf("队列的长度为：%d\n\n", LengthLQueue(Q));
			break;
		case 7:
			if (!Q->front)
				puts("队列未初始化\n");
			else
			{
				printf("请输入想入队的数据 :");
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
				puts("入队成功\n");
			}
			break;
		case 8:
			if (!Q->front)
				puts("队列未初始化\n");
			else if (DeLQueue(Q))
				puts("出队成功\n");
			else
				puts("出队失败\n");
			break;
		case 9:
			if (!Q->front)
				puts("队列未初始化\n");
			else
				ClearLQueue(Q);
			puts("");
			break;
		case 10:
			if (!Q->front)
				puts("队列未初始化\n");
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