#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <string>

using namespace std;

template <typename T> class MyList{
	public:
		MyList();
		~MyList();
		int getSize();
		void push_back(T item);
		T at(int loc);
	
	private:
		T* data_;
		int size;
		int capacity;
};

template <typename T> MyList<T>::MyList() {
	size = 0;
	capacity = 2;
	data_ = new T[2];
};

template <typename T> MyList<T>::~MyList() {
	delete [] data_;
}

template <typename T> int MyList<T>::getSize() {
	return size;
}

template <typename T> void MyList<T>::push_back(T item) {
	if(size == capacity) {
		T* newData = new T[size*2];
		
		for(int i = 0; i < size; i++) {
			newData[i] = data_[i];
		}
		
		delete [] data_;
		
		data_ = newData;
		
		capacity *= 2;
		
		return;
	}
	
	data_[size] = item;
	size++;
}

template <typename T> T MyList<T>::at(int loc) {
	return data_[loc];
}

#endif
