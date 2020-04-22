#include <iostream>
using namespace std;
#include <string>
#include "header.h"

template <typename T>
Node<T>::Node(T element) {
	data = element;
	link = NULL;
}

template <typename T>
LinkedList<T>::LinkedList() {
	first = 0;
	current_size = 0;
}

template <typename T>
int LinkedList<T>::GetSize() {
	return current_size;
}

template <typename T>
void LinkedList<T>::Insert(T element) {
	Node<T> *newnode = new Node<T>(element);
	newnode->link = first;
	first = newnode;
	current_size++;
}

template <typename T>
bool LinkedList<T>::Delete(T &element) {
	if (first == 0)
		return false;

	Node<T> *current = first;
	Node<T> *previous = NULL;

	while (1) {
		if (current->link == 0) {
			if (previous)
				previous->link = current->link;
			else
				first = first->link;
			break;
		}
		previous = current;
		current = current->link;
	}

	element = current->data;
	delete current;

	current_size--;

	return true;
}

template <typename T>
void LinkedList<T>::Print() {
	Node<T> *current = first;

	for (int i = 1; i <= current_size; i++) {
		cout << "[" << i << "|" << current->data << "]";
		if (i == current_size) break;
		cout << "->";
		current = current->link;
	}
	cout << endl;
}

template <typename T>
bool Stack<T>::Delete(T &element) {
	Node<T> *dlt;

	if (this->first == 0)
		return false;
	dlt = this->first;
	this->first = this->first->link;

	element = dlt->data;
	delete dlt;
	this->current_size--;
	return true;
}