// Kekoa Sato
// 10/14/15

#include <iostream>
using namespace std;

int main () {

    bool done = false;
    int numTriangles = 0, size = 0;

    // Asks user for input repeatedly until the input is valid.
    while (!done) {
        cout << "enter number and size of triangles\n";
        cin >> numTriangles >> size;

        if (numTriangles <= 0 || numTriangles >= 5) {
            cout << "number must be between 1 and 4\n";
        }
        if (size <= 0) {
            cout << "size must be greater than 0\n";
        }
        if (size > 0 && (numTriangles > 0 && numTriangles < 5)) 
            done = true;
    }

    // Outer loop that essentially prints the rows for the triangles.
    for (int row = 1; row <= size; row++) {
        for (int col = 1; col <= size; col++) {
            if (col <= row)
                cout << "*";
        }
        // If the user wants at least two triangles print second triangle.
        // First for loop is for spaces, second is for *'s
        if (numTriangles >= 2) {
            cout << " ";
            for (int col = 1; col <= size; col++) {
                if (col > row)
                    cout << " ";
            }

            for (int col = size; col > 0; col--) {
                if (col >= row)
                    cout << "*";
            }
        }
        // If user wants at least 3 triangles, print third triangle.
        // First for loop is for first triangle of spaces, second for loop
        // is for second for loop of spaces, third for loop is for *'s
        if (numTriangles >= 3) {
            cout << " ";
            for (int col = size; col > 0; col--) {
                if (col < row)
                    cout << " ";
            }
            for (int col = size; col > 0; col--) {
                if (col < row)
                    cout << " ";
            }

            for (int col = 1; col <= size; col++) {
                if (col >=row)
                    cout << "*";
            }
        }
        // If user wants at least 4 triangles, print fourth traingle.
        // First for loop is for spaces, second for loop is for *'s
        if (numTriangles >= 4) {
            cout << " ";
            for (int col = size; col > 0; col--) {
                if (col > row)
                    cout << " ";
            }

            for (int col = size; col > 0; col--) {
                if (col <= row)
                    cout << "*";
            }
        }
        cout << endl;
    }
    return 0;
}