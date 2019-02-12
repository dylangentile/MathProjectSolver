#pragma once

typedef struct{
  int suit; //0,1,2,3 spades, hearts, clubs, diamonds
  int value; //1 - Ace,2,3..10, 11-Jack, 12- Queen, 13 - King
}Card;

class Deck{
public:
  Deck();
  ~Deck();
  void deckInit();  
  
};
