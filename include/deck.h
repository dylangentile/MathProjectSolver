#pragma once
#include <vector>
#include <string>
#include <deque> 


typedef struct{
	int suit; //0,1,2,3 spades, hearts, clubs, diamonds
	int value; //1 - Ace,2,3..10, 11-Jack, 12- Queen, 13 - King
	char name;
}Card;

class Deck{
public:
	Deck();
	~Deck();
	Card *cardArray;
	int sample;
	std::string retMsg;
	void deckInit();  
	void drawprob(int choose, int whichsuit, int whichvalue); //a -1 value means it can be any suit/value
private:
	void sequencedDraw(int &numerator, std::deque<int> &taken, int nesting, int whichsuit, int whichvalue);
};
