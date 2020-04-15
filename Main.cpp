//George Vargas
//CECS 282-07
//Prog 1-Solitaire Prime
//Feb 12, 2020
#include <iostream>
#include "Card.h"
#include "Deck.h"
using namespace std;

/**
*Create your own function called "isPrime" (cannot use C++ library function). One is not a prime number.
*/
bool isPrime(int num) {
    /*
    bool prime = true;
    if (num == 1 || num % 2 == 0 || num % 3 == 0 || num % 5 == 0 || num % 7== 0 || num % 11 == 0 || num % 13 == 0) {
        prime= false;
    }
    if (num == 2 || num == 3 || num == 5 || num == 7 || num == 11 || num == 13) {
        prime = true;
    }
    return prime;
    */
    if (num <= 1)
        return false;
    for (int i = 2; i < num; i++)
        if (num % i == 0)
            return false;
    return true;
}
/*
*This function deals out the cards and checks if the piles are prime.
*/
void play(Deck deck) {
    Card card;
    int sum = 0;
    int piles = 0;

    while (deck.cardsLeft()!= 0) {
        //Take the top card from the deck.
        card = deck.deal();
        //Display the card using 2 feilds.
        card.showCard();
        //This returns the point value of the card and adds them into sum.
        sum += card.getValue();
        //If the sum is not prime, take the next card from the top of the deck.

        //When you aquire a Prime pile, print out the value (prime number) and start over on the next line.
        if (isPrime(sum)) {
            cout << "Prime: " << sum << "\n";
            sum = 0;
            piles++;
        }
        //If the last card from the deck gives you a prime pile, then you win.
        if (deck.cardsLeft() == 0 && sum == 0)
            cout << "\nWinner in " << piles << " piles!\n";
        //If the last card from the deck does not give you a prime pile, then you lose.
        if (deck.cardsLeft() == 0 && sum != 0)
            cout << "Loser\n";
    }
    cout << "There are no more cards to deal, start a new deck.\n"; 
}

/**
*The main runs the entire program.
*/
int main() {

    int choice=0;
    Deck deck;
    
    while (choice!=5) {
        cout << "\nWelcome to Solitaire Prime!\n1) New Deck\n2) Display Deck\n3) Shuffle Deck"
            "\n4) Play Solitaire Prime\n5) Exit\n";
        cin >> choice;

        switch (choice) {
            //This will create an unshuffled deck in the following order: Spades, Hearts, Diamonds, Clubs...Ace, 2, 3,..., 10, Jack, Queen, King.
        case 1:
            cout << "\nThe deck of cards has been reorganized.\n";
            deck.refreshDeck();
            break;
            //This will display all cards in a grid: 13 columns by 4 rows.
        case 2:
            cout << "\nThe game's current deck of cards.\n";
            deck.showDeck();
            break;
            //This will randomly shuffle all the cards in the deck.
        case 3:
            cout << "\nThe deck of cards has been shuffled.\n";
            deck.shuffle();
            break;
            //This will play the game as described above.
        case 4:
            cout << "\nYour deck of cards.\n";
            deck.showDeck();
            cout << "\nYour hand has been dealt, goodluck!\n";
            play(deck);
            break;
            //This will exit the program.
        case 5:
            cout << "\nThank you for playing Solitaire Prime!\n";
            break;
        }
    }
    return 0;
}