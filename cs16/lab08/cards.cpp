// cards.cpp - uses a structure that represents a playing card
// Avi Loschak, Kekoa Sato 12/02/2015

#include <iostream>
#include <algorithm>  // provides sort function
using namespace std;

// the card structure
struct Card {
    char suit;
    int face;
};

// array to help printing face values
string faces[] = {"", "", "deuce", "three", "four", "five",
    "six", "seven", "eight", "nine", "ten", "jack", "queen",
    "king", "ace"};

// function to help printing suit names
string suit(char s) {
    if (s == 'C') return "Clubs";
    if (s == 'D') return "Diamonds";
    if (s == 'H') return "Hearts";
    return "Spades";
}

// prototypes for functions YOU WILL DEFINE BELOW main
void printCard(Card c);
void printCards(Card cards[], int n);
bool cmpCard(Card c1, Card c2);

// DO NOT CHANGE main
int main() {
    
    // create and initialize an array of 5 cards
    Card cards[] = { {'S', 14}, {'H', 12}, {'D', 7},
        {'C', 7}, {'S', 11} };
    
    // test printCard by itself
    cout << "printing third card: \n";
    printCard(cards[2]);
    
    // test printCards now for first two cards, then whole array
    cout << "\nprinting first two cards:\n";
    printCards(cards, 2);
    cout << "\nprinting all cards, unsorted:\n";
    printCards(cards, 5);
    
    // depend on cmpCard to sort array; then print again
    sort(cards, cards + 5, cmpCard);
    cout << "\nprinting all cards, sorted:\n";
    printCards(cards, 5);
    
    return 0;
}

// COMPLETE THE FUNCTIONS BELOW

// prints c neatly, followed by a newline
void printCard(Card c) {
    cout << faces[c.face] << " of " << suit(c.suit) << endl;
}

// neatly prints first n cards on separate lines
void printCards(Card cards[], int n) {
    for(int i = 0; i < n; i++) {
        printCard(cards[i]);
    }
}

// returns true if face value of c1 is less than
// face value of c2; or if face values are equal,
// then returns true if c1 suit is less than c2
// suit; otherwise returns false
bool cmpCard(Card c1, Card c2) {
    if(c1.face < c2.face)
        return true;
    else if(c2.face < c1.face)
        return false;

    if(c1.suit < c2.suit)
        return true;
    else
        return false;
}

