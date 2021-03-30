/**
 * ����:QG
 **/


#ifndef __QGLIST_H__
#define __QGLIST_H__

 /*
  * ˫������
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
	 * ��ʼ������
	 */
	QGList();

	/*
	 * ��������
	 */
	~QGList();

	//�ж��Ƿ�Ϊ������
	bool ListIsEmpty();

	//�ж������Ƿ����� 
	bool ListIsFull();

	/*
	 * ���������е�һ��Ԫ�ص�����
	 */
	ElemType& front();

	/*
	 * �������������һ��Ԫ�ص�����
	 */
	ElemType& back();

	/*
	* ��ӽڵ�����
	*/
	ElemType& Add();

	/*
	 * �������һ��Ԫ��ǰ���Ԫ��e
	 */
	bool push_front(ElemType e);

	/*
	 * ɾ�������һ��Ԫ��
	 */
	bool pop_front();

	/*
	 * ���������һ��Ԫ�غ����Ԫ��e
	 */
	bool push_back(ElemType e);

	/*
	 * ɾ���������һ��Ԫ��
	 */
	bool pop_back();

	//���ҽڵ�
	Node* SearchNode(unsigned int index);

	/*
	 * ������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
	 */
	bool insert(unsigned int index, ElemType e);

	/*
	 * ɾ������λ��Ԫ��
	 */
	bool erase(unsigned int index);

	/*
	 * �������
	 */
	bool clear();

	/*
	 * ����Ԫ���Ƿ����
	 */
	bool contain(ElemType& e);

	/*
	 * ����������Ԫ�ص�����
	 */
	unsigned int size();

	/*
	 * ��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
	 */
	bool traverse(void (*visit)(ElemType& e));
};

#endif

