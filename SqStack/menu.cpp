#include"menu.h"
#include<iostream>
#include<limits>
#include<ios>
int menu()
{
	int c;
	do
	{
		puts("\n��ѡ����");
		puts("1 )�ж�ջ�Ƿ�Ϊ��");
		puts("2 )�ж�ջ�Ƿ�����");
		puts("3 )�õ�ջ��Ԫ��");
		puts("4 )���ջ");
		puts("5 )���ջ����");
		puts("6 )��ջ");
		puts("7 )��ջ");
		puts("8 )ȫ����ջ");
		puts("9 )�˳�ʹ��");
		std::cin >> c;
		if (!std::cin || c > 10 || c < 1)
		{
			while (getchar() != '\n');
			std::cin.clear();
			std::cin.sync();
			std::cout << "�����������������" << std::endl;
		}
		else
		{
			if (getchar() != '\n')
			{
				while (getchar() != '\n');
				std::cout << "�����������������" << std::endl;
			}
			else
				return c;
		}
	} while (1);
}