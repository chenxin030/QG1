#include "menu.h"
#include <cstdio>
#include <iostream>
using namespace std;
int menu()
{
	char a, b;
	do
	{
		puts("\n��ѡ����");
		puts("1 )�鿴�Ƿ�Ϊ������");
		puts("2 )�鿴�����Ƿ�����");
		puts("3 )���������е�һ��Ԫ��");
		puts("4 )�������������һ��Ԫ��");
		puts("5 )�������һ��Ԫ��ǰ���Ԫ��");
		puts("6 )ɾ�������һ��Ԫ��");
		puts("7 )���������һ��Ԫ�غ����Ԫ��");
		puts("8 )ɾ���������һ��Ԫ��");
		puts("9 )���ҽڵ�");
		puts("10)�������ĳ��λ�ò���Ԫ��");
		puts("11)ɾ������λ��Ԫ��");
		puts("12)�������");
		puts("13)��������, ��ÿ��Ԫ�ص���visitָ��ĺ���");
		puts("14)�˳�ʹ��");
		a = getchar();
		if (a == '\n')
		{
			puts("���벻���Ϲ淶������������");
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
		puts("���벻���Ϲ淶������������");
		while (getchar() != '\n')
			continue;
	} while (1);
}
int menu2()
{
	int i = 0;
	do
	{
		puts("\n��ѡ����");
		puts("1 )���ÿ���ڵ�����");
		if (i < 0 && i>1)
			puts("���벻���Ϲ淶������������");
	} while (i < 0 && i>1);
	return i;
}