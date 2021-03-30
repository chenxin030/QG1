/**
 * 作者:QG
 **/


#ifndef __QGLIST_H__
#define __QGLIST_H__

 /*
  * 双向链表
  */
class QGList {

public:
	typedef int ElemType;

protected:
	struct Node {
		ElemType data;
		struct Node* prior;
		struct Node* next;
	};
	struct
	{
		Node* head;
		Node* tail;
		int size;
	}List;


public:

	/*
	 * 初始化链表
	 */
	QGList();

	/*
	 * 销毁链表
	 */
	~QGList();

	//判断是否为空链表
	bool ListIsEmpty();

	//判断链表是否已满 
	bool ListIsFull();

	/*
	 * 返回链表中第一个元素的引用
	 */
	ElemType& front();

	/*
	 * 返回链表中最后一个元素的引用
	 */
	ElemType& back();

	/*
	* 添加节点内容
	*/
	ElemType& Add();

	/*
	 * 在链表第一个元素前添加元素e
	 */
	bool push_front(ElemType e);

	/*
	 * 删除链表第一个元素
	 */
	bool pop_front();

	/*
	 * 在链表最后一个元素后添加元素e
	 */
	bool push_back(ElemType e);

	/*
	 * 删除链表最后一个元素
	 */
	bool pop_back();

	//查找节点
	Node* SearchNode(unsigned int index);

	/*
	 * 在链表的第index + 1个元素前插入元素e
	 */
	bool insert(unsigned int index, ElemType e);

	/*
	 * 删除任意位置元素
	 */
	bool erase(unsigned int index);

	/*
	 * 清空链表
	 */
	bool clear();

	/*
	 * 查找元素是否存在
	 */
	bool contain(ElemType& e);

	/*
	 * 返回链表中元素的数量
	 */
	unsigned int size();

	/*
	 * 遍历链表, 对每个元素调用visit指向的函数
	 */
	bool traverse(void (*visit)(ElemType& e));
};

#endif

