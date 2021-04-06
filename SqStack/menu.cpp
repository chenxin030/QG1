#include"menu.h"
#include<iostream>
#include<limits>
#include<ios>
int menu()
{
	int c;
	do
	{
		puts("\n请选择功能");
		puts("1 )判断栈是否为空");
		puts("2 )判断栈是否已满");
		puts("3 )得到栈顶元素");
		puts("4 )清空栈");
		puts("5 )检测栈长度");
		puts("6 )入栈");
		puts("7 )出栈");
		puts("8 )全部出栈");
		puts("9 )退出使用");
		std::cin >> c;
		if (!std::cin || c > 10 || c < 1)
		{
			while (getchar() != '\n');
			std::cin.clear();
			std::cin.sync();
			std::cout << "输入错误，请重新输入" << std::endl;
		}
		else
		{
			if (getchar() != '\n')
			{
				while (getchar() != '\n');
				std::cout << "输入错误，请重新输入" << std::endl;
			}
			else
				return c;
		}
	} while (1);
}