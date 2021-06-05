#include <iostream>
using namespace std;
#include <ctime>
#include <random>
#include <string>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

//function that creates a vector deck and returns the ordered deck
vector<string> createDeck()
{
    vector<string> deck;
    string suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    string faces[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    int counter = 0;

	//each card is a string, combined with the suit and face string
	//two for loops are used, one that iterates through the suits array and another one that iterates through the faces array
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            deck.push_back(faces[j] + " of " + suits[i]);
            counter++;
        }
    }

    return deck;
}

//this is a template function that shuffles any deck using the swap method and returns the shuffled deck
vector<string> shuffleDeck(vector<string> &orderedDeck)
{
    //srand initializes the rand() function
	srand(time(0));

    vector<string> shuffleDeck;
    shuffleDeck = orderedDeck;

    int randomN = 0;

	//a random number is generated in between 1 and 52 and it refers to a random index in the deck
	//in the ordered deck, the card that refers to the random index is swapped with the card that the index that the for loop iterates to
    for (int i = 0; i < shuffleDeck.size(); i++)
    {
        randomN = rand() % shuffleDeck.size();

        string temp = shuffleDeck[i];
        shuffleDeck[i] = shuffleDeck[randomN];
        shuffleDeck[randomN] = temp;
    }

    return shuffleDeck;
}

//create player deck, dealt through the common method where the top card of the deck is given to the player, computer, player, computer, etc
vector<string> playerCards(vector<string> &randomDeck)
{
    vector<string> player;
    vector<string> sortDeck;

    sortDeck = randomDeck;

	//all cards in the even index of the deck is given to the player
    for (int i = 0; i < 52; i++)
    {
        if (i % 2 == 0)
        {
            player.push_back(sortDeck[i]);
        }
    }

    return player;
}

//create computer deck, dealt through the common method where the top card of the deck is given to the player, computer, player, computer, etc
vector<string> computerCards(vector<string> &randomDeck)
{
    vector<string> computer;

    vector<string> sortDeck;
    sortDeck = randomDeck;

	//all cards in the odd index of the deck is given to the player
    for (int i = 0; i < 52; i++)
    {
        if (i % 2 != 0)
        {
            computer.push_back(sortDeck[i]);
        }
    }

    return computer;
}


//find out if card1 is bigger then card2, determines which card value is bigger
bool compareCard(string card1, string card2, vector<string> &suits, vector<string> &faces) {
	string card_1 = card1;
	string card_2 = card2;

	vector<string> suit;
	vector<string> face;

	suit = suits;
	face = faces;

	int card_1_face, card_1_suit;
	int card_2_face, card_2_suit;
	
	bool biggerCard1 = true;

	//determining the number values - 1 of the faces and assigning it to variables to be compared
	for (int k = 0; k < face.size(); k++)
	{
		//looks for the substring that matches a index in the face array and assigns the index value to a variable for card1 and card2
		if (card_1.find(face[k]) != string::npos)
		{
			card_1_face = k;
		}

		if (card_2.find(face[k]) != string::npos)
		{
			card_2_face = k;
		}
	}

	//comapre the number values of faces
	if (card_2_face > card_1_face)
	{
		biggerCard1 = false;
	}
	else if (card_2_face < card_1_face)
	{
		biggerCard1 = true;
	}
	else //if both cards have the same face value, compare suits
	{
		//same method used before as the faces
		for (int j = 0; j < suit.size(); j++)
		{
			if (card_1.find(suit[j]) != string::npos)
			{
				card_1_suit = j;
			}

			if (card_2.find(suit[j]) != string::npos)
			{
				card_2_suit = j;
			}
		}

		if (card_1_suit > card_2_suit)
		{
			biggerCard1 = true;
		}
		else
		{
			biggerCard1 = false;
		}
	}

	return biggerCard1;
}

//the cpu plays cards in the order of largest to smallest
vector<string>cpuBot(vector<string> computerHand, vector<string> suits, vector<string> faces) {
	string tempCard;
	bool biggerCard;	
	vector<string> computerCard;

	vector<string> suit, face;

	suit = suits;
	face = faces;

	computerCard = computerHand;
	

	//computer plays cards in order from strong to least
	//two for loops to compare different cards in the deck
	for (int i = 0; i < computerCard.size(); i++)
	{
		for(int k = i+1; k < computerCard.size(); k++) {
			//compares the card and the card after in the hand to see which is bigger
			biggerCard = compareCard(computerCard[i], computerCard[k], suit, face);
			
			//if the card after is bigger, swap positions with the card before
			if(!biggerCard) {
				tempCard = computerCard[i];
				computerCard[i] = computerCard[k];
				computerCard[k] = tempCard;
			}
		}
	}

	return computerCard;
}

