#include <iostream>
#include <fstream>
#include <sstream>
#include "bstree.h"

using namespace std;

int main(int argc, char* argv[]) {	

	if(argc < 2 || argc > 2) {
		cout << "Invalid arguments." << endl;
		return 0;
	}
	
	BSTree<int> tree;
	
	//Code for part 1
	/*tree.find(55);
	tree.empty();
	tree.size();
	tree.inOrderPrintTraversal();
	tree.preOrderPrintTraversal();
	*/
	
	ifstream inputFile(argv[1]);
	
	if(!inputFile.is_open()) {
		cout << "Error: Could not open file." << endl;
		return 0;
	}

	int num;
	
	while(inputFile >> num) {
		tree.insert(num);
		tree.preOrderPrintTraversal();
	}
	
	cout << "Done: " << endl;
	
	tree.inOrderPrintTraversal();
	
	//Code for part 2
	/*cout << tree.empty() << endl;
	cout << tree.size() << endl;
	cout << tree.find(2) << endl;
	cout << tree.find(7) << endl;
	cout << tree.find(20) << endl;
	cout << tree.find(8) << endl;
	cout << tree.find(11) << endl;
	cout << tree.size() << endl;*/
	
	//Code for part 3
	cout << tree.empty() << endl;
	cout << tree.size() << endl;
	cout << tree.find(20) << endl;
	cout << tree.find(17) << endl;
	cout << tree.find(22) << endl;
	cout << tree.find(13) << endl;
	cout << tree.find(27) << endl;
	cout << tree.find(10) << endl;
	cout << tree.size() << endl;

	return 0;
}
