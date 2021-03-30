#include"qgforwardlist.h"
#include"menu.h"
#include<iostream>
using namespace std;
int main()
{
	int b = 1;
	QGList* list = new QGList;
	while (b)
	{
		switch (menu())
		{
		case 1:
			if (list->ListIsEmpty())
				cout << "链表为空" << endl;
			else
				cout << "链表存有数据" << endl;
			break;
		case 2:
			if (!list->ListIsFull())
				cout << "链表未满" << endl;
			break;
		case 3:
			if (!list->SearchNode(1))
			{
				cout << "没有该节点" << endl;
				break;
			}
			cout << list->front() << endl;
			break;
		case 4:
			if (!list->SearchNode(1))
			{
				cout << "没有该节点" << endl;
				break;
			}
			cout << list->back() << endl;
			break;
		case 5:
			if (list->push_front(list->Add()))
				cout << "添加成功" << endl;
			else
				cout << "添加失败" << endl;
			break;
		case 6:
			if (list->pop_front())
				cout << "删除成功" << endl;
			else
				cout << "删除失败" << endl;
			break;
		case 7:
			if (list->push_back(list->Add()))
				cout << "添加成功" << endl;
			else
				cout << "添加失败" << endl;
			break;
		case 8:
			if (list->pop_back())
				cout << "删除成功" << endl;
			else
				cout << "删除失败" << endl;
			break;
		case 9:
			unsigned int ch;
			cout << "该节点序号为" << endl;
			cin >> ch;
			if (list->SearchNode(ch))
				cout << list->SearchNode(ch)->data << endl;
			else
				cout << "查找失败" << endl;
			getchar();
			break;
		case 10:
			int index;
			cout << "若要在第1个位置插入，请输入0，以此类推" << endl;
			cin >> index;
			getchar();
			if (list->insert(index, list->Add()))
				cout << "插入成功" << endl;
			else
				cout << "插入失败" << endl;
			break;
		case 11:
			int index2;
			cout << "请输入要删除的位置" << endl;
			cin >> index2;
			if (list->erase(index2))
			{
				cout << "删除成功" << endl;
				getchar();
			}
			else
				cout << "删除失败" << endl;
			break;
		case 12:
			if (list->clear())
				cout << "清空成功" << endl;
			break;
		case 13:
			cout << "请选择要进行的操作" << endl;
			break;
		case 14:
			b = 0;
			break;
		}
	}
}