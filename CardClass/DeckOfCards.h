#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include "Cards.h"
#include <iostream>
#include <random>
//Trouble: How to 
//reference the card class without redefinition 
//in the main class

class DeckOfCards {
    public:
        DeckOfCards();

        void shuffle();
        Cards dealCard();
        bool moreCards();

        void deckPrint();

		static Cards * returnDeck();

    private:
        Cards deck[52];
        const int SIZE_OF_DECK = 52;
        int currentCard = 0;

};


#endif