// Kekoa Sato 05/20/16
// stuff.h

#ifndef STUFF_H
#define STUFF_H
#include <string>
#include <vector>

using namespace std;

class Stuff {
public:
    Stuff (string name = "", double height = 0);
    string getName() const;
    double getHeight() const;
    virtual double volume() const;
    virtual string toString() const;
    friend ostream& operator<<(std::ostream &out, const Stuff &s);   
    //friend ostream& operator<<(ostream &out, const vector<Stuff*> &v);
private:
    string name;
    double height;
};



class Rectangular : public Stuff {
public:
    Rectangular(string name, double height, double width, double depth);
    double getWidth() const;
    double getDepth() const;
    virtual double volume() const;
    virtual string toString() const;
private:
    double width;
    double depth;
};

class Cylindrical : public Stuff {
public:
    Cylindrical(string name, double height, double diameter);
    double getDiameter() const;
    virtual double volume() const;
    virtual string toString() const;
private:
    double diameter;
};
#endif