#include "mylist.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	MyList<int> intList;
	
	for(int i = 0; i < 12; i++) {
		intList.push_back(i);
		i++;
	}
	
	MyList<string> stringList;
	
	for(int i = 0; i < 4; i++) {
		string word = "";
		cout << "Enter a word" << endl;
		cin >> word;
		stringList.push_back(word);
	}
	
	return 0;
}
