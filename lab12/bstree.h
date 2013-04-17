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
void inOrderPrint(Node<T>* node) {
	if(node->left_ == NULL && node->right_ == NULL) { 
		std::cout << node->val_ << std::endl;
		return;
	}
	if(node->left_ != NULL) {
		inOrderPrint(node->left_);
	}
	std::cout << node->val_ << std::endl;
	if(node->right_ != NULL) {
		inOrderPrint(node->right_);	
	}
}

template <typename T>
void preOrderPrint(Node<T>* node) {
	if(node->left_ == NULL && node->right_ == NULL) {
		std::cout << node->val_ << std::endl;
		return;
	}
	std::cout << node->val_ << std::endl;
	if(node->left_ != NULL) {
		preOrderPrint(node->left_);
	}
	if(node->right_ != NULL) {
		preOrderPrint(node->right_);	
	}
}

template <typename T>
class BSTree {
	public:
		BSTree();
		~BSTree();
		
		Node<T>* find(const T& val);
		bool empty();
		int size();
		void insert(const T& val);
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
Node<T>* BSTree<T>::find(const T& val) {
	if(empty()) {
		std::cout << "Tree is empty." << std::endl;
	}
	
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
void BSTree<T>::insert(const T& val) {
	Node<T> *newNode = new Node<T>;
	newNode->val_ = val;
	newNode->left_ = NULL;
	newNode->right_ = NULL;
	
	if(root_ == NULL) {
		root_ = newNode;
		size_++;
		return;
	}
	
	Node<T> *temp = root_;
	
	while(true) {
		if(newNode->val_ > temp->val_) {
			if(temp->right_ == NULL) {
				temp->right_ = newNode;
				size_++;
				return;
			} else {
				temp = temp->right_;
				continue;
			}
		}
		else if(newNode->val_ < temp->val_) {
			if(temp->left_ == NULL) {
				temp->left_ = newNode;
				size_++;
				return;
			} else {
				temp = temp->left_;
				continue;
			}
		}
	}
}

template <typename T>
void BSTree<T>::inOrderPrintTraversal() {
	if(empty()) {
		std::cout << "Tree is empty." << std::endl;
		return;
	}
	inOrderPrint(root_);
}


template <typename T>
void BSTree<T>::preOrderPrintTraversal() {
	if(empty()) {
		std::cout << "Tree is empty." << std::endl;
		return;
	}
	preOrderPrint(root_);
}

#endif
