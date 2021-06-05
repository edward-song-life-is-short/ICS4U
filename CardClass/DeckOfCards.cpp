#include "DeckOfCards.h"

DeckOfCards::DeckOfCards() {
    int cardCount = -1;
	
	for(int suit = 0; suit < 4; suit++) {
        for(int face = 0; face < 13; face++) {
            cardCount++;
			Cards *temp = new Cards(suit, face);
			deck[cardCount] = *temp;
      		 
        }
    }
}

void DeckOfCards::deckPrint() {
    for(int i = 0; i < SIZE_OF_DECK; i++) {
        deck[i].printCards();
    }
}


Cards DeckOfCards::dealCard() {
    Cards top = deck[currentCard];
    currentCard++;
    return top;
}

bool DeckOfCards::moreCards() {
    if(currentCard != 52) {
        cout << currentCard;
        return true;
    }
    else {
        return false;
    }
}

void DeckOfCards::shuffle() {
    int index = 0;

    for(int i = 0; i < SIZE_OF_DECK; i++) {
        index = rand() %  51 + 0;
        
        Cards temp = deck[i];
        deck[i] = deck[index];
        deck[index] = temp;;

    }
}