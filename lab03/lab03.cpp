#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

template <typename T> class List{
	public:
		List();
		List(int c);
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
	capacity = 20;
	data_ = new T[20];
};

template <typename T> List<T>::List(int c) {
	size = 0;
	capacity = c;
	data_ = new T[c];
};

template <typename T> int List<T>::getSize() {
	return size;
}

template <typename T> void List<T>::push_back(T item) {
	if(size == capacity) {
		cout << "Sorry, this array is full." << endl;
		return;
	}
	
	data_[size] = item;
	size++;
}

template <typename T> T List<T>::at(int loc) {
	return data_[loc];
}

int main() {
	return 0;
}
