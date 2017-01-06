// ptrtest1.cpp
// tests sum, maxPtr, minPtr and valueDiff functions

#include <iostream>
#include "ptrfuncs.h"

int main() {
    using namespace std;
    double x[] = {
        406.94, 198.63, 961.99, 238.36, 910.21, 188.81, 467.37, 639.6,
        125.1, 581.16, 144.5, 354.07, 812.45, 716.26, 150.35, 753.4,
        387.7, 491.69, 788.64, 624.17, 263.02, 545.16, 908.81, 829.42,
        287.31, 913.75, 811, 245.32, 997.68, 701.87, 806.56, 76.68,
        368.48, 792.79, 645.42, 868.44, 87.5, 702.63, 403.33, 698.98,
        772.66, 793.88, 678.93, 37.28, 328.28, 893.33, 80.62, 721.98,
        213.74, 251.96, 375.7, 18.64, 541.57, 117.97, 315.98, 136.18,
        743.54, 519.56, 863.66, 359.53, 340.57, 283.71, 908.8, 600.22,
        620.95, 684.85, 479.14, 210.61, 685.58, 23.42, 466.19, 641.73,
        985.22, 803.12, 139.89, 106.97, 463.64, 575.13, 461.76, 572.48
    };
    int nx = (sizeof x) / sizeof(double);  // total number of values
    int half = nx / 2;
    
    double *first = x;
    double *max, *min;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "results for whole set of values:\n";
    cout << "  sum = " << sum(first, nx) << endl;
    max = maxPtr(first, nx);
    cout << "  max = " << *max
        << ", at position " << max - first << endl;
    min = minPtr(first, nx);
    cout << "  min = " << *min
        << ", at position " << min - first << endl;
    cout << "  range = " << valueDiff(max, min) << endl;
    
    cout << "results for first half of values:\n";
    cout << "  sum = " << sum(first, half) << endl;
    max = maxPtr(first, half);
    cout << "  max = " << *max
        << ", at position " << max - first << endl;
    min = minPtr(first, half);
    cout << "  min = " << *min
        << ", at position " << min - first << endl;
    cout << "  range = " << valueDiff(max, min) << endl;
    
    cout << "results for second half of values:\n";
    cout << "  sum = " << sum(first + half, half) << endl;
    max = maxPtr(first + half, half);
    cout << "  max = " << *max
        << ", at position " << max - first << endl;
    min = minPtr(first + half, half);
    cout << "  min = " << *min
        << ", at position " << min - first << endl;
    cout << "  range = " << valueDiff(max, min) << endl;
    
    return 0;
}

