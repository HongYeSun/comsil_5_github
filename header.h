#ifndef __LIST__
#define __LIST__

//Linked List Node
template <typename T>
class Node {
public:
	T data;
	Node<T> *link;
	Node(T element);
};

template <typename T>
class LinkedList {
protected:
	Node<T> *first;
	int current_size;
public:
	LinkedList();
	int GetSize();//����Ʈ�� ��� ������ ����
	void Insert(T element);//�� �տ� ���Ҹ� ����
	virtual bool Delete(T &element);//�� ���� ���Ҹ� ����
	void Print();//����Ʈ�� ���
};

template <typename T>
class Stack :public LinkedList<T> {
public:
	virtual bool Delete(T &element);//�� ���� ���Ҹ� ����
};

#endif