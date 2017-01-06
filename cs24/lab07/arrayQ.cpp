// arrayQ.cpp - implements queue as array
// Kekoa Sato, Avi Loschak 02/16/2016

#include "arrayQ.h"

Queue::Queue() {
    clear();
 }  

void Queue::enqueue(int n) {
    if (isFull())
        throw FullQueue();
    rear = (rear + 1) % CAPACITY;
    data[rear] = n;
    size++;  
}

int Queue::dequeue() {
    if (isEmpty())
        throw EmptyQueue();
    front = (front + 1)%CAPACITY;
    size--;
    return data[front];
}

void Queue::clear() {
    front = rear = size = 0;
}

bool Queue::isEmpty() const {
    if (size == 0)
        return true;
    return false; 
}

bool Queue::isFull() const {
    if (size == CAPACITY)
        return true;
    return false; 
}

int Queue::getSize() const {
    return size; 
}
