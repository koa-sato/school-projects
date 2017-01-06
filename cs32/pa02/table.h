// table.h - header file for table.cpp 
// Kekoa Sato 4/22/16

#ifndef TABLE_H
#define TABLE_H
#include "entry.h"
#include "list"
using namespace std;

class Table {
public:
    // Constructors
    Table(unsigned int max_entries = 100);
    Table(unsigned int entries, std::istream &input);
    Table(const Table& source);
    
    ~Table();
    
    Table& operator =(const Table& source);

    // Overloaded put functions
    void put(unsigned int key, std::string data);
    void put(Entry e);
    // Returns string associated with parameter
    std::string get(unsigned int key) const;
    // Removes Entry given key
    bool remove(unsigned int key);
    int getUsed() const;
    int getSize() const;
    list<Entry>* getArray() const;
    friend std::ostream& operator<<(std::ostream &out, const Table &t);
private:
    unsigned int size, used;
    list<Entry> *arr;
    unsigned int hashkey(unsigned int key) const;
};

#endif /* TABLE_H */

