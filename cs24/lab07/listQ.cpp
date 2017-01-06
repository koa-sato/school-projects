// listQ.cpp - implements queue as linked list
// Kekoa Sato, Avi Loschak, 02/16/2016

#include "listQ.h"


#include <iostream>
using namespace std;
Queue::Queue() { 
	Node *q = new Node(0);
    q->data = 0;
    q->next = 0;
    front = rear = q;
    size = 0;
}  
Queue::~Queue() {
    clear();
    front = rear = 0;

}

void Queue::enqueue(int n) {
    Node *q = new Node(n);
    if(rear != 0)
        rear->next = q;
    rear = q;
    if(size == 1)
        front->next = q;
    if(size == 0)
        front = q;
    q->data = n;
    size++;
}

int Queue::dequeue() {
    if (isEmpty())
        throw EmptyQueue();
    int value = front->data;
    Node *copy = front;
    front = front->next;
    delete copy;
    size--;
    if(size == 0){
        rear = 0;
    }
    return value;
}

void Queue::clear() {
    Node *temp = front;
    Node *q = temp;
    
    while(temp != 0) {
        temp = q->next;
        delete q;
        q = temp;
    }

    Node *n = new Node(0);
    n->data = 0;
    n->next = 0;
    front = rear = n;
    size = 0;

}

bool Queue::isEmpty() const {
    if(size == 0)
        return true;
    return false; 
}

int Queue::getSize() const {
    return size;
}
