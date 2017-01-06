// Kekoa Sato 05/20/16
// stuff.cpp

#include <iostream>
#include "stuff.h"
#include <sstream>
#include <cmath>

Stuff::Stuff(string name, double height) : name(name), height(height) {};

string  Stuff::getName() const {
    return name;
}

double Stuff::getHeight() const {
    return height;
}

double Stuff::volume() const {
    return height;
}

string Stuff::toString() const {
    ostringstream oss;
    oss << getName() << ":height=" << getHeight();
    return oss.str();
}

ostream& operator<<(ostream &out, const Stuff &s) {
    out << s.toString();
    return out;
}

/*ostream& operator<<(ostream &out, vector<Stuff*> &v) {
    vector<Stuff *>::iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
        out << *it;
    }
    return out;

}*/

Rectangular::Rectangular(string name, double height, double width, double depth) : Stuff(name, height),
width(width), depth(depth) {}

double Rectangular::getWidth() const {
    return width;
}

double Rectangular::getDepth() const {
    return depth;
}

double Rectangular::volume() const {
    return getHeight() * getWidth() * getDepth();
}

string Rectangular::toString() const {
    ostringstream oss;
    oss << Stuff::toString();
    oss << ",width=" << getWidth() << ",depth=" << getDepth();
    return oss.str();
}

Cylindrical::Cylindrical(string name, double height, double diameter) : Stuff(name, height), diameter(diameter) {}

double Cylindrical::getDiameter() const {
    return diameter;
}

double Cylindrical::volume() const {
    double radiusSquared = pow((getDiameter()/2.0), 2.0);
    return getHeight()*(M_PI)*radiusSquared;
}

string Cylindrical::toString() const {
    ostringstream oss;
    oss << Stuff::toString();
    oss << ",diameter=" << getDiameter();
    return oss.str();
}