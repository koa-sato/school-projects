// swaptest.cpp - tests function intswap for CS 16 lab

#include <iostream>
#include "intswap.chf"

int main() {
    using namespace std;
    
    int x, y;
    cout << "enter x and y:" << endl;
    cin >> x >> y;
    
    // first test by passing addresses of local variables
    cout << "now x is " << x << " and y is " << y << endl;
    intswap(&x, &y);
    cout << "after swap:\n    x is " << x << " and y is " << y << endl;
    
    // second test is for dynamically allocated data
    int *xsqrptr = new int(x * x), *ysqrptr = new int(y * y);
    cout << "\nnow copy of x squared is " << *xsqrptr
        << " and copy of y squared is " << *ysqrptr << endl;
    intswap(xsqrptr, ysqrptr);
    cout << "after swap:\n    copy of x squared is " << *xsqrptr
        << " and copy of y squared is " << *ysqrptr << endl;
    
    // free the dynamically allocated memory
    delete xsqrptr;
    delete ysqrptr;
    
    return 0;
}

