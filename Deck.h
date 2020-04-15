//These protect the header files.
#ifndef DECK_H
#define DECK
//George Vargas
//CECS 282-07
//Prog 1-Solitaire Prime
//Feb 12, 2020
#include "Card.h"

using namespace std;

class Deck
{
//This creates the array for the deck of cards.
private:
    Card pile[52];
    int topCard = 0;

public:
    //constructor which creates a deck of 52 cards. Ace of Spades on top, followed by the rest of the Spades in order, followed by Hearts, Diamonds and Clubs.
    Deck();
    //Reset the deck so it looks like a new deck.
    void refreshDeck();
    //Deal a card from the top of the deck.
    Card deal();
    //Shuffle the cards in the deck.
    void shuffle();
    //Show all the cards in the deck: 13 columns and 4 rows.
    void showDeck();
    //Return the number of cards left in the deck.
    int cardsLeft();
};

#endif
