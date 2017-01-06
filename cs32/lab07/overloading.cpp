// overloading.cpp -- for cs32 inheritance lab
// Kekoa Sato, John Rehbein, 05/18/16

#include <iostream>
using namespace std;

class Parent {

public:
  Parent() { age = 45; }

   void setAge(int years) { 
     cout << "SetAge method from Parent class" << endl;
     age = years;
   }

   int getAge() const { return age; }

   int increaseAge() { 
     cout << "This is Parent::increaseAge: My age: " << age
          << " And now I am one year older" << endl; 
     return age = age + 1;
   }

   void printAge() const { 
     cout << "This is my age:" << age << endl;
   }
 
protected:
   int age;
};

class Child : public Parent {

public:
   Child() { age = 7; }
  
   int change() {
      age = increaseAge();
      return age;
   }

   void setAge(int years) {
      age = years;
      Parent::setAge(years); 
      cout << "This is Child::setAge" << endl;
   }

   void printAge() const { 
      cout << "This is my age:" << Parent::age << endl;
   }
};

class Baby : public Parent {

public:
   Baby() { age = 2; months = 7;}
   
   int months;

   int increaseAge() { 
      cout << "This is Baby::increaseAge. I won't tell you my age,"
           << " because I have redifined my parent's function" << endl; 
      return age = age + 1;
   }

   int change() {
      age = increaseAge();
      return age;
   }

   void setAge(int years) {
      age = years;
      Parent::setAge(years); 
      cout << "This is Baby::setAge" << endl;
   }

   void setAge(int years, int monthCount) {
      age = years;
      cout << "This is Baby::setAge and I am overloaded ";
      printAge();
   }

   void printAge() {
      cout << "Baby::age: I am: " << age << " and " << months << " months" << endl;
   }
};

int main() {

  Baby B;

  B.setAge(2);

  B.printAge();

  B.Parent::printAge();

  /////////////////////

  B.increaseAge();

  B.printAge();

  B.Parent::printAge();

  ////////////////////
  
  B.setAge(3,5);

  B.printAge();

}