//takes player input, the order of cards that they want to play
vector<int> playerInput(vector<string> selectCard) {
	int number;
	int cardCheck = 0;

	vector<string> playerHand;
	
	playerHand = selectCard;

	bool foundCard;

	foundCard = false;

	vector<int> play_order_card;

	//checks valid cards
	while (!foundCard)
	{
		//clear the order that the player wants to play to allow for new input
		play_order_card.clear();
		
		cardCheck = 0;

		cout << "Select the order of cards you want to play. For example, (1 2 3 4)" << endl;

		//take input through white spaces, player can type number values in the order of cards tha they want to play 
		for (int i = 0; i < selectCard.size(); i++)
		{
			cin >> number;
			play_order_card.push_back(number - 1);
		}

		for (int i = 0; i < play_order_card.size(); i++)
		{
			cardCheck++;

			//all these conditions need to be satisfied in order to play
			if (play_order_card[i] > 3 || play_order_card[i] < 0 || play_order_card.size() != selectCard.size())
			{
				cardCheck = 0;
				play_order_card.clear();
				foundCard = false;
				cout << "Please select the numbers displayed on the screen" << endl;
				break;
			}
		}

		if (cardCheck == 4)
		{
			foundCard = true;
		}
	}

	return play_order_card; 
}

//different conditional output when the player reaches certain stages of the game
void playerOutput(int condition, int rounds) {
	int state = condition;

	int round;

	round = rounds;

	if(condition == 1) {
		cout << "-------------------------------------" << endl;
		cout << "Round " << round << endl;
		cout << "-------------------------------------" << endl;
	}
	else if(condition == 2) {
		cout << "------------ Congratulations! You beat the computer! --------------" << endl;
	}
	else if(condition == 3) {
		cout << "------------ Sorry! You lost to the computer! --------------" << endl;
	}
	else if(condition == 4) {
		cout << "------------ The computer had to reshuffle the discard pile -------------" << endl;
	}
	else if(condition == 5) {
		cout << "-------------- You had to reshuffle the discard pile ------------------" << endl;
	}

}

