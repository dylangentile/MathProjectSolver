//PROBLEM 1
#include "deck.h"
#include <random>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>

#include "function.h"

using namespace std;


Deck::Deck(){
	retMsg = "\nCombinations:\n";
}
Deck::~Deck(){
  
}


void
Deck::deckInit(){
	sample = 52;
	cardArray.clear();
	int x = 0;
	for(int i = 0; i < 4; i++)
  	{
		for(int j = 1; j < 14; j++)
		{
			Card tempCard;
			tempCard.suit = i;
			tempCard.value = j; //counting from one allows the cardvalues to match real life and not be all one less
			if(j == 1)
			{
					tempCard.name = "Ace of ";
			}
			else if(j >= 1 && j <= 10){
				stringstream ss;
				ss << j;
				string g;
				ss >> g;
				tempCard.name = g + " of ";
			}
			else if(j == 11){
				tempCard.name = "Jack of ";
			}
			else if(j == 12){
				tempCard.name = "Queen of ";
			}
			else if(j == 13){
				tempCard.name = "King of ";
			}
			else {
				tempCard.name = "Unknown of ";
			}


			if(i == 0){
				
				tempCard.name += "Spades";
			}
			else if(i == 1){
				tempCard.name += "Hearts";
			}
			else if(i == 2){
				tempCard.name += "Clubs";
			}
			else if(i == 3){
				tempCard.name += "Diamonds";
			}
			else {
				tempCard.name += "Unknown";
			}
			cardArray.push_back(tempCard);
			x++; 
		}
	}
  
}


void
Deck::drawCombination(int &numerator, int choose){

	for(int i = 0; i < cardArray.size(); i++)
	{
		Card theCard = cardArray.at(i);
		
	}

}



void 
Deck::dependentProb(int choose, int whichSuit, int whichValue){
/*
	for(vector<Card>::iterator it = cardArray.begin(); it != cardArray.end(); it++){
		Card theCard = *it;
		cout << theCard.name << "\n";
	}
*/
	choose--;
	int numerator;
	long long denominator = factorial(sample, sample - choose);

    

    for(int i = 0; i < sample; i++)
    {
   		
    	if(choose > 0){
    		drawCombination(numerator, choose -1);
    	}





    }


}

void Deck::empericalEvidence(int choose, int whichSuit, int whichValue, int times){
	int numerator = 0;
	int denominator = 0;
	for(int i = 0; i < times; i++){
		vector<Card> drawn;
		deckInit();
		random_shuffle(cardArray.begin(), cardArray.end());
		for(int q = 0; q < choose; q++){
			drawn.push_back(cardArray.back());
			cout <<	drawn.back().name;
			drawn.pop_back();
		}

		if(whichValue != -1 && whichSuit != -1)
		{
			for(vector<Card>::iterator it = drawn.begin(); it != drawn.end(); ++it)
			{
				Card tempCard = *it;
				cout << tempCard.name;
				if(tempCard.suit == whichSuit && tempCard.value == whichValue)
				{
					numerator++;
					break;
				}
				
			}
			denominator++;
			//cout << "\n";

		}	
		else if(whichValue == -1){
			if(drawn.size()== 0){
				cout << "sizeof 0";
			}
			if(drawn.size() == 1){
				cout << "choose 1";
				//Card acard = drawn.at(0);
				//if(acard.suit == whichSuit){
					//numerator++;
				//}
			}
			else
			{
				for(vector<Card>::iterator it = drawn.begin(); it != drawn.end(); ++it)
				{
					Card tempCard = *it;
					if(tempCard.suit == whichSuit)
					{
						numerator++;
						break;
					}
				}
			}
			denominator++;

		}
		else if(whichSuit == -1){
			for(vector<Card>::iterator it = drawn.begin(); it != drawn.end(); ++it)
			{
				Card tempCard = *it;
				cout << tempCard.name;
				if(tempCard.value == whichValue)
				{
					numerator++;
					break;
				}
			}
			denominator++;

		}
		else{
			cout << "\n????\n";
		}
		cout << "\n";
	}



	double chance = (double)numerator/(double)denominator;
	chance = chance * 100;
	cout << "\n\nAfter trying " << times << " times, I think the chance is:\n" << chance << "%" << " or " << numerator << "/" << denominator << "\n";
}

