#include "qglist.h"
#include<iostream>
using namespace std;
/*
	 * 初始化链表
	 */
QGList::QGList()
{
	List.head = List.tail = NULL;
	List.size = 0;
	cout << "已创建链表(无节点)" << endl;
}

/*
 * 销毁链表
 */
QGList::~QGList()
{
	if (ListIsEmpty())
	{
		cout << "链表已销毁" << endl;
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
		cout << "链表已空" << endl;
	}
	cout << "已销毁链表" << endl;
}

//判断是否为空链表
bool QGList::ListIsEmpty()
{
	if (List.head == NULL)
	{
		return true;
	}
	return false;
}

//判断链表是否已满 
bool QGList::ListIsFull()
{
	Node* pt = new Node;
	if (pt)
		return false;
	else
	{
		cout << "空间已满" << endl;
		return true;
	}
	delete pt;
	pt = NULL;
}
/*
 * 返回链表中第一个元素的引用
 */
QGList::ElemType& QGList::front()
{
	if (List.head)
		return  List.head->data;
}

/*
 * 返回链表中最后一个元素的引用
 */
QGList::ElemType& QGList::back()
{
	if (List.tail)
		return List.tail->data;
}

/*
* 添加节点内容
*/
QGList::ElemType& QGList::Add()
{
	ElemType nnew = 0;
	cout << "请输入int类型数字(五位数以内)：" << endl;
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
			cout << "输入错误，请重新输入" << endl;
		}
	}
	return nnew;
}

/*
 * 在链表第一个元素前添加元素e
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
 * 删除链表第一个元素
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
 * 在链表最后一个元素后添加元素e
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
 * 删除链表最后一个元素
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

//查找节点
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
 * 在链表的第index + 1个元素前插入元素e
 */
bool QGList::insert(unsigned int index, ElemType e)
{
	if (ListIsFull())
		return false;
	if (index + 1 > List.size)
	{
		if (List.size == 0)
		{
			cout << "链表中没有节点，请输入5或7添加节点" << endl;
		}
		else
		{
			cout << "没有这么多节点,共有" << List.size << "个节点" << endl;
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
 * 删除任意位置元素
 */
bool QGList::erase(unsigned int index)
{
	if (ListIsEmpty())
	{
		cout << "链表为空，无法删除" << endl;
		return false;
	}
	if (index > List.size)
	{
		cout << "没有这么多节点，无法删除,共有" << List.size << "个节点" << endl;
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
 * 清空链表
 */
bool QGList::clear()
{
	if (ListIsEmpty())
	{
		cout << "链表已空" << endl;
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
		cout << "链表已清空" << endl;
		return true;
	}
}

/*
 * 查找元素是否存在
 */
bool QGList::contain(ElemType& e)
{
	if (ListIsEmpty())
	{
		cout << "链表为空，无法查找" << endl;
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
		cout << "该节点存在" << endl;
		return true;
	}
	else
	{
		cout << "该节点不存在" << endl;
		return false;
	}
}

/*
 * 返回链表中元素的数量
 */
unsigned int QGList::size()
{
	return List.size;
}

/*
 * 遍历链表, 对每个元素调用visit指向的函数
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