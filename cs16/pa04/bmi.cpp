// Kekoa Sato
// 10/21/2105
// This progerams calculates your bmi and tells you if you are 
// healthy or not

#include <iostream>
using namespace std;

// constants to convert pounds to kilograms and inches to meters
const double PPKG = 0.453592;
const double IPM = 0.0254;

// Calculates bmi using pounds and inches as parameters
double bmi (double pounds, double inches) {
    double kilos = pounds * PPKG;
    double meters = inches * IPM;
    return (kilos / (meters * meters));
}

// Series of functions to tell if the user is underweight, normal,
// overweight, or obese.
bool underweight (double bmi) {
    return bmi < 18.5;
}

bool normal (double bmi) {
    return bmi > 18.5 && bmi < 24.9;
}

bool overweight (double bmi) {
    return bmi > 25 && bmi < 29.9;
}

bool obese (double bmi) {
    return bmi >= 30;
}

// Function to print the info the way the assignment was asked.
void printInfo (double bmi) {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout << "BMI is " << bmi << endl;

    cout << "  Underweight? ";
    if (underweight(bmi))
        cout << "yes";
    else
        cout << "no";
    cout << endl;

    cout << "  Normal? ";
    if (normal(bmi))
        cout << "yes";
    else 
        cout << "no";
    cout << endl;

    cout << "  Overweight? ";
    if (overweight(bmi)) 
        cout << "yes";
    else
        cout << "no";
    cout << endl;

    cout << "  Obese? ";
    if (obese(bmi))
        cout << "yes";
    else
        cout << "no";
    cout << endl;
}

// Main function that calls above functions.
int main () {
    double b_m_i, pounds, inches;
    cout << "enter pounds and inches: " << endl;
    cin >> pounds >> inches;
    b_m_i = bmi(pounds, inches);
    printInfo(b_m_i);
    return 0;
}
