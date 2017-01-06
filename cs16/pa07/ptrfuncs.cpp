// ptrfuncs.cpp
// Avi Loschak, Kekoa Sato 11/20/15

#include <iostream>
#include <iomanip> // to use setw
#include "ptrfuncs.h"

void sort(double *a, int numberUsed);
void swap(double &i, double &j);
int indexOfSmallest(double *a, int start, int numberUsed);

// IMPLEMENT ptrfuncs.h FUNCTIONS BELOW
double sum(double *values, int n) {
    double sum = 0, *i;
    for(i = values; i < values + n; i++) {
        sum += *(i);
    }
    return sum;
    
}
double *maxPtr(double *values, int n) {
    double *i, *max;
    max = values;
    for(i = values; i < values + n; i++) {
        if(*max < *i)
            max = i;
    }
    return max;
}  

double *minPtr(double *values, int n) {
    double *i, *min;
    min = values;
    for(i = values; i < values + n; i++) {
        if(*min > *i)
            min = i;
    }
    return min;
}

double valueDiff(double *left, double *right) {
     return *left - *right;
}

void printTable(double *values, int n, int perRow) {
    int counter = 0;
    double *i;
    for (i = values; i < values + n; i++) {
        std::cout << std::setprecision(2) << std::setw(10) << std::fixed << *i;
        counter++;
        if(counter % perRow == 0)
            std::cout << "\n";
    }
    if (counter % perRow != 0)
        std::cout << std::endl;
}

void sortValues(double *first, double *last) {
    double *i, *j;
    i = first;
    j = last;  
    sort(first, last - first + 1);
}

void sort(double *a, int numberUsed) {
    int indexOfNextSmallest;
    for (int index = 0; index < numberUsed - 1; index++) {
        indexOfNextSmallest = indexOfSmallest(a, index, numberUsed);
        swap(*(a + index), *(a + indexOfNextSmallest));
    }
}

void swap(double &i, double &j) {
    double temp;
    temp = i;
    i = j;
    j = temp;
}

int indexOfSmallest(double *a, int start, int numberUsed) {
    double min = *(a + start);
    int indexOfMin = start;

    for (int index = start + 1; index < numberUsed; index++) {
        if (*(a + index) < min) {
            min = *(a + index);
            indexOfMin = index;
        }
    }
    return indexOfMin;
}
