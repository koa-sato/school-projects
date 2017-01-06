// Kekoa Sato 
// 10/28/2015

#include <iostream>
using namespace std;

bool get_option();
void get_length(int &largeQuantity, int &smallQuantity);
double convert_to_big(int largeQuantity, int smallQuantity, int num);
void convert(double &quantity, int &largeConvert, int &smallConvert, double convFactor, int multiple);
void show_results(int largeQuantity, int smallQuantity);
bool askAgain();
bool feetToMeters = false;

int main () {
    int feet = 0, inches = 0, meters = 0, centimeters = 0;
    double dfeet, dmeters;
    bool again;

    do {
        feetToMeters = get_option();

        if (feetToMeters) {
            get_length(feet, inches);
            dfeet = convert_to_big(feet, inches, 12);
            convert(dfeet, meters, centimeters, .3048, 100);
            show_results(meters, centimeters);
        }
        else {
            get_length(meters, centimeters);
            dmeters = convert_to_big(meters, centimeters, 100);
            convert(dmeters, feet, inches, 3.2808399, 12);
            show_results(feet, inches);
        }   
        again = askAgain();
    } while (again);
    return 0;
}

bool get_option() {
    int option = 0;
    
    cout << "enter 1 for feet,inches to meters,centimeters, or\nenter 2 for meters,centimeters to feet,inches\n";
    do {
        cin >> option;
        if (option == 1)
            return true;
        else if (option == 2)
            return false;
        else{
            cout << "enter 1 or 2 only\n";
        }
    } while (option < 1 || option > 2);
    return false;
}

void get_length(int &largeQuantity,int &smallQuantity) {
    if (feetToMeters)
        cout << "enter feet and inches\n";
    else
        cout << "enter meters and centimeters\n";
    cin >> largeQuantity >> smallQuantity;
}

double convert_to_big(int largeQuantity, int smallQuantity, int num) {
    return largeQuantity + smallQuantity/static_cast<double>(num);
}

void convert(double &quantity, int &largeConvert, int &smallConvert, double convFactor, int multiple) {
    largeConvert = quantity * convFactor;
    smallConvert = (quantity * convFactor - largeConvert) * multiple;
}

void show_results(int largeQuantity, int smallQuantity) {
    if (feetToMeters)
        cout << "conversion: " << largeQuantity << " meters and " << smallQuantity << " centimeters";
    else
        cout << "conversion: " << largeQuantity << " feet and " << smallQuantity << " inches";
    cout << endl;
}

bool askAgain() {
    bool again = false;
    char response, extra;
    cout << "convert more?" << endl;
    cin >> response;
    do {
        cin.get(extra);
    } while (extra != '\n');
    if (response == 'y' || response == 'Y')
        again = true;
    return again;
}
