//George Vargas
//CECS 282-07
//Prog 1-Solitaire Prime
//Feb 12, 2020
#include "Deck.h"
#include <iostream>
/**
*This header file contains definitions of functions to get 
*and manipulate date and time information.
*/
#include <time.h>
using namespace std;

/**
 * Default constructor, this calls newDeck method to create a Deck.
 */
Deck::Deck() {
    refreshDeck();
}

/**
 * @return This returns the amount of cards left.
 */
int Deck::cardsLeft() {
    return 52 - topCard;
}

/**
 * This creates a new deck of cards.
 */
void Deck::refreshDeck() {
    //topCard sets to the first card
    topCard = 0;
    int count = 0;
    char suits[] = { 'S', 'H', 'D', 'C' };

    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 13; j++) {
            //the count is the position of card
            //j is the value of the card
            pile[count].setCard(j, suits[i]);
            count++;
        }
    }
}

/**
 * This deals the card at the top of the deck.
 * @return The card dealt.
 */
Card Deck::deal() {
    topCard++;
    return pile[topCard - 1];
}

/**
 * This prints the deck.
 */
void Deck::showDeck() {
    int index=0;

    for (int i = 0; i < 4; i++) {
        //Error index was starting at 0 in the first two i=0,1 after j for loop
        index = 13 * i;
        for (int j = 0; j < 13; j++)
            pile[j + index].showCard();

        cout << "\n";
        
    }
}

/**
 * Create your own function to shuffle(cannot use the random_shuffle provided by C++).
 */
void Deck::shuffle() {

    srand(time(NULL));

    for (int i = 0; i < 1000; i++) {
        //Generates random numbers 0-51
        int ranNum1 = rand() % 52;
        int ranNum2 = rand() % 52;
        //store 0-51 number of ranNum1's value into temp
        Card tempNum = pile[ranNum1];
        //copy ranNum2's value to ranNum1's position
        pile[ranNum1] = pile[ranNum2];
        //store ranNum1's value to ranNum2's position
        pile[ranNum2] = tempNum;
    }
}