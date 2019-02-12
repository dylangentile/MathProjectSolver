//PROBLEM 1 of PROJECT-6
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
  
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 13; j++){
      cardArray[(i*13)*j].suit = i;
      cardArray[(i*13)*j].value = j+1; 
    }
  }
  
  for(int i =0; i < 52; i++){
    cout << cardArray[i].value << ":" << cardArray[i].suit << "\n";
  }
  
}

