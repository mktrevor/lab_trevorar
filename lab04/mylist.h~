#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

//List class starts here.
/*********************************************************************/

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

//User class starts here.
/*****************************************************************/

class User{
	public:
		User();
		User(string name, int age);
		~User();
		
		string getName();
		int getAge();
		string getFriend(int loc);
		
		void setName(string name);
		void setAge(int age);
		void addFriend(string name);
		
		void printUser();
		
	private:
		string name_;
		int age_;
		List<string>* friends;
};

User::User() {
	name_ = "";
	age_ = 0;
	friends = new List<string>;
};

User::User(string name, int age) {
	name_ = name;
	age_ = age;
	friends = new List<string>;
}
string User::getName() {
	return name_;
};

User::~User() {
	delete friends;
}

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

void User::printUser() {
	cout << "User name: " << name_ << endl;
	cout << "User age: " << age_ << endl;
	cout << "User friends: ";
	for(int i = 0; i < friends->getSize(); i++) {
		cout << getFriend(i) << " ";
	}
	cout << endl;
};
	
//Main function starts here.
/*********************************************************************/

int main() {
	vector<User*> userList;
	
	cout << "Please enter a name and an age (separated by a space) for as many users as you would like." << endl;
	cout << "Enter 'done' when you've finished." << endl << endl;
	
	while(true) {
		string name = "";
		int age = 0;
		
		cin >> name;
		
		if(name == "done") {
			break;
		}
		
		cin >> age;
		
		User* user = new User(name, age);
		
		userList.push_back(user);
	}

	cout << endl << endl;
	cout << "Good. Now, enter two names at a time and the second will be added to the first's friends list." << endl;
	cout << "Enter 'done' when you've finished." << endl << endl;
	
	while(true) {
		string name1 = "";
		string name2 = "";
		
		cin >> name1;
		
		if(name1 == "done") {
			break;
		}
		
		cin >> name2;
		
		for(int i = 0; i < userList.size(); i++) {
			if(userList[i]->getName() == name1) {
				userList[i]->addFriend(name2);
			}
		}
	}
	
	cout << endl << "USERS" << endl;	
		
	for(int i = 0; i < userList.size(); i++) {
		cout << "--------------------" << endl;
		userList[i]->printUser();
	}
	
	return 0;
}
