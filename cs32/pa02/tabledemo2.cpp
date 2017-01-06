// tabledemo.cpp - demonstration program for Table
// cmc, 4/4/2016

#include <iostream>
#include <fstream>
#include "table.h"

using namespace std;

unsigned int user_get(Table &t);
unsigned int user_remove(Table &t);
/*
int main() {
    cout << "Demonstrate very small table\n";
    Table t(5);
    t.put(7, "seven");
    t.put(9, "nine");
    t.put(17, "Seventeen");
    t.put(4, "four");
    t.put(36, "Thirty-six");
    cout << t;
    cout << "key accesses: " << Entry::access_count() << endl;
    
    cout << "\nNow demonstrate default size table\n";
    Table t2;
    Entry e;
    unsigned int count = 0;
    cout << "Enter up to 100 entries for a new table.\n"
        << "(enter 0 key and random data to quit)\n";
    do {
        cin >> e;
        if (e.get_key() == 0) break;
        t2.put(e);
        ++count;
    } while(count < 100);
    cout << t2;
    cout << "Try removing some entries (enter 0 to quit)\n";
    while (user_remove(t2) != 0)
        ;
    cout << t2;
    
    cout << "\nFinally demonstrate larger table\n";
    ifstream input;
    input.open("fips.txt");
    if (!input.good()) {
        cout << "No fips.txt in current directory. Quitting\n";
        return 1;
    }
    Table t3(3142, input);
    cout << "Try getting some entries by FIPS code keys\n"
        << "(enter 0 key to quit)\n";
    while (user_get(t3) != 0)
        ;
    cout << "Print large table to sortedfips.txt?\n";
    char ans;
    cin >> ans;
    if (ans == 'Y' || ans == 'y') {
        unsigned int start = Entry::access_count();
        ofstream out;
        out.open("sortedfips.txt");
        out << t3;
        out.close();
        cout << "done writing to sortedfips.txt ... required "
             << Entry::access_count() - start << " accesses\n";
    }
    return 0;
}

unsigned int user_get(Table &t) {
    unsigned int key;
    cout << "Enter key to get:\n";
    cin >> key;
    if (key != 0) {
        unsigned int start = Entry::access_count();
        cout << "data at key " << key << ": " << t.get(key) << endl;
        cout << "(accesses: " <<
            Entry::access_count() - start << ")\n";
    }
    return key;
}

unsigned int user_remove(Table &t) {
    unsigned int key;
    cout << "Enter key to remove:\n";
    cin >> key;
    if (key != 0) {
        unsigned int start = Entry::access_count();
        if (t.remove(key))
            cout << "removed key: " << key << endl;
        else
            cout << "did not find key: " << key << endl;
        cout << "(accesses: "
            << Entry::access_count() - start << ")\n";
    }
    return key;
}
*/
/*
int main() {

    Table *t = new Table(2);
    t->put(1, "one");
    t->put(2, "two");
    t->put(3, "three");
    t->remove(2);
    cout << *t << endl;
    delete t;
    cout << Entry::instance_count() << endl;

    cout << "\nTable 2:" << endl;
    Table *t2 = new Table(5);
    t2->put(1, "one");
    t2->put(2, "two");
    t2->put(3, "three");
    t2->put(4, "four");
    t2->put(5, "five");
    t2->put(6, "six");
    cout << *t2 << endl;

    cout << "instances:  " << Entry::instance_count() << endl;

    Table t3;// = *t2;
            t3= *t2;
   // cout << t3;
  
    t3 = *t2;
    cout << &t3 << endl;
    cout << "Table 3:\n" << t3 << endl;
    cout << Entry::instance_count() << endl;

    t2->remove(2);
    t2->remove(1);
    cout << "Removed some from Table 2\n" << *t2 << endl;
    cout << Entry::instance_count() << endl;
    
    
    *t2 = t3;
    cout << Entry::instance_count() << endl;
    cout << "Table 2: " << endl;
    cout << *t2 << endl;
    cout << "Table 3: " << endl;
    cout << t3 << endl;
    
    delete t2;
    cout << Entry::instance_count() << endl;
    cout << t3 << endl;

    
    cout << "\n\n" << endl;
    Table *t4 = new Table(5);
    t4->put(1, "one");
    t4->put(2, "two");
    t4->put(3, "three");
    t4->put(4, "four");
    t4->put(5, "five");
    t4->put(6, "six");
    
    
    Table t5(*t4);
    cout << Entry::instance_count() << endl;
    cout << *t4 << endl;
    t5.remove(3);
    t5.remove(2);
    cout << Entry::instance_count() << endl;
 
}
*/

int main() {
    Table *t1 = new Table(3);
    t1->put(10, "ten");
    t1->put(32, "thirty-two");
    t1->put(5, "five");
    
    cout << "Instances after making three:" << endl;
    cout << Entry::instance_count() << endl;
    
    delete t1;
    cout << "Instances after deleting three:" << endl;
    cout << Entry::instance_count() << endl;
    
    Table *t2 = new Table(3);
    t2->put(10, "ten");
    t2->put(32, "thirty-two");
    t2->put(5, "five");
    
    cout << "\nInstances after making three:" << endl;
    cout << Entry::instance_count() << endl;
    Table t3 = *t2;
    cout << "Instances after using assignment operator of the three:" << endl;
    cout << Entry::instance_count() << endl;
    
    t2->remove(10);
    t2->remove(5);
    cout << "Instances after deleting two from one table" << endl;
    cout << Entry::instance_count() << endl;
    t3.remove(10);
    cout << "Instances after deleting one from the other table:" << endl;
    cout << Entry::instance_count() << endl;
    
    delete t2;
    
    cout << "Instances after deleting t2:" << endl;
    cout << Entry::instance_count() << endl;
}