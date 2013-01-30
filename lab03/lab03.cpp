#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//List class starts here.
/*********************************************************************/

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
	data_ = new T[10];
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

//User class starts here.
/*****************************************************************/

class User{
	public:
		User();
		~User();
		
		string getName();
		int getAge();
		string getFriend(int loc);
		
		void setName(string name);
		void setAge(int age);
		void addFriend(string name);
		
	private:
		string name_;
		int age_;
		List<string>* friends;
};

User::User() {
	int userInput = 0;
	cout << "Please enter a capacity for your friends list: ";
	cin >> userInput;

	name_ = "";
	age_ = 0;
	friends = new List<string>(userInput);
};

string User::getName() {
	return name_;
};

int User::getAge() {
	return age_;
};

string User::getFriend(int loc) {
	return friends->at(loc);
};

void User::setName(string name) {
	name_ = name;
};

void User::setAge(int age) {
	age_ = age;
};

void User::addFriend(string name) {
	friends->push_back(name);
};

//Main function starts here.
/*********************************************************************/

int main() {
	return 0;
}
