//George Vargas
//CECS 282-07
//Prog 1-Solitaire Prime
//Feb 12, 2020
//These protect the header files.
#ifndef CARD_H
#define CARD_H

class Card {

//These create the suit & rank the cards.
private:
    char suit;
    char rank;

public:
    //Create a "blank" card.
    Card();
    //Constructor to create a card, setting the rank and suit.
    Card(char, char);
    //Set an existing blank card to  particular value.
    void setCard(char, char);
    //Display the card using 2 feilds...Ace of Spades: AS, Ten of Diamond: 10D, Queen of Heart: QH, Three of Club: 3C.
    void showCard();
    //This returns the suit of the card object from Private suit
    char getSuit();
    //Return the point value of the card. Ace=1, 2 through 10, Jack=10, Queen=10, King=10.
    int getValue();
};


#endif
