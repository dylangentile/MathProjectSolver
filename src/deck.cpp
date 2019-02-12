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
  int x = 0;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 13; j++){
      cardArray[x].suit = i;
      cardArray[x].value = j+1;
	x++; 
    }
  }
  
  for(int i =0; i < 52; i++){
    if(cardArray[i].value == 1){
      cout << "ace";
    }
    else if(cardArray[i].value == 11){
      cout << "jack";
    }
    else if(cardArray[i].value == 12){
      cout << "queen";
    }
    else if(cardArray[i].value == 13){
      cout << "king";
    }else {
      cout << cardArray[i].value;
    }
    
    cout << " of ";
    if(cardArray[i].suit == 0){
      cout << "spades";
    }
    else if(cardArray[i].suit == 1){
      cout << "hearts";
    }
    else if(cardArray[i].suit == 2){
      cout << "clubs";
    }
    else if(cardArray[i].suit == 3){
      cout << "diamonds";
    }
    cout << "\n";
  }
  
}

