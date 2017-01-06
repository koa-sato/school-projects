// Kekoa Sato, John Rehbein, 05/04/16
// buggy2.cpp - uses class BankAccount

#include <iostream>
#include "bankaccount.h"
using namespace std;

int main( )
{
    BankAccount account1, account2;
    BankAccount *accountPointer;

    cout << "Start of Test:\n";

    account1.set(123, 99, 3.0);
    cout << "account1 initial statement:\n";
    account1.output(cout);

    account1.set(100, 5.0);
    accountPointer = &account1;
    cout << "account1 with new setup:\n";
    accountPointer->output(cout);
    //delete accountPointer;

    account1.update( );
    cout << "account1 after update:\n";
    account1.output(cout);

    account2 = account1;
    accountPointer = &account2;
    cout << "account2:\n";
    account2.output(cout);

    return 0;
}
