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
				puts("û�ж���\n");
			break;
		case 3:
			if (Q->b)
			{
				if (IsFullAQueue(Q))
					puts("��������\n");
				else
					puts("����δ��\n");
			}
			else
				puts("û�ж���\n");
			break;
		case 4:
			if (Q->b)
			{
				if (IsEmptyAQueue(Q))
					puts("����Ϊ��\n");
				else
					puts("��������Ԫ��\n");
			}
			else
				puts("û�ж���\n");
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
				printf("���еĳ���Ϊ��%d\n", LengthAQueue(Q));
			else
				puts("û�ж���\n");
			puts("");
			break;
		case 7:
			if (!Q->b)
			{
				puts("û�ж���\n");
			}
			else
			{
				puts("����������ӵ����� :");
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
				puts("��ӳɹ�\n");
			}
			break;
		case 8:
			if (DeAQueue(Q))
				puts("���ӳɹ�\n");
			else
				puts("����ʧ��\n");
			break;
		case 9:
			ClearAQueue(Q);
			break;
		case 10:
			if (!Q->b)
			{
				puts("û�ж���\n");
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