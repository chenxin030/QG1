#include"menu.h"
#include<stdio.h>
#pragma warning(disable:4996)
int menu()
{
	int i;
	while (1)
	{
		puts("��ѡ����");
		puts("1)��ʼ������");
		puts("2)���ٶ���");
		puts("3)�������Ƿ�����");
		puts("4)�������Ƿ�Ϊ��");
		puts("5)�鿴��ͷ");
		puts("6)�鿴���г���");
		puts("7)���");
		puts("8)����");
		puts("9)��ն���");
		puts("10)������������");
		puts("11)�˳�ϵͳ");
		s_scanf(&i);
		if (i > 11 || i < 1)
		{
			puts("�����������������");
		}
		else
			break;
	}
	return i;
}
int menu2()
{
	int i;
	while (1)
	{
		puts("����������Ҫ���������");
		puts("1)int����");
		puts("2)double����");
		puts("3)char����");
		s_scanf(&i);
		if (i > 3 || i < 1)
		{
			puts("�����������������");
		}
		else
			break;
	}
	return i;
}
int menu3()
{
	int c;
	while (1)
	{
		puts("��ѡ������Ҫ���еĲ���");
		puts("1)�����Ԫ��");
		//puts("2)");
		//puts("3)");
		//puts("4)");
		s_scanf(&c);
		if (c < 1 || c > 4)
			printf("�����������������:");
		else
			break;
	}
	return c;
}
void s_scanf(int* iptr)
{
	while (scanf("%d", iptr) != 1)
	{
		puts("�Ƿ����룬����������");
		while (getchar() != '\n')
			continue;
	}
	getchar();
}
void ss_scanf(void* ptr, int datatype)
{
	switch (datatype)
	{
	case 1:
		while (scanf("%d", (int*)ptr) != 1)
		{
			puts("�Ƿ����룬����������");
			while (getchar() != '\n')
				continue;
		}
		break;
	case 2:
		while (scanf("%lf", (double*)ptr) != 1)
		{
			puts("�Ƿ����룬����������");
			while (getchar() != '\n')
				continue;
		}
		break;
	case 3:
		while (scanf("%c", (char*)ptr) != 1)
		{
			puts("�Ƿ����룬����������");
			while (getchar() != '\n')
				continue;
		}
		break;
	default:
		break;
	}
}
void s_printf(void* ptr, int type)
{
	switch (type)
	{
	case 1:
		printf("%d", *(int*)ptr);
		break;
	case 2:
		printf("%lf", *(double*)ptr);
		break;
	case 3:
		printf("%c", *(char*)ptr);
		break;
	}
}