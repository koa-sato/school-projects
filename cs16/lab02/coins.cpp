// Kekoa Sato, Avi Loschak
// 10/7/15
 
 #include <iostream>
 using namespace std;
 
 int main()
 {
   int numQuarters, numDimes, numNickels, total;
   
   cout << "Enter number of quarters:" << endl;
   cin >> numQuarters;
   cout << "Enter number of dimes:" << endl;
   cin >> numDimes;
   cout << "Enter number of nickels:" << endl;
   cin >> numNickels;
   
   total = numQuarters * 25 + numDimes * 10 + numNickels * 5;
   cout << "The coins are worth " << total << " cents." << endl;
 
     return 0;
 }
