// table.cpp - hash table implementation of a table to store strings
// Now includes "big 3" (copy constructor, assignment operator, and destructor)
// Kekoa Sato, 05/06/16

#include <iostream>
#include <fstream>
#include "table.h"
#include <algorithm>

using namespace std;

// Constructors
Table::Table(unsigned int max_entries) {
    arr = new list<Entry>[max_entries];
    size = max_entries;
    used = 0;
}

Table::Table(unsigned int entries, istream &input) {
    arr = new list<Entry>[entries];
    size = entries;
    used = 0;
    int key = 0;
    string s;
    while (!input.eof() && used != size) {
        Entry *e = new Entry;
        input >> *e;
        put(*e);
        delete e;
    }
}

Table::Table(const Table& source) {
    *this = source;
}

Table::~Table() {
    delete []arr;
    this->size = 0;
    this->used = 0;
}

Table& Table::operator=(const Table& source) {
    if (this == &source)
        return *this;
    if (this->getUsed() != 0)
        this->~Table();
    arr = new list<Entry>[source.getSize()];
    size = source.getSize();
    list<Entry> *sourceArr = source.getArray();
    for (int i = 0; i < source.getSize(); i++) {
        list<Entry>::iterator it;
        for (it = sourceArr[i].begin(); it != sourceArr[i].end(); ++it) {
            Entry *e = new Entry(*it);
            put(*e);
            delete e;
        }
    }
    return *this;
    
}

// Overloaded put functions

void Table::put(unsigned int key, std::string data) {
    Entry *e = new Entry(key, data);
    put(*e);
    delete e;
}

void Table::put(Entry e) {
    list<Entry>::iterator it;
    int key = e.get_key();
    unsigned int index = hashkey(key);
    for (it = arr[index].begin(); it != arr[index].end(); ++it) {
        if (it->get_key() == key) {
            
            it->set_data(e.get_data());
            return;
        }
    }
    arr[index].push_back(e);
    used++;
}
// Returns string associated with parameter

string Table::get(unsigned int key) const {
    list<Entry>::iterator it;
    unsigned int index = hashkey(key);
    for (it = arr[index].begin(); it != arr[index].end(); ++it) {
        if (it->get_key() == key)
            return it->get_data();
    }
    return "";
}
// Removes Entry given key

bool Table::remove(unsigned int key) {
    unsigned int index = hashkey(key);
    list<Entry>::iterator it;
    for (it = arr[index].begin(); it != arr[index].end(); ++it) {
        if (it->get_key() == key) {
            arr[index].erase(it);
            used--;
            return true;
        }
    }
    return false;
}

int Table::getUsed() const {
    return used;
}

int Table::getSize() const {
    return size;
}

list<Entry>* Table::getArray() const {
    return arr;
}

unsigned int Table::hashkey(unsigned int key) const {
    return key % size;
}

std::ostream& operator<<(std::ostream &out, const Table &t) {
    int counter = 0;
    Entry *array = new Entry[t.getUsed()];

    for (int i = 0; i < t.getSize(); i++) {
        list<Entry>::iterator it;
        for (it = t.arr[i].begin(); it != t.arr[i].end(); ++it) {
            array[counter] = *it;
            counter++;
        }
    }

    sort(array, array + t.getUsed());
    for (int i = 0; i < t.getUsed(); i++) {
        out << array[i] << endl;
    }
    delete []array;
    return out;
}