#ifndef STACK_H
#define STACK_H
template <typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node<T>* prev;
};
template <typename T>
class Stack
{
public:
	Stack();
	~Stack();
	bool isEmptyLStack();//�ж�ջ�Ƿ�Ϊ��
	bool isFullStack();//�ж�ջ�Ƿ�����
	T getTopLStack();//�õ�ջ��Ԫ��
	bool clearLStack();//���ջ
	int LStackLength();//���ջ����
	bool pushLStack(T data);//��ջ
	T popLStack();//��ջ
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
};
template <typename T>
Stack<T>::Stack()
{
	head = new Node<T>;
	head->next = tail = nullptr;
	size = 0;
}
template <typename T>
Stack<T>::~Stack()
{
	Node<T>* pt = nullptr;
	if(head->next)
		 pt = head->next;
	while (pt)
	{
		head = pt->next;
		delete pt;
		if(head&&head->next)
			pt = head->next;
	}
}
template <typename T>
bool Stack<T>::isEmptyLStack()//�ж�ջ�Ƿ�Ϊ��
{
	if (head->next == nullptr)
		return true;
	else
		return false;
}
template <typename T>
bool Stack<T>::isFullStack()
{
	Node<T>* newp = new Node<T>;
	if (!newp)
		return true;
	else
		return false;
	delete newp;
}
template <typename T>
T Stack<T>::getTopLStack()//�õ�ջ��Ԫ��
{
	if(tail)
		return tail->data;
}
template <typename T>
bool Stack<T>::clearLStack()//���ջ
{
	if (isEmptyLStack())
		return true;
	Node<T>* pt = head->next;
	Node<T>* pt2 = pt->next;
	while (pt)
	{
		delete pt;
		pt = pt2;
		pt2 = pt2->next;
	}
	head->next = tail = nullptr;
	size = 0;
	return true;
}
template <typename T>
int Stack<T>::LStackLength()//���ջ����
{
	return size;
}
template <typename T>
bool Stack<T>::pushLStack(T data)//��ջ
{
	Node<T>* npt = new Node<T>;
	npt->data = data;
	npt->next = nullptr;
	npt->prev = tail;
	if (isEmptyLStack())
	{
		head->next = tail = npt;
		tail->prev = head;
		return true;
	}
	std::cout << " 1 " << std::endl;
	tail->next = npt;
	tail = npt;
	return true;
}
template <typename T>
T Stack<T>::popLStack()//��ջ
{
	T pt = tail->data;
	if (head->next == tail)
	{
		delete tail;
		head->next = tail = nullptr;
		return pt;
	}
	tail = tail->prev;
	delete tail->next;
	tail->next = nullptr;
	return pt;
}

#endif