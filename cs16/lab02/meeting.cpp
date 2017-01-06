// Avi Loschak, Kekoa Sato
// 10/7/15

#include <iostream>
using namespace std;

int main () {

  int roomCap, numPeople, excess;

  cout << "Enter maximum room capacity:\n";
  cin >> roomCap;
  cout << "Enter number of people present:\n";
  cin >> numPeople;
  excess = numPeople - roomCap;

  if (numPeople <= roomCap)
    cout << "Meeting is legal.\n";
  else
    cout << "Meeting cannot be held unless " << excess << " leave." << endl;

  return 0;
}
