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
	int GetSize();//리스트의 노드 개수를 리턴
	void Insert(T element);//맨 앞에 원소를 삽입
	virtual bool Delete(T &element);//맨 뒤의 원소를 삭제
	void Print();//리스트를 출력
};

template <typename T>
class Stack :public LinkedList<T> {
public:
	virtual bool Delete(T &element);//맨 뒤의 원소를 삭제
};

#endif