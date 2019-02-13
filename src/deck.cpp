//PROBLEM 1
#include "deck.h"
#include <iostream>

using namespace std;


Deck::Deck(){
  
}
Deck::~Deck(){
  
}

void
Deck::deckInit(){
	Card *cardArray = new Card[52];
	int x = 0;
	for(int i = 0; i < 4; i++)
  	{
		for(int j = 0; j < 13; j++)
		{
			cardArray[x].suit = i;
			cardArray[x].value = j+1;
			x++; 
		}
	}
  
}

