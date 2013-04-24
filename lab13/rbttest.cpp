#include <iostream>
#include <fstream>
#include <sstream>
#include "rbtree.h"

using namespace std;

int main(int argc, char* argv[]) {	

	if(argc < 2 || argc > 2) {
		cout << "Invalid arguments." << endl;
		return 0;
	}
	
	RBTree<int> tree;	
	
	ifstream inputFile(argv[1]);
	
	if(!inputFile.is_open()) {
		cout << "Error: Could not open file." << endl;
		return 0;
	}

	int num;
	
	//Part 1
	while(inputFile >> num) {
		tree.insert(num);
		//tree.preOrderPrintTraversal();
		//cout << "----" << endl;
	}
	
	//Part 2 (ttest1.txt)
	/*cout << tree.find(55) << endl;
	cout << tree.empty() << endl;
	cout << tree.size() << endl;
	tree.inOrderPrintTraversal();
	tree.preOrderPrintTraversal();*/
	
	//Part 3 (ttest2.txt)
	/*cout << tree.empty() << endl;
	cout << tree.size() << endl;
	cout << tree.find(1) << endl;
	cout << tree.find(20) << endl;
	cout << tree.find(25) << endl;
	cout << tree.find(5) << endl;
	cout << tree.size() << endl;*/
	
	//Part 3 (ttest3.txt)
	cout << tree.empty() << endl;
	cout << tree.size() << endl;
	cout << tree.find(100) << endl;
	cout << tree.find(50) << endl;
	cout << tree.find(48) << endl;
	cout << tree.find(1337) << endl;
	cout << tree.size() << endl;
	
	//tree.inOrderPrintTraversal();
	
	return 0;
}
