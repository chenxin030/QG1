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
				std::cout << "ջ�ǿյ�" << std::endl;
			else
				std::cout << "ջ��������" << std::endl;
			break;
		case 2:
			if (s.isFullStack())
				std::cout << "ջ�Ѿ�����" << std::endl;
			else
				std::cout << "ջ��δ��" << std::endl;
			break;
		case 3:
			if (!s.isEmptyLStack())
				std::cout << s.getTopLStack() << std::endl;
			else
				std::cout << "û������" << std::endl;
			break;
		case 4:
			if (s.clearLStack())
				std::cout << "�����ջ" << std::endl;
			break;
		case 5:
			std::cout << "ջ�ĳ���Ϊ��" << s.LStackLength() << std::endl;
			break;
		case 6:
			if (s.isFullStack())
				std::cout << "ջ�Ŀռ��������޷�����" << std::endl;
			else
			{
				int data;
				std::cout << "����������(int����)��" << std::endl;
				bool b = true;
				std::cin >> data;
				while (b)
				{
					if (!std::cin)
					{
						while (getchar() != '\n');
						std::cout << "�����������������: " << std::endl;
						std::cin.clear();
						std::cin.sync();
					}
					else if (getchar() != '\n')
					{
						while (getchar() != '\n');
						std::cout << "�����������������" << std::endl;
					}
					else
						b = false;
					if (b)
						std::cin >> data;
				}
				if (s.pushLStack(data))
					std::cout << "����ɹ�" << std::endl;
				else
					std::cout << "����ʧ��" << std::endl;
			}
			break;
		case 7:
			if (!s.isEmptyLStack())
				std::cout << s.popLStack() << std::endl;
			else
				std::cout << "û������" << std::endl;
			break;
		case 8:
			if (s.isEmptyLStack())
				std::cout << "ջ��û������" << std::endl;
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