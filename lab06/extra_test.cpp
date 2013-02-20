#include <iostream>
#include "llist.h"
#include "stack.h"
#include "queue.h"

using namespace std;

int main()
{
	Stack<int> mystack;
	Queue<int> myqueue;
	
	int userChoice = 0;
	int num;
	
	while(true) {

		cout << "Please choose an option:" << endl;
		cout << "1. Push to stack." << endl;
		cout << "2. Print and pop top of stack." << endl;
		cout << "3. Push_back to queue." << endl;
		cout << "4. Print and pop front of queue." << endl;
		cout << "5. Quit." << endl;
	
		cin >> userChoice;
	
		switch(userChoice) {
			case 1:
			cout << "Enter an integer: ";
			cin >> num;
			mystack.push(num);
			break;
		
			case 2:
			if(mystack.size() > 0) {
				cout << endl << mystack.top();
				mystack.pop();
			} else {
				cout << endl << "Stack is empty!";
			}
			break;
		
			case 3:
			cout << "Enter an integer: ";
			cin >> num;
			myqueue.push_back(num);
			break;
	
			case 4:
			if(myqueue.size() > 0) {
				cout << endl << myqueue.front();
				myqueue.pop_front();
			} else {
				cout << endl << "Queue is empty!";
			}
			break;
		
			case 5:
			return 0;
		
			default:
			cout << "Please enter a valid choice.";
		}
		cout << endl << endl;
	}
}
