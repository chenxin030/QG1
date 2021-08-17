#include"menu.h"
#include<stdio.h>
#pragma warning(disable:4996)
int menu()
{
	int i;
	while (1)
	{
		puts("请选择功能");
		puts("1)初始化队列");
		puts("2)销毁队列");
		puts("3)检查队列是否已满");
		puts("4)检查队列是否为空");
		puts("5)查看队头");
		puts("6)查看队列长度");
		puts("7)入队");
		puts("8)出队");
		puts("9)清空队列");
		puts("10)遍历函数操作");
		puts("11)退出系统");
		s_scanf(&i);
		if (i > 11 || i < 1)
		{
			puts("输入错误，请重新输入");
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
		puts("请输入你想要输入的类型");
		puts("1)int类型");
		puts("2)double类型");
		puts("3)char类型");
		s_scanf(&i);
		if (i > 3 || i < 1)
		{
			puts("输入错误，请重新输入");
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
		puts("请选择你想要进行的操作");
		puts("1)输出各元素");
		//puts("2)");
		//puts("3)");
		//puts("4)");
		s_scanf(&c);
		if (c < 1 || c > 4)
			printf("输入错误，请重新输入:");
		else
			break;
	}
	return c;
}
void s_scanf(int* iptr)
{
	while (scanf("%d", iptr) != 1)
	{
		puts("非法输入，请重新输入");
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
			puts("非法输入，请重新输入");
			while (getchar() != '\n')
				continue;
		}
		break;
	case 2:
		while (scanf("%lf", (double*)ptr) != 1)
		{
			puts("非法输入，请重新输入");
			while (getchar() != '\n')
				continue;
		}
		break;
	case 3:
		while (scanf("%c", (char*)ptr) != 1)
		{
			puts("非法输入，请重新输入");
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