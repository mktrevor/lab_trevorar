#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>

template <typename T>
struct Node {
	T val_;
	Node<T> *left;
	Node<T> *right;
	Node<T> *parent;
	bool red;
};

template <typename T>
void inOrderPrint(Node<T>* node) {
	
	if(node->left == NULL && node->right == NULL) { 
		std::cout << node->val_ << std::endl;
		std::cout << "RED: " << node->red << std::endl;
		return;
	}
	if(node->left != NULL) {
		inOrderPrint(node->left);
	}
	std::cout << node->val_ << std::endl;
	std::cout << "RED: " << node->red << std::endl;
	if(node->right != NULL) {
		inOrderPrint(node->right);	
	}
}

template <typename T>
void preOrderPrint(Node<T>* node) {
	if(node->left == NULL && node->right == NULL) {
		std::cout << node->val_ << std::endl;
		return;
	}
	std::cout << node->val_ << std::endl;
	if(node->left != NULL) {
		preOrderPrint(node->left);
	}
	if(node->right != NULL) {
		preOrderPrint(node->right);	
	}
}

template <typename T>
class RBTree {
	public:
		RBTree();
		~RBTree();
		
		Node<T>* find(const T& val);
		bool empty();
		int size();
		void insert(const T& val);
		void inOrderPrintTraversal();
		void preOrderPrintTraversal();
		
	private:
		Node<T> *root_;
		int size_;
		Node<T>* uncle(Node<T>* node);
		Node<T>* grandparent(Node<T>* node);
		bool leftChild(Node<T>* node);
		bool rightChild(Node<T>* node);
		void rightRotate(Node<T>* x);
		void leftRotate(Node<T>* x);
		void fixTree(Node<T>* node);
};

template <typename T>
RBTree<T>::RBTree() {
	root_ = NULL;
	size_ = 0;
}

template <typename T>
RBTree<T>::~RBTree() { }

template <typename T>
Node<T>* RBTree<T>::find(const T& val) {
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
			temp = temp->right;
			continue;
		}
		else {
			temp = temp->left;
			continue;
		}
	}
}

template <typename T>
bool RBTree<T>::empty() {
	return (root_ == NULL);
}

template <typename T>
int RBTree<T>::size() {
	return size_;
}

template <typename T>
void RBTree<T>::insert(const T& val) {
	Node<T> *newNode = new Node<T>;
	newNode->val_ = val;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	newNode->red = 1;
	
	if(root_ == NULL) {
		root_ = newNode;
		size_++;
		return;
	}
	
	Node<T> *temp = root_;
	
	while(true) {
		if(newNode->val_ > temp->val_) {
			if(temp->right == NULL) {
				temp->right = newNode;
				newNode->parent = temp;
				size_++;
				break;
			} else {
				temp = temp->right;
				continue;
			}
		}
		else if(newNode->val_ < temp->val_) {
			if(temp->left == NULL) {
				temp->left = newNode;
				newNode->parent = temp;
				size_++;
				break;
			} else {
				temp = temp->left;
				continue;
			}
		}
	}
	if(newNode == root_) {
		return;
	}
	if(newNode->parent->red == 0) {
		return;
	} else {
		fixTree(newNode);
	}
}

template <typename T>
void RBTree<T>::inOrderPrintTraversal() {
	if(empty()) {
		std::cout << "Tree is empty." << std::endl;
		return;
	}
	inOrderPrint(root_);
}


template <typename T>
void RBTree<T>::preOrderPrintTraversal() {
	if(empty()) {
		std::cout << "Tree is empty." << std::endl;
		return;
	}
	preOrderPrint(root_);
}

template <typename T>
bool RBTree<T>::leftChild(Node<T>* node) {
	if(node == root_) {
		return 0;
	}
	return (node->parent->left == node);
}

template <typename T>
bool RBTree<T>::rightChild(Node<T>* node) {
	if(node == root_) {
		return 0;
	}
	return (node->parent->right == node);
}

template <typename T>
Node<T>* RBTree<T>::grandparent(Node<T>* node) {
	if(node != NULL && node->parent != NULL) {
		return node->parent->parent;
	} else { return NULL; }
}

template <typename T>
Node<T>* RBTree<T>::uncle(Node<T>* node) {
	Node<T>* g = grandparent(node);
	
	if(g == NULL) {
		return NULL;
	} 
	if(leftChild(node->parent)) {
		return g->right;
	} else {
		return g->left;
	}	
}

template <typename T>
void RBTree<T>::leftRotate(Node<T>* x) {
	Node<T>* y = x->right;
	x->right = y->left;
	if(y->left != NULL) {
		y->left->parent = x;
	}
	
	y->parent = x->parent;
	
	if(x->parent == NULL) {
		root_ = y;
	} else if(leftChild(x)) {
		x->parent->left = y;
	} else {
		x->parent->right = y;
	}
	
	y->left = x;
	x->parent = y;
}

template <typename T>
void RBTree<T>::rightRotate(Node<T>* x) {
	Node<T>* y = x->left;
	x->left = y->right;
	if(y->right != NULL) {
		y->right->parent = x;
	}
	
	y->parent = x->parent;
	
	if(x->parent == NULL) {
		root_ = y;
	} else if(rightChild(x)) {
		x->parent->right = y;
	} else {
		x->parent->left = y;
	}
	
	y->right = x;
	x->parent = y;
}



template <typename T>
void RBTree<T>::fixTree(Node<T>* node) {
	if(node->parent == NULL) {
		node->red == 0;
		return;
	}
	if(node->parent->red == 0) {
		return;
	}

	Node<T> *u = uncle(node);
	Node<T> *g = grandparent(node);

	if(u != NULL && u->red == 1) {
		node->parent->red = 0;
		u->red = 0;
		g->red = 1;
		fixTree(g);
		return;
	} 
	if(rightChild(node) && leftChild(node->parent)) {
		leftRotate(node->parent);
		node = node->left;
	} else if(leftChild(node) && rightChild(node->parent)) {
		rightRotate(node->parent);
		node = node->right;
	}
	
	g = grandparent(node);
	if(node != NULL) {
		node->parent->red = 0;
	}
	if(g != NULL) {
		g->red = 1;
	
		if(leftChild(node)) {
			rightRotate(g);
		} else {
			leftRotate(g);
		}
	}
}

#endif
