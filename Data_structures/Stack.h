#pragma once
#include <iostream>


namespace stack {
	template <class T>
	struct TNode {
		TNode<T>* next = nullptr;
		T data;
	};

	template <class T>
	class Stack
	{
	public:
		Stack();
		~Stack();
		void pushBack(T input_data);
		void popBack();
		T top();
		bool empty();
		size_t size();
	private:
		TNode<T> *top_;
		size_t size_;
	};



	template<class T>
	Stack<T>::Stack()
	{

		this->top_ = nullptr;
		this->size_ = 0;
	}

	template<class T>
	Stack<T>::~Stack()
	{
		TNode<T> *tmp;
		while (this->top_) {
			tmp = this->top_;
			this->top_ = this->top_->next;
			delete tmp;
		}
		size_ = 0;
	}

	template<class T>
	void Stack<T>::pushBack(T inputData)
	{
		TNode<T>* node = new TNode<T>();
		node->data = inputData;
		node->next = this->top_;
		this->top_ = node;
		size_++;
	}

	template<class T>
	void Stack<T>::popBack()
	{
		TNode<T>* tmp = this->top_;
		this->top_ = this->top_->next;
		delete tmp;
		size_--;
	}


	template<class T>
	T Stack<T>::top()
	{
		return this->top_->data;
	}

	template<class T>
	bool Stack<T>::empty()
	{
		if (top_ == nullptr)
			return true;
		return false;
	}

	template<class T>
	size_t Stack<T>::size()
	{
		return size_;
	}

}