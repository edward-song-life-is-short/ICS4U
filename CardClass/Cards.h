#ifndef CARDS_H
#define CARDS_H

#include <string>
#include <iostream>
using namespace std;

class Cards {
    //this should be Card - not CARDS
    //The deck is made of multiple card objects
    //I think my mic is broken
    public:
        Cards();
        Cards(int, int);

        Cards(const Cards& );

        Cards operator =(const Cards &);
        string operator <<(const Cards&);

		void printCards();

    private:
        int face, suit;
        const static string faceArr[13]; 
        const static string suitArr[4];
        const int SIZE_OF_DECK = 52;
};

#endif