#pragma once
#include <vector>
#include <string>
#include <deque> 
#include <map>


typedef struct{
	int suit; //0,1,2,3 spades, hearts, clubs, diamonds
	int value; //1 - Ace,2,3..10, 11-Jack, 12- Queen, 13 - King
	std::string name;
}Card;

class Deck{
public:
	std::map<char, std::string> nameMap;
	Deck();
	~Deck();
	std::vector<Card> cardArray;
	int sample;
	std::string retMsg;
	void deckInit(); 
	void dependentProb(int choose, int whichSuit, int whichNumber);
	void empericalEvidence(int choose, int whichSuit, int whichValue, int times);
private:
	void drawCombination(int &numerator, int choose);
};
