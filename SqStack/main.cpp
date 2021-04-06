#include<iostream>
#include"SqStack.h"
#include"menu.h"
int main()
{
	bool b = true;
	SqStack<int> s;
	while (b)
	{
		switch (menu())
		{
		case 1:
			if (s.isEmptyLStack())
				std::cout << "栈是空的" << std::endl;
			else
				std::cout << "栈里有数据" << std::endl;
			break;
		case 2:
			if (s.isFullStack())
				std::cout << "栈已经满了" << std::endl;
			else
				std::cout << "栈还未满" << std::endl;
			break;
		case 3:
			if (!s.isEmptyLStack())
				std::cout << s.getTopLStack() << std::endl;
			else
				std::cout << "没有数据" << std::endl;
			break;
		case 4:
			if (s.clearLStack())
				std::cout << "已清空栈" << std::endl;
			break;
		case 5:
			std::cout << "栈的长度为：" << s.LStackLength() << std::endl;
			break;
		case 6:
			if (s.isFullStack())
				std::cout << "栈的空间已满，无法输入" << std::endl;
			else
			{
				int data;
				std::cout << "请输入数字(int类型)：" << std::endl;
				bool b = true;
				std::cin >> data;
				while (b)
				{
					if (!std::cin)
					{
						while (getchar() != '\n');
						std::cout << "输入错误，请重新输入: " << std::endl;
						std::cin.clear();
						std::cin.sync();
					}
					else if (getchar() != '\n')
					{
						while (getchar() != '\n');
						std::cout << "输入错误，请重新输入" << std::endl;
					}
					else
						b = false;
					if (b)
						std::cin >> data;
				}
				if (s.pushLStack(data))
					std::cout << "输入成功" << std::endl;
				else
					std::cout << "输入失败" << std::endl;
			}
			break;
		case 7:
			if (!s.isEmptyLStack())
				std::cout << s.popLStack() << std::endl;
			else
				std::cout << "没有数据" << std::endl;
			break;
		case 8:
			if (s.isEmptyLStack())
				std::cout << "栈内没有数据" << std::endl;
			else
				while (!s.isEmptyLStack())
				{
					std::cout << s.popLStack() << std::endl;
				}
			break;
		case 9:
			b = false;
			break;
		}
	}
}