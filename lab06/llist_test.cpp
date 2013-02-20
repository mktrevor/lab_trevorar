#include <iostream>
//#include "llist_sol.h"
#include "llist.h"
#include "stack.h"
#include "queue.h"

using namespace std;

int main()
{
	cout << "LINKED LIST:" << endl;

  LList<int> mylist;
  
  mylist.push_back(5);
  mylist.push_back(6);
  mylist.push_back(7);
  mylist.push_back(8);
  cout << "Front item is: " << mylist.peek_front() << endl;
  cout << "Item at location 1 is " << mylist[1] << endl;
  mylist.remove(6);
  mylist.insert(0,4);
  mylist.insert(2,9);
  cout << "List contents (and removal)" << endl;
  cout << "Size: " << mylist.size() << endl;
  while(!mylist.empty()){
    cout << mylist.peek_front() << endl;
    mylist.pop_front();
  }
  
  cout << "STACK: " << endl;
  
  Stack<int> mystack;
  mystack.push(0);
  cout << "Top: " << mystack.top() << endl;
  mystack.push(4);
  cout << "Top: " << mystack.top() << endl;
  mystack.push(44);
  cout << "Top: " << mystack.top() << endl;
  mystack.pop();
  cout << "Top: " << mystack.top() << endl;
  mystack.push(12);
  cout << "Top: " << mystack.top() << endl;
  mystack.pop();
  cout << "Top: " << mystack.top() << endl;
  mystack.push(124);
  cout << "Top: " << mystack.top() << endl;
  while(!mystack.empty()) {
  	mystack.pop();
  }
  
  //mystack.pop;
  
  mystack.push(100);
  cout << "Top: " << mystack.top() << endl;
  mystack.push(50);
  cout << "Top: " << mystack.top() << endl;
  mystack.push(4);
  cout << "Top: " << mystack.top() << endl;
  while(!mystack.empty()) {
  	cout << mystack.top() << endl;
  	mystack.pop();
  }
  
  cout << "QUEUE: " << endl;
  
  Queue<int> myqueue;
  myqueue.push_back(0);
  cout << "Front: " << myqueue.front() << "    Back: " << myqueue.back() << endl;
  myqueue.push_back(4);
  cout << "Front: " << myqueue.front() << "    Back: " << myqueue.back() << endl;
  myqueue.push_back(44);
  cout << "Front: " << myqueue.front() << "    Back: " << myqueue.back() << endl;
  myqueue.pop_front();
  cout << "Front: " << myqueue.front() << "    Back: " << myqueue.back() << endl;
  myqueue.push_back(12);
  cout << "Front: " << myqueue.front() << "    Back: " << myqueue.back() << endl;
  myqueue.pop_front();
  cout << "Front: " << myqueue.front() << "    Back: " << myqueue.back() << endl;
  myqueue.push_back(124);
  cout << "Front: " << myqueue.front() << "    Back: " << myqueue.back() << endl;
  while(!myqueue.empty()) {
  	myqueue.pop_front();
  }
  
  myqueue.push_back(100);
  cout << "Front: " << myqueue.front() << "    Back: " << myqueue.back() << endl;
  myqueue.push_back(50);
  cout << "Front: " << myqueue.front() << "    Back: " << myqueue.back() << endl;
  myqueue.push_back(4);
  cout << "Front: " << myqueue.front() << "    Back: " << myqueue.back() << endl;
  while(!myqueue.empty()) {
  	cout << myqueue.front() << endl;
  	myqueue.pop_front();
  }
  return 0;
}
