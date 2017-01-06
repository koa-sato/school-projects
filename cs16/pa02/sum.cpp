// Kekoa Sato
// 10/07/15

#include <iostream>
using namespace std;

int main () {
  int amountNumbers, greaterThanZeroSum, lessThanZeroSum, numsGreaterThanZero,
    numsLessThanZero, temp, counter;

  greaterThanZeroSum = 0;
  lessThanZeroSum = 0;
  numsGreaterThanZero = 0;
  numsLessThanZero = 0;
  counter = 0;
 
  // Asks the user for amount of number to be inputted and keeps track of 
  // positive and negative totals. 
  cout << "How many numbers will you enter?\n";
  cin >> amountNumbers;
  // If the user says anything less than 0, the looping process is skipped.
  if (amountNumbers > 0) {
    cout << "Enter " << amountNumbers << " whole numbers while I count down.\n";
    while (amountNumbers > 0) {
      cout << "Entries left to go: " << amountNumbers << endl;
      cin >> temp;
      if (temp > 0) {
        greaterThanZeroSum += temp;
        numsGreaterThanZero++;
      }
      else if (temp < 0) {
        lessThanZeroSum += temp;
        numsLessThanZero++;
      }
      counter++;
      amountNumbers--;
    }

    // Outputs final results 
    cout << "The sum of " << numsGreaterThanZero <<
      " numbers greater than zero is " << greaterThanZeroSum << ".";
    cout << "\nThe sum of " << numsLessThanZero <<
      " numbers less than zero is " << lessThanZeroSum << ".";
    cout << "\nThe sum of all " << counter  << " numbers is " <<
      greaterThanZeroSum + lessThanZeroSum << ".\n";
  }
  // This is printed if the user initially stated that they wanted to sum
  // anything less than 1 number.
  else {
    cout << "There is nothing to sum.\n";
  }
    cout << "Goodbye.\n";
  
  return 0;
}
