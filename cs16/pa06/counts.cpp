// counts.cpp - counts characters
// Kekoa Sato, Avi Loschak 11/09/2015

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "common.h"

using namespace std;

void getInput(int ascii[], int &count, istream& in);
void printOutput(int ascii[], int count, ostream& out);
void getFile(int ascii[], int &count, string name);
void writeFile(int ascii[], int count, string name);
void checkOutputFile(string fileName);

int main(int argc, char *argv[]) {
    
    int ascii[NUM] = {0};
    int count = 0;
    bool write = false;
    if (argc < 2) {
        getInput(ascii, count, cin);
        printOutput(ascii, count, cout);
    }
    else if (argv[1][0] == '-' && argv[1][1] == 'o') {
        if (argc <= 2) {
           cout << "missing output file" << endl;
           exit(1);
       }
        string name = argv[2];
        checkOutputFile(name);
        getInput(ascii, count, cin);
        writeFile(ascii, count, name);
    }
    else {
        string name;
        for (int i = 1; i < argc; i++) {
            name = argv[i];
            if (!name.substr(0, 2).compare("-o")) {
                if (argc <= i + 1) {
                    cout << "missing output file" << endl;
                    exit(1);
                }
                name = argv[i + 1];
                i = argc;
                write = true;
            }
            if (!write)
                getFile(ascii, count, name);
        }
        if (write)
            writeFile(ascii, count, name);  
        else 
            printOutput(ascii, count, cout);  
    }
    return 0;
}

void getInput(int ascii[], int &count, istream& in) {
    char letter;
    while (!in.eof()) {
        in.get(letter);
        if (!in.eof()) {
            ascii[static_cast<int>(letter)]++;
            count++;
        }
    }
}

void printOutput(int ascii[], int count, ostream& out) {
    prHeader(out);
    int i = 0;
    for (i = 0; i < FIRST; i++) {
        if (ascii[i] > 0) {
            prCountStr(out, i, symbols[i], ascii[i]);
        }
    }

    for (i = FIRST; i <= LAST; i++) {
        if (ascii[i] > 0) {
            prCountChr(out, i, static_cast<char>(i), ascii[i]);
        }
    }
    if (ascii[i] > 0)
        prCountStr(out, i, symbolDel, ascii[i]);

    prTotal(out, count);
    
}

void getFile(int ascii[], int &count, string name) {
    ifstream fin;
    if (!name.substr(0,1).compare("-") && name.substr(1,2).compare("o")) {
        cout << "bad option: " << name << endl;
        exit(1);
    }
    fin.open(name.c_str());
    if (fin.fail()) {
        cout << "bad file: " << name << endl;
        exit(1);
    }
    getInput(ascii, count, fin);
    fin.close();
}

void writeFile(int ascii[], int count, string name) {
    ofstream fout;
    fout.open(name.c_str());
    if (fout.fail()) {
        cout << "bad file: " << name << endl;
        exit(1);
    }
    printOutput(ascii, count, fout);
    fout.close();
}

void checkOutputFile(string fileName) {
    ofstream outFile;
    outFile.open(fileName.c_str());
    if (outFile.fail()) {
        cout << "bad file: " << fileName << endl;
        exit(1);
    }
    outFile.close();
}
