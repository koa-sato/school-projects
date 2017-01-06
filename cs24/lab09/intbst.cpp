// intbst.cpp
// Implements class IntBST
// Avi Loschak, Kekoa Sato 03/01/2016

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() : root(0) { }

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if (n) {
        clear(n->left);
        clear(n->right);
        delete n;
    }
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    // handle special case of empty tree first
    if (!root) {
        root = new Node(value);
        return true;
    }
    // otherwise use recursive helper
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    if (value == n->info)
        return false;
    if (value < n->info) {
        if (n->left)
            return insert(value, n->left);
        else {
            n->left = new Node(value);
            return true;
        }
    }
    else {
        if (n->right)
            return insert(value, n->right);
        else {
            n->right = new Node(value);
            return true;
        }
    }
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if (n) {
        cout << n->info << " ";
        printPreOrder(n->left);
        printPreOrder(n->right);
    }
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    printInOrder(root);
}
void IntBST::printInOrder(Node *n) const {
    if (n) {
        printInOrder(n->left);
        cout << n->info << " ";
        printInOrder(n->right);
    }
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    printPostOrder(root);
}
void IntBST::printPostOrder(Node *n) const {
    if (n) {
        printPostOrder(n->left);
        printPostOrder(n->right);
        cout << n->info << " ";
    }
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    if(n == NULL)
        return 0;
    else
        return n->info + sum(n->left) + sum(n->right);
}

// return count of values
int IntBST::count() const {
    return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const {
    if(n == NULL)
        return 0;
    else
       return 1 + count(n->left) + count(n->right);
}

// recursive helper for contains
bool IntBST::contains(int value, Node *n) const {
    if(n == NULL)
        return false;
    if(value < n->info )
        return contains(value, n->left);
    if(value > n->info)
        return contains(value, n->right);
    if(value == n->info)
        return true;
}
// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    return contains(value, root);
}


// implement optional challenge methods below
/*bool IntBST::contains(int value) const {
    Node *n = root;
    
    while(n != NULL) {
        if(value < n->info )
            n = n->left;
        else if(value > n->info)
            n = n->right;
        else if(value == n->info)
            return true;
    }
    
    return false;
}*/

void remove(int value) {
    if (root == NULL)
        return;
    else 
        remove(value, root);
}

void remove(int value, Node* &n) { // uses removeThis below too
    if(n->info == value)
        removeThis(n);
    if(value < n->info && n->left != NULL)
        remove(value, n->left);
    if(value > n->info && n->right != NULL)
        remove(value, n->right);
    
}

void removeThis(Node* &n) { // in turn, uses maxValue below
    if (n->left == NULL && n->right == NULL) {
        n->info = 0;
        delete n;
	}
    else if (n->left == NULL) {
        n->info = n->right->info;
        removeThis(n->right);
    }
    else if (n->right == NULL) {
        n->info = n->left->info;
        removeThis(n->left);
    }
    else {
        
    }
}

int maxValue(Node *n) const {
    if (n == NULL)
        return 0;
    if (n->right == NULL)
        return n->info;
    return maxValue(n->right);
}
