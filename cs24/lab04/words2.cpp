// words2.cpp - implements class Words
// (dynamic array version)
// Kekoa Sato, Avi Loschak 01/26/16

#include <cassert>
#include <string>
#include <algorithm>
#include "words2.h"

using std::string;

namespace lab04_2
{
    Words::Words(unsigned int initial_capacity) {
	data = new string[initial_capacity];
	capacity = initial_capacity;
        used = 0;
    }

    Words::Words(const Words &source) {
	data = new string[source.capacity];        
	capacity = source.capacity;
        used = source.used;
	copy(source.data, source.data + used, data);
	
    }

    Words::~Words() {
        delete [] data;
    }
    
    void Words::append(string word) {
	if(used == capacity) {
	    string *data2 = new string[capacity * 2];
	    copy(data, data + capacity, data2);
	    data = data2;
	    capacity = capacity * 2;
	}
	data[used] = word;
	used++;
	    
    }
    
    string& Words::operator[] (unsigned int index) {
        return data[index];
    }

    void Words::operator=(const Words &source) {
        if (this == &source)
            return;
        else if (source.get_capacity() != capacity) {
            string *data2 = new string[source.get_capacity()];
            delete [] data;
            data = data2;
	}
	    capacity = source.get_capacity();
	    used = source.size();
	    copy(source.data,source.data + source.size(), data);
    }
    
    unsigned int Words::size() const {
        return used;
    }
    
    unsigned int Words::get_capacity() const {
        return capacity;
    }
    
    string Words::operator[] (unsigned int index) const {
        return data[index];
    }
    
}
