// ptrtest2.c
// tests printTable and sortValues functions

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "ptrfuncs.h"

double *get(const char *filename, int n);

int main(int argc, char *argv[]) {
    using namespace std;
    
    int n; // number of values to process
    double *p; // to point at first value
    int perRow; // number of values to print per row
    
    if (argc < 4) {
        cout << "usage: " << argv[0] << " filename n perRow\n";
        return 1;
    }
    n = atoi(argv[2]);
    p = get(argv[1], n);
    perRow = atoi(argv[3]);
    
    if (p == 0) {
        cout << "could not read " << argv[1] << endl;
        return 2;
    }
    
    cout << "Processing first " << n
        << " values from " << argv[1] << ".\n";
    
    int half = n / 2;
    int rest = n - half;

    cout << "first " << half << " values:\n";
    printTable(p, half, perRow);
    cout << "last " << rest << " values:\n";
    printTable(p + rest - 1, rest, perRow);

    cout << "all values in sorted order:\n";
    sortValues(p, p + n - 1);
    printTable(p, n, perRow);
    
    delete [] p;
    return 0;
}

double *get(const char *filename, int n) {
    using std::ifstream;
    ifstream in;
    in.open(filename);
    if (in.fail())
        return 0;
    double *data = new double[n];
    for (int i = 0; i < n; i++)
        in >> *(data + i);
    return data;
}


