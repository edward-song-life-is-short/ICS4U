#include "Cards.h"
#include <iostream>

using namespace std;

const string Cards::faceArr[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

const string Cards::suitArr[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};


Cards::Cards() {
    suit = 0;
    face = 0;
}

Cards::Cards(int s, int f){
    suit = s;
    face = f;
}

void Cards::printCards() {
	cout << faceArr[face] + " of " + suitArr[suit] << endl; 
}

Cards::Cards(const Cards& c) {
    suit = c.suit;
    face = c.face;
}

string Cards::operator <<(const Cards &c) {
    return Cards::suitArr[c.suit - 1];
}

Cards Cards::operator =(const Cards &c) {
    suit = c.suit;
    face = c.face;

    return *this;
}



