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
	bool isEmptyLStack();//判断栈是否为空
	bool isFullStack();//判断栈是否已满
	T getTopLStack();//得到栈顶元素
	bool clearLStack();//清空栈
	int LStackLength();//检测栈长度
	bool pushLStack(T data);//入栈
	T popLStack();//出栈
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
bool Stack<T>::isEmptyLStack()//判断栈是否为空
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
T Stack<T>::getTopLStack()//得到栈顶元素
{
	if(tail)
		return tail->data;
}
template <typename T>
bool Stack<T>::clearLStack()//清空栈
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
int Stack<T>::LStackLength()//检测栈长度
{
	return size;
}
template <typename T>
bool Stack<T>::pushLStack(T data)//入栈
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
T Stack<T>::popLStack()//出栈
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