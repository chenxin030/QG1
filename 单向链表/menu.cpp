#include "menu.h"
#include <cstdio>
#include <iostream>
using namespace std;
int menu()
{
	char a, b;
	do
	{
		puts("\n请选择功能");
		puts("1 )查看是否为空链表");
		puts("2 )查看链表是否已满");
		puts("3 )返回链表中第一个元素");
		puts("4 )返回链表中最后一个元素");
		puts("5 )在链表第一个元素前添加元素");
		puts("6 )删除链表第一个元素");
		puts("7 )在链表最后一个元素后添加元素");
		puts("8 )删除链表最后一个元素");
		puts("9 )查找节点");
		puts("10)在链表的某个位置插入元素");
		puts("11)删除任意位置元素");
		puts("12)清空链表");
		puts("13)遍历链表, 对每个元素调用visit指向的函数");
		puts("14)退出使用");
		a = getchar();
		if (a == '\n')
		{
			puts("输入不符合规范，请重新输入");
			continue;
		}
		b = getchar();
		if (b == '\n' && a > '0' && a <= '9')
		{
			return a - '0';
		}
		if ((getchar()) == '\n' && a == '1' && b >= '0' && b <= '4')
		{
			return (a - '0') * 10 + b - '0';
		}
		puts("输入不符合规范，请重新输入");
		while (getchar() != '\n')
			continue;
	} while (1);
}
int menu2()
{
	int i = 0;
	do
	{
		puts("\n请选择功能");
		puts("1 )输出每个节点内容");
		if (i < 0 && i>1)
			puts("输入不符合规范，请重新输入");
	} while (i < 0 && i>1);
	return i;
}