#include "Cards.h"
#include "DeckOfCards.h"
#include <iostream>
#include <array>



int main() {
    //DeckOfCards *deck1 = new DeckOfCards();
    DeckOfCards *d1 = new DeckOfCards();
	
    d1->shuffle();
    cout << endl;
    d1->deckPrint();

    for(int i = 0; i < 52; i++) {
        d1->dealCard().printCards();
    }

    cout << endl << "Card in deck status:" << d1->moreCards();

	delete d1;

	
}