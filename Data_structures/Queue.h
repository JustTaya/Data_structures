#pragma once
#include <iostream>

template <class T>
struct QNode {
	QNode<T> *next_node=nullptr;
	T dat;
};

template <class T>
class Queue {
private:
	QNode<T> *head;
	QNode<T> *tail;
	size_t size;
public:
	Queue();
	~Queue();
	bool Enqueue(T  data);
	T Dequeue();
	bool Empty();
	size_t Size();
};

template<class T>
inline Queue<T>::Queue()
{
	head = nullptr;
	tail = head;
	size = 0;
}

template<class T>
Queue<T>::~Queue()
{
	QNode<T>* tmp;
	while (this->head) {
		tmp = this->head;
		this->head = this->head->next_node;
		delete tmp;
	}
}

template<class T>
bool Queue<T>::Enqueue(T data)
{
	QNode<T>* tmp = new QNode<T>();
	tmp->dat = data;
	size++;
	if (this->head==nullptr) {
		this->head = tmp;
		this->tail = tmp;
		return false;
	}
	(this->tail)->next_node = tmp;
	this->tail = tmp;
	return false;
}

template<class T>
T Queue<T>::Dequeue()
{
	QNode<T>*tmp = this->head;
	T data = this->head->dat;
	this->head = this->head->next_node;
	size--;
	delete tmp;
	return data;
}

template<class T>
bool Queue<T>::Empty()
{
	if (this->head == nullptr)
		return true;
	return false;
}

template<class T>
inline size_t Queue<T>::Size()
{
	return size;
}
