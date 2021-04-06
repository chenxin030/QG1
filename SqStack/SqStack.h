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
	bool isEmptyLStack();//�ж�ջ�Ƿ�Ϊ��
	bool isFullStack();//�ж�ջ�Ƿ�����
	T getTopLStack();//�õ�ջ��Ԫ��
	bool clearLStack();//���ջ
	int LStackLength();//���ջ����
	bool pushLStack( T data);//��ջ
	T popLStack();//��ջ
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
	std::cout << "ջ������" << std::endl;
}
template <class T>
bool SqStack<T>::isEmptyLStack()//�ж�ջ�Ƿ�Ϊ��
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
T SqStack<T>::getTopLStack()//�õ�ջ��Ԫ��
{
	if (!isEmptyLStack())
		return Node[top];
}
template <class T>
bool SqStack<T>::clearLStack()//���ջ
{
	if (isEmptyLStack())
		return true;
	memset(Node, 0, sizeof(T) * StackSize);
	top = -1;
	return true;
}
template <class T>
int SqStack<T>::LStackLength()//���ջ����
{
	return top + 1;
}
template <class T>
bool SqStack<T>::pushLStack( T data)//��ջ
{
	Node[top + 1] = data;
	top++;
	return true;
}
template <class T>
T SqStack<T>::popLStack()//��ջ
{
	T pt = Node[top];
	Node[top] = 0;
	top--;
	return pt;
}

#endif