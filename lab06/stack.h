#ifndef STACK_H
#define STACK_H

#include "llist.h"

template <typename T>
class Stack : private LList<T> {
	public:
		Stack();
		~Stack();
		int size() const;
		void push(const T& val);
		void pop();
		T& top();
		bool empty() const;
};

template <typename T>
Stack<T>::Stack() {};

template <typename T>
Stack<T>::~Stack() {
	LList<T>::clear();
};

template <typename T>
int Stack<T>::size() const {
	LList<T>::size();
}

template <typename T>
void Stack<T>::push(const T& val) {
	insert(0, val);
}

template <typename T>
void Stack<T>::pop() {
	if(size() == 0) {
		cout << "ERROR: Trying to pop empty stack." << endl;
		return;
	}
	LList<T>::pop_front();
	return;
}

template <typename T>
T& Stack<T>::top() {
	LList<T>::peek_front();
}

template <typename T>
bool Stack<T>::empty() const {
	LList<T>::empty();
}

#endif
