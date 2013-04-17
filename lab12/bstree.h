#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>

template <typename T>
struct Node {
	T val_;
	Node<T> *left_;
	Node<T> *right_;
};

template <typename T>
class BSTree {
	public:
		BSTree();
		~BSTree();
		
		Node<T>* find(T val);
		bool empty();
		int size();
		void insert(T val);
		void inOrderPrintTraversal();
		void preOrderPrintTraversal();
		
	private:
		Node<T> *root_;
		int size_;
};

template <typename T>
BSTree<T>::BSTree() {
	root_ = NULL;
	size_ = 0;
}

template <typename T>
BSTree<T>::~BSTree() { }

template <typename T>
Node<T>* BSTree<T>::find(T val) {
	Node<T> *temp = root_;
	while(true) {
		if(temp == NULL) {
			return NULL;
		}
		if(temp->val_ == val) {
			return temp;
		}
		else if(temp->val_ < val) {
			temp = temp->right_;
			continue;
		}
		else {
			temp = temp->left_;
			continue;
		}
	}
}

template <typename T>
bool BSTree<T>::empty() {
	return (root_ == NULL);
}

template <typename T>
int BSTree<T>::size() {
	return size_;
}

template <typename T>
void BSTree<T>::insert(T val) {
	Node<T> *temp = root_;

	Node<T> *newNode = new Node<T>;
	newNode->val_ = val;
	while(true) {
		if(newNode->val_ > temp->val_) {
			if(temp->right_ == NULL) {
				temp->right_ = newNode;
			} else {
				temp = temp->right_;
				continue;
			}
		}
		else if(newNode->val_ < temp->val_) {
			if(temp->left_ == NULL) {
				temp->left_ = newNode;
			} else {
				temp = temp->left_;
				continue;
			}
		}
	}
}




#endif
