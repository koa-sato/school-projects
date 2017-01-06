// common.h - include at start of counts.cpp
// Use the constants, symbols and functions herein to
// insure that your printed results exactly match our
// solution's results. Do not print by any other means.
//
// Do not change this file, and especially do not rely on any
// changes to it. You will not turn this file in.

#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <iomanip>
#include <cstdlib>

// global constants: number of different characters, and
//                   first and last printable characters
const int NUM = 128;
const int FIRST = '!';
const int LAST = '~';

// symbols for special characters, corresponding to codes 0 through FIRST-1
const char symbols[][4] = {"NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK",
    "BEL", "BS", "HT", "LF", "VT", "FF", "CR", "SO", "SI", "DLE", "DC1",
    "DC2", "DC3", "DC4", "NAK", "SYN", "ETB", "CAN", "EM", "SUB", "ESC",
    "FS", "GS", "RS", "US", "SPC" };

// symbol for DEL character, code LAST+1 (same as NUM-1)
const char symbolDel[4] = "DEL";

// the following four functions must be used to print results

// use prHeader at the start to print header row (titles)
void prHeader(std::ostream& out) {
    out << "Code\tChar\tCount\n----\t----\t-----\n";
}

// use prCountStr to print count for one of the special symbols
void prCountStr(std::ostream& out, int code, const char str[], int count) {
    out << std::setw(3) << code << '\t' << str << '\t'
        << std::setw(5) << count << std::endl;
}

// use prCountChr to print count for one of the printable characters
void prCountChr(std::ostream& out, int code, const char chr, int count) {
    out << std::setw(3) << code << '\t' << chr << '\t'
        << std::setw(5) << count << std::endl;
}

// use prTotal at the end to print total character count
void prTotal(std::ostream& out, int count) {
    out << "\t\t-----\nTotal\t\t"
        << std::setw(5) << count << std::endl;
}

// use the following three functions for part 2 error messages
// ignore these functions for part 1

// use badFile(name) to exit if a file (name) cannot be opened
void badFile(char name[]) {
    std::cout << "bad file: " << name << std::endl;
    std::exit(1);
}

// use badOption(op) if an invalid option (not '-o') is on command line
void badOption(char op[]) {
    std::cout << "bad option: " << op << std::endl;
    std::exit(2);
}

// use missing() if output filename is missing
void missing() {
    std::cout << "missing output file\n";
    std::exit(3);
}

#endif


