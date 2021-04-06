#ifndef STACK_H
#define STACK_H
const int StackSize = 10;
template<class T>
struct Node
{
	T data;
};
template<class T>
class SqStack
{
public:
	SqStack();
	~SqStack();
public:
	bool isEmptyLStack();//判断栈是否为空
	bool isFullStack();//判断栈是否已满
	T getTopLStack();//得到栈顶元素
	bool clearLStack();//清空栈
	int LStackLength();//检测栈长度
	bool pushLStack( T data);//入栈
	T popLStack();//出栈
private:
	T Node[StackSize];
	int top;
};
template <class T>
SqStack<T>::SqStack()
{
	top = -1;
	memset(Node, 0, sizeof(T) * StackSize);
}
template <class T>
SqStack<T>::~SqStack()
{
	std::cout << "栈已销毁" << std::endl;
}
template <class T>
bool SqStack<T>::isEmptyLStack()//判断栈是否为空
{
	if (top == -1)
		return true;
	else
		return false;
}
template <class T>
bool SqStack<T>::isFullStack()
{
	if (top == StackSize-1)
		return true;
	else
		return false;
}
template <class T>
T SqStack<T>::getTopLStack()//得到栈顶元素
{
	if (!isEmptyLStack())
		return Node[top];
}
template <class T>
bool SqStack<T>::clearLStack()//清空栈
{
	if (isEmptyLStack())
		return true;
	memset(Node, 0, sizeof(T) * StackSize);
	top = -1;
	return true;
}
template <class T>
int SqStack<T>::LStackLength()//检测栈长度
{
	return top + 1;
}
template <class T>
bool SqStack<T>::pushLStack( T data)//入栈
{
	Node[top + 1] = data;
	top++;
	return true;
}
template <class T>
T SqStack<T>::popLStack()//出栈
{
	T pt = Node[top];
	Node[top] = 0;
	top--;
	return pt;
}

#endif