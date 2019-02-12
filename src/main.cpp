#include <iostream>
#include "deck.h"
using namespace std;


int main(int argc, char const *argv[])
{
  
  cout << "hello!\n\n";
  
  Deck *thedeck = new Deck;
  thedeck->deckInit();
  
  
  return 0;
  
  
  
}
