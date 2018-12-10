// Fig. 18.2: fig 18_02.cpp from C++ How to Program - Deitel - 4th Ed.
// Card shuffling and dealing program using structures.
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::right;

#include <iomanip>

using std::setw;

#include <cstdlib>
#include <ctime>

// Card structure definition
struct Card {
	char *face;
    char *suit;
}; // end structure Card    

void fillDeck(Card * const, char *[], char *[]);
void shuffle(Card * const);
void deal(Card * const);

void main() {
	Card deck[52];
	char *face[] = { "Ace", "Deuce", "Three", "Four",
		"Five", "Six", "Seven", "Eight", "Nine", "Ten",
		"Jack", "Queen", "King" };
	char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	srand(time(0));  // randomize 
	
	fillDeck(deck, face, suit);
	
	shuffle(deck);
	
	deal(deck);
	
	system("pause");

} // end main

// place strings into Card structures
void fillDeck(Card * const wDeck, char *wFace[], char *wSuit[]){
	for (int i = 0; i < 52; i++) {
		wDeck[i].face = wFace[i % 13];
		wDeck[i].suit = wSuit[i / 13];
	} // end for
} // end function fillDeck

// shuffle cards
void shuffle(Card * wDeck){
	for (int i = 0; i < 52; i++) {
		int j = rand() % 52;
		Card temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	} // end for
} // end function shuffle

// deal cards
void deal(Card * const wDeck){
	for (int i = 0; i < 52; i++) 
		cout << right << setw(5) << wDeck[i].face << " of " << left << setw(8) << wDeck[i].suit
			<< ((i + 1) % 2 ? '\t' : '\n');
} // end function deal
