#pragma once
#include <iostream>

template <class T>
struct TNode {
	TNode<T>*prnode=nullptr;
	T dat;
};

template <class T>
class Stack
{
private:
	TNode<T>*top;
	size_t size;
public:
	Stack();
	~Stack();
	bool Push_Back(T data);
	bool Pop_Back();
	T Top();
	bool Empty();
	size_t Size();
};



template<class T>
Stack<T>::Stack()
{

	this->top = nullptr;
	this->size = 0;
}

template<class T>
Stack<T>::~Stack()
{
	TNode<T> *tmp;
	while (this->top) {
		tmp = this->top;
		this->top = this->top->prnode;
		delete tmp;
	}
   size=0;
}

template<class T>
bool Stack<T>::Push_Back(T data)
{
	TNode<T>* node = new TNode<T>();
	node->dat = data;
	node->prnode = this->top;
	this->top = node;
	size++;
	return false;
}

template<class T>
bool Stack<T>::Pop_Back()
{
	TNode<T>* tmp = this->top;
	this->top = this->top->prnode;
	delete tmp;
	size--;
	return false;
}

template<class T>
T Stack<T>::Top()
{
	return this->top->dat;
}

template<class T>
bool Stack<T>::Empty()
{
	if (top == nullptr)
		return true;
	return false;
}

template<class T>
size_t Stack<T>::Size()
{
	return size;
}