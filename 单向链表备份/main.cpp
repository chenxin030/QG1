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
				cout << "����Ϊ��" << endl;
			else
				cout << "�����������" << endl;
			break;
		case 2:
			if (!list->ListIsFull())
				cout << "����δ��" << endl;
			break;
		case 3:
			if (!list->SearchNode(1))
			{
				cout << "û�иýڵ�" << endl;
				break;
			}
			cout << list->front() << endl;
			break;
		case 4:
			if (!list->SearchNode(1))
			{
				cout << "û�иýڵ�" << endl;
				break;
			}
			cout << list->back() << endl;
			break;
		case 5:
			if (list->push_front(list->Add()))
				cout << "��ӳɹ�" << endl;
			else
				cout << "���ʧ��" << endl;
			break;
		case 6:
			if (list->pop_front())
				cout << "ɾ���ɹ�" << endl;
			else
				cout << "ɾ��ʧ��" << endl;
			break;
		case 7:
			if (list->push_back(list->Add()))
				cout << "��ӳɹ�" << endl;
			else
				cout << "���ʧ��" << endl;
			break;
		case 8:
			if (list->pop_back())
				cout << "ɾ���ɹ�" << endl;
			else
				cout << "ɾ��ʧ��" << endl;
			break;
		case 9:
			unsigned int ch;
			cout << "�ýڵ����Ϊ" << endl;
			cin >> ch;
			if (list->SearchNode(ch))
				cout << list->SearchNode(ch)->data << endl;
			else
				cout << "����ʧ��" << endl;
			getchar();
			break;
		case 10:
			int index;
			cout << "��Ҫ�ڵ�1��λ�ò��룬������0���Դ�����" << endl;
			cin >> index;
			getchar();
			if (list->insert(index, list->Add()))
				cout << "����ɹ�" << endl;
			else
				cout << "����ʧ��" << endl;
			break;
		case 11:
			int index2;
			cout << "������Ҫɾ����λ��" << endl;
			cin >> index2;
			if (list->erase(index2))
			{
				cout << "ɾ���ɹ�" << endl;
				getchar();
			}
			else
				cout << "ɾ��ʧ��" << endl;
			break;
		case 12:
			if (list->clear())
				cout << "��ճɹ�" << endl;
			break;
		case 13:
			cout << "��ѡ��Ҫ���еĲ���" << endl;
			break;
		case 14:
			b = 0;
			break;
		}
	}
}