//contains most of the game code and its calculatiosn
bool playerSelect(vector<string> &playerDeck, vector<string> &computerDeck, string *suits, string *faces, int gameMode)
{

    string *suitValue, *faceValue;
    vector<string> player_deck, computer_deck;

    suitValue = suits;
    faceValue = faces;

    player_deck = playerDeck;
    computer_deck = computerDeck;

    vector<string> selectCard;
    vector<string> computerCard;

    vector<string> p_discardPile;
    vector<string> c_discardPile;

    vector<string> suitValueVector, faceValueVector;

	vector<int> playerOrder;

    int playerValue = 0, computerValue = 0;

	int gameSelect = gameMode;

    int fixSize;

    bool player_winner = false, cpu_winner = false;

    int c_card_left;
    int p_card_left;

	bool playerWin = false;

    int rounds = 0;

	int p_condition = 0;

    string p_card, c_card;

    vector<string> shuffled_p_discard, shuffled_c_discard;

	vector<string> cpu1Hand;

	//switch the suits and faces array into a vector
    for (int i = 0; i < 13; i++)
    {
        faceValueVector.push_back(faceValue[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        suitValueVector.push_back(suitValue[i]);
    }
	
    while (!player_winner && !cpu_winner)
    {
		//rounds played
		rounds++;

		c_card_left = 4;
		p_card_left = 4;

		if(gameMode == 1) {
			playerOutput(1, rounds);
		}

		if (rounds != 1 && gameMode != 2)
		{
			//checks that computer can draw a hand of 4+ cards in both discard and their deck
			if (computer_deck.size() + c_discardPile.size() < 4)
			{
				playerOutput(2, rounds);
				player_winner = true;
				break;
			}

			//same as before but for player
			if (player_deck.size() + p_discardPile.size() < 4)
			{
				playerOutput(3, rounds);
				cpu_winner = true;
				break;
			}

			//if the deck runs out, shuffle the discard pile of the computer
			if (c_discardPile.size() > 0 && computer_deck.size() < 4)
			{
				playerOutput(4, rounds);
				//reshuffle time
				shuffled_c_discard = shuffleDeck(c_discardPile);

				for (int i = 0; i < c_discardPile.size(); i++)
				{
					computer_deck.push_back(shuffled_c_discard[i]);
				}

				//clear the discard pile deck because the cards are shuffled into the deck
				c_discardPile.clear();
			}
			//if the deck runs out, shuffle the discard pile of the player
			if (p_discardPile.size() > 0 && player_deck.size() < 4)
			{
				playerOutput(5, rounds);

				//reshuffle time
				shuffled_p_discard = shuffleDeck(p_discardPile);

				for (int i = 0; i < p_discardPile.size(); i++)
				{
					player_deck.push_back(shuffled_p_discard[i]);
				}
				//clear the discard pile deck because the cards are shuffled into the deck
				p_discardPile.clear();
			}
		}
		else if(rounds != 1 && gameMode == 2) {
			//this is the computer vs computer game play, it is the exact same code as the player vs computer
			if (computer_deck.size() + c_discardPile.size() < 4)
			{
				cout << "CPU 1 won in " << rounds << " rounds!" << endl;
				player_winner = true;
				break;
			}

			if (player_deck.size() + p_discardPile.size() < 4)
			{
				cout << "CPU 2 won in " << rounds << " rounds!" << endl;
				cpu_winner = true;
				break;
			}

			if (c_discardPile.size() > 0 && computer_deck.size() < 4)
			{
				//reshuffle time
				shuffled_c_discard = shuffleDeck(c_discardPile);

				for (int i = 0; i < c_discardPile.size(); i++)
				{
					computer_deck.push_back(shuffled_c_discard[i]);
				}

				c_discardPile.clear();
			}

			if (p_discardPile.size() > 0 && player_deck.size() < 4)
			{
				//reshuffle time
				shuffled_p_discard = shuffleDeck(p_discardPile);

				for (int i = 0; i < p_discardPile.size(); i++)
				{
					player_deck.push_back(shuffled_p_discard[i]);
				}

				p_discardPile.clear();
			}
		}

		//draw top 4 cards for the hand of each player
		for (int i = 0; i < 4; i++)
		{
			computerCard.push_back(computer_deck[i]);
			selectCard.push_back(player_deck[i]);
		}

		//erase the drawn elements from the deck
		computer_deck.erase(computer_deck.begin(), computer_deck.begin() + 4);
		player_deck.erase(player_deck.begin(), player_deck.begin() + 4);

		fixSize = selectCard.size();
		
		//output the cards in the player hand
		if(gameMode == 1) {
			for (int i = 0; i < selectCard.size(); i++)
			{
				cout << i + 1 << "." << selectCard[i] << endl;
			}

			playerOrder = playerInput(selectCard);
		}
		else {
			//order the deck according to computer bot
			cpu1Hand = cpuBot(selectCard, suitValueVector, faceValueVector);
			
		}
		//order computer hand largest to greatest
		computerCard = cpuBot(computerCard, suitValueVector, faceValueVector);


		for (int i = 0; i < fixSize; i++)
		{
			c_card = computerCard[i];
			
			if(gameMode == 1) {
				p_card = selectCard[playerOrder[i]];
			}
			else {
				p_card = cpu1Hand[i];
			}
			
			//compares player and computer card, if player win true, player wins the card round
			playerWin = compareCard(p_card, c_card, suitValueVector, faceValueVector);
			

			if(gameMode == 1) {
				cout << i + 1 << ". You: " << p_card << " -  Computer: " << c_card << ".";

				if(playerWin) {
					cout << "You win!" << endl;
				}
				else {
					cout << "The computer wins!" << endl;
				}
			
			}

			//push the cards that have been played into the respective discard piles
			if (playerWin)
			{
				p_discardPile.push_back(c_card);
				p_discardPile.push_back(p_card);
			}
			else
			{
				c_discardPile.push_back(p_card);
				c_discardPile.push_back(c_card);
			}
		}
		
		if(gameMode == 1) {
			cout << "Draw 4 more cards" << endl;
			cout << endl;
		}
		
		//reset values for the new hands
		selectCard.clear();
		computerCard.clear();
	}	

	return player_winner;
}

int main()
{
    bool playGame = true;
	int gameMode = 0;
	float playerWins = 0, cpuWins = 0;
	float wr;
	bool winner;

	string suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    string faces[13] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};

	vector<string> shuffler, fullDeck, playerDeck, computerDeck;

		//main menu
		while(playGame) {
			cout << "****************************************" << endl;
			cout << "Welcome to ICS4U War Game" << endl;
			cout << "****************************************" << endl;

			cout << endl;

			cout << "Select game mode (1 2 3):" << endl;

			cout << "1. Player vs Computer" << endl;

			cout << "2. Computer vs Computer" << endl;

			cout << "3. Exit Game" << endl;

			cin >> gameMode;
			

			if(gameMode == 3) {
				break;
			}

			shuffler = createDeck();
			vector<string> player_deck, computer_deck;

			//generating the decks for the player and computer
			fullDeck = shuffleDeck(shuffler);
			playerDeck = playerCards(fullDeck);
			computerDeck = computerCards(fullDeck);

			//push the cards into a vector to pass as an argument into the next function
			for (int i = 0; i < 26; i++)
			{
				player_deck.push_back(playerDeck[i]);
				computer_deck.push_back(computerDeck[i]);
			}

			//function returns boolean to check who wins the game
			winner = playerSelect(player_deck, computer_deck, suits, faces, gameMode);

			if(winner) {
				playerWins++;
			}
			else {
				cpuWins++;
			}

			if(gameMode == 1) {
				cout << "-------------------------------" << endl;
				cout << "Stats" << endl;
				cout << "-------------------------------" << endl;
				cout << "The computer won " << cpuWins << " times." << endl;
				cout << "The player won " << playerWins << " times." << endl;
				cout << "You have a " << floor(playerWins/(cpuWins + playerWins)* 100 + 0.5)/100 * 100 << "% win rate." << endl;
			}
			cout << "Do you want to play again? Select 1 to play or 0 to exit." << endl;

			cin >> gameMode;

			if(gameMode == 0) {
				playGame = false;
			}
		}
		
    return 0;
}