#include "qglist.h"
#include<iostream>
using namespace std;
/*
	 * ��ʼ������
	 */
QGList::QGList()
{
	List.head = List.tail = NULL;
	List.size = 0;
	cout << "�Ѵ�������(�޽ڵ�)" << endl;
}

/*
 * ��������
 */
QGList::~QGList()
{
	if (ListIsEmpty())
	{
		cout << "����������" << endl;
	}
	Node* pt = new Node;
	while (List.head)
	{
		pt = List.head;
		List.head = List.head->next;
		delete pt;
	}
	pt = List.head = List.tail = NULL;
	List.size = 0;
	if (ListIsEmpty())
	{
		cout << "�����ѿ�" << endl;
	}
	cout << "����������" << endl;
}

//�ж��Ƿ�Ϊ������
bool QGList::ListIsEmpty()
{
	if (List.head == NULL)
	{
		return true;
	}
	return false;
}

//�ж������Ƿ����� 
bool QGList::ListIsFull()
{
	Node* pt = new Node;
	if (pt)
		return false;
	else
	{
		cout << "�ռ�����" << endl;
		return true;
	}
	delete pt;
	pt = NULL;
}
/*
 * ���������е�һ��Ԫ�ص�����
 */
QGList::ElemType& QGList::front()
{
	if (List.head)
		return  List.head->data;
}

/*
 * �������������һ��Ԫ�ص�����
 */
QGList::ElemType& QGList::back()
{
	if (List.tail)
		return List.tail->data;
}

/*
* ��ӽڵ�����
*/
QGList::ElemType& QGList::Add()
{
	ElemType nnew = 0;
	cout << "������int��������(��λ������)��" << endl;
	int time = 0;
	bool input = false;
	char ch;
	while (!input)
	{
		time = 0;
		while ((ch = getchar()) != '\n')
		{
			time++;
			nnew *= 10;
			nnew += ch - '0';
		}
		if (time < 6 && ch == '\n')
		{
			input = true;
		}
		else
		{
			cout << "�����������������" << endl;
		}
	}
	return nnew;
}

/*
 * �������һ��Ԫ��ǰ���Ԫ��e
 */
bool QGList::push_front(ElemType e)
{
	if (ListIsFull())
		return false;
	Node* pnew = new Node;
	pnew->data = e;
	if (!List.head)
	{
		List.head = pnew;
		List.head->next = NULL;
		List.head->prior = NULL;
		List.tail = List.head;
		List.size++;
		return true;
	}
	pnew->next = List.head;
	pnew->prior = NULL;
	List.head->prior = pnew;
	List.head = pnew;
	List.size++;
	return true;
}

/*
 * ɾ�������һ��Ԫ��
 */
bool QGList::pop_front()
{
	Node* pt = new Node;
	if (ListIsEmpty())
		return false;
	pt = List.head;
	List.head = List.head->next;
	if(List.head)
		List.head->prior = NULL;
	delete pt;
	List.size--;
	if (List.size == 0)
		List.tail = NULL;
	pt = NULL;
	return true;
}

/*
 * ���������һ��Ԫ�غ����Ԫ��e
 */
bool QGList::push_back(ElemType e)
{
	if (ListIsFull())
		return false;
	Node* pnew = new Node;
	pnew->data = e;
	pnew->next = NULL;
	if (ListIsEmpty())
		List.head = pnew;
	else
		List.tail->next = pnew;
	pnew->prior = List.tail;
	List.tail = pnew;
	List.size++;
	return true;
}

/*
 * ɾ���������һ��Ԫ��
 */
bool QGList::pop_back()
{
	Node* pt = new Node;
	if (ListIsEmpty())
		return false;
	pt = List.tail->prior;
	if (List.head == List.tail)
	{
		List.head = List.tail = NULL;
		delete pt;
		List.size--;
		return true;
	}
	List.tail = pt;
	pt = List.tail->next;
	delete pt;
	pt = NULL;
	List.size--;
	return true;
}

//���ҽڵ�
QGList::Node* QGList::SearchNode(unsigned int index)
{
	unsigned int i = 1;
	Node* pt;
	pt = List.head;
	while (pt && i < index)
	{
		pt = pt->next;
		i++;
	}
	if (i == index)
		return pt;
	else
		return NULL;
	pt = NULL;
}

/*
 * ������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
 */
bool QGList::insert(unsigned int index, ElemType e)
{
	if (ListIsFull())
		return false;
	if (index + 1 > List.size)
	{
		if (List.size == 0)
		{
			cout << "������û�нڵ㣬������5��7��ӽڵ�" << endl;
		}
		else
		{
			cout << "û����ô��ڵ�,����" << List.size << "���ڵ�" << endl;
		}
		return false;
	}
	Node* pnew = new Node;
	pnew->data = e;
	if (index == 0)
	{
		push_front(e);
	}
	else if (index == List.size)
	{
		push_back(e);
	}
	else
	{
		Node* pt = SearchNode(index);
		pnew->next = pt->next;
		pt->next = pnew;
		pnew->prior = pt;
		pt->next->prior = pt;
	}
	List.size++;
	return true;
}

/*
 * ɾ������λ��Ԫ��
 */
bool QGList::erase(unsigned int index)
{
	if (ListIsEmpty())
	{
		cout << "����Ϊ�գ��޷�ɾ��" << endl;
		return false;
	}
	if (index > List.size)
	{
		cout << "û����ô��ڵ㣬�޷�ɾ��,����" << List.size << "���ڵ�" << endl;
		getchar();
		return false;
	}
	if (index == 1)
	{
		Node* pt;
		pt = List.head;
		List.head = List.tail = NULL;
		delete pt;
		List.size--;
		return true;
	}
	Node* pt;
	if (index == List.size)
	{
		pt = List.tail->prior;
		List.tail = pt;
	}
	else
	{
		pt = SearchNode(index - 1);
		if (!pt)
		{
			delete pt;
			pt = NULL;
			return false;
		}

	}
	Node* pt2 = pt->next;
	pt->next = pt2->next;
	if(pt2->next)
		pt2->next->prior = pt;
	delete pt2;
	pt2 = NULL;
	List.size--;
	return true;
}

/*
 * �������
 */
bool QGList::clear()
{
	if (ListIsEmpty())
	{
		cout << "�����ѿ�" << endl;
		return true;
	}
	Node* pt = List.head;
	while (List.head)
	{
		pt = List.head;
		List.head = List.head->next;
		delete pt;
	}
	List.tail = List.head = NULL;
	List.size = 0;
	if (ListIsEmpty())
	{
		cout << "���������" << endl;
		return true;
	}
}

/*
 * ����Ԫ���Ƿ����
 */
bool QGList::contain(ElemType& e)
{
	if (ListIsEmpty())
	{
		cout << "����Ϊ�գ��޷�����" << endl;
		return false;
	}
	Node* pt;
	pt = List.head;
	while (pt && pt->data != e)
	{
		pt = pt->next;
	}
	if (pt && pt->data == e)
	{
		cout << "�ýڵ����" << endl;
		return true;
	}
	else
	{
		cout << "�ýڵ㲻����" << endl;
		return false;
	}
}

/*
 * ����������Ԫ�ص�����
 */
unsigned int QGList::size()
{
	return List.size;
}

/*
 * ��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
 */
bool QGList::traverse(void (*visit)(ElemType& e))
{
	Node* pnode;
	pnode = List.head;
	while (pnode)
	{
		(*visit)(pnode->data);
		pnode = pnode->next;
	}
	return true;
}