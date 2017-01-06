// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    for (Node *n = first; n != 0; n = n->next) {
        sum += n->info;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    for(Node *n = first; n != 0; n = n->next){
        if(n->info == value)
            return true;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if(count() == 0)
        return 0;

    int max = first->info;
    for(Node *n = first; n != 0; n = n->next){
        if(n->info > max){
            max = n->info;        
        }   
    }
        return max;
        
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if(count() == 0)
        return 0;
    return static_cast <double>(sum())/count();
    
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node *n = new Node;
    n->info = value;
    n->next = first;
    first = n;
}

// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }

// destructor deletes all nodes
IntList::~IntList() {
    Node *n = first;
    while (n) {
        Node *garbage = n;
        n = n->next;
        delete garbage;
    }
}

// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
