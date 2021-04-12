#include"AQueue.h"
#include"menu.h"
#include<iostream>
int main()
{
	int b = 1;
	AQueue* Q = new AQueue;
	Q->b = 0;
	int type = menu2();
	while (b)
	{
		void* geti = (int*)malloc(sizeof(int));
		void* getd = (double*)malloc(sizeof(double));
		void* getc = (char*)malloc(sizeof(char));
		void* ptri = (int*)malloc(sizeof(int));
		void* ptrd = (double*)malloc(sizeof(double));
		void* ptrc = (char*)malloc(sizeof(char));
		void (*pfun)(void* q,int type);
		switch (menu())
		{
		case 1:
			InitAQueue(Q,type);
			break;
		case 2:
			if (Q->b)
				DestoryAQueue(Q);
			else
				puts("没有队列\n");
			break;
		case 3:
			if (Q->b)
			{
				if (IsFullAQueue(Q))
					puts("队列已满\n");
				else
					puts("队列未满\n");
			}
			else
				puts("没有队列\n");
			break;
		case 4:
			if (Q->b)
			{
				if (IsEmptyAQueue(Q))
					puts("队列为空\n");
				else
					puts("队列内有元素\n");
			}
			else
				puts("没有队列\n");
			break;
		case 5:
			switch (type)
			{
			case 1:
				if (GetHeadAQueue(Q, geti, type))
					s_printf(geti, type);
				break;
			case 2:
				if (GetHeadAQueue(Q, getd, type))
					s_printf(getd, type);
				break;
			case 3:
				if (GetHeadAQueue(Q, getc, type))
					s_printf(getc, type);
				break;
			}
			puts("\n");
			break;
		case 6:
			if (Q->b)
				printf("队列的长度为：%d\n", LengthAQueue(Q));
			else
				puts("没有队列\n");
			puts("");
			break;
		case 7:
			if (!Q->b)
			{
				puts("没有队列\n");
			}
			else
			{
				puts("请输入想入队的数据 :");
				switch (type)
				{
				case 1:
					ss_scanf(ptri, type);
					EnAQueue(Q, ptri, type);
					break;
				case 2:
					ss_scanf(ptrd, type);
					EnAQueue(Q, ptrd, type);
					break;
				case 3:
					ss_scanf(ptrc, type);
					EnAQueue(Q, ptrc, type);
					break;
				}
				puts("入队成功\n");
			}
			break;
		case 8:
			if (DeAQueue(Q))
				puts("出队成功\n");
			else
				puts("出队失败\n");
			break;
		case 9:
			ClearAQueue(Q);
			break;
		case 10:
			if (!Q->b)
			{
				puts("没有队列\n");
			}
			else
			{
				switch (menu3())
				{
				case 1:
					pfun = APrint;
					TraverseAQueue(Q, pfun, type);
					break;
				case 2:

					break;
				}
			}
			puts("");
			break;
		case 11:
			b = 0;
			break;
		}
	}
}