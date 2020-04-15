//George Vargas
//CECS 282-07
//Prog 1-Solitaire Prime
//Feb 12, 2020
#include "Card.h"
#include <iostream>
using namespace std;

/**
 * The default constructor.
 */
Card::Card() {
    rank = '?';
    suit = '?';
}

/**
 * The overloaded constructor.
 * @param r Rank
 * @param s Suit
 */
Card::Card(char r, char s) {

    rank = r;
    suit = s;
}

/**
 * This sets the card.
 * @param r Rank
 * @param s Suit
 */
void Card::setCard(char r, char s) {
    rank = r;
    suit = s;
}

/**
 * This casts the rank char type into an int value
 * @return This returns the numerical value of the card object.
 */
int Card::getValue() {

    if (rank < 11)
        return rank;
    else if (rank > 10)
        return 10;
}

/**
 * @return This returns the suit of the card object from Private suit
 */
char Card::getSuit() {
    return suit;
}

/**
 * This prints the card. Try to change from int rank to char rank.
 */
void Card::showCard() {
    
    if (rank == 1)
        cout << 'A' << getSuit() << " ";
    else if (rank == 11)
        cout << 'J' << getSuit() << " ";
    else if (rank == 12)
        cout << 'Q' << getSuit() << " ";
    else if (rank == 13)
        cout << 'K' << getSuit() << " ";
    else if (rank > 1 && rank < 11)
        cout << getValue() << getSuit() << " ";
     
}