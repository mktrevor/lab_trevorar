#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T> class List{
	public:
		List();
		~List();
		int getSize();
		void push_back(T item);
		T at(int loc);
	
	private:
		T* data_;
		int size;
		int capacity;
};

template <typename T> List<T>::List() {
	size = 0;
	capacity = 2;
	data_ = new T[2];	
};

template <typename T> List<T>::~List() {
	delete [] data_;
}

template <typename T> int List<T>::getSize() {
	return size;
}

template <typename T> void List<T>::push_back(T item) {
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

template <typename T> T List<T>::at(int loc) {
	return data_[loc];
}
