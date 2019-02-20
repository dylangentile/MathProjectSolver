//PROBLEM 1
#include "deck.h"
#include <random>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>
#include "progress_bar.hpp"


#include "function.h"

using namespace std;


Deck::Deck(){
	retMsg = "";
}
Deck::~Deck(){
  
}
void
Deck::preInit(bool verbosity){
	verbose = verbosity;
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
	//Progress *theProgress = new Progress;
	//theProgress->pInit(times);
	ProgressBar progress_bar(times, "Calculating");
	retMsg += "\n";
	int numerator = 0;
	int denominator = 0;
	for(int i = 0; i < times; i++){
		vector<Card> drawn;
		deckInit();
		random_shuffle(cardArray.begin(), cardArray.end());
		for(int q = 0; q < choose; q++){
			drawn.push_back(cardArray.back());
			retMsg += drawn.back().name;
			if(drawn.back().name.size() >= 16){
				retMsg += "\t";
			}
			else{
				retMsg += "\t\t";
			}
			cardArray.pop_back();
		}

		if(whichValue != -1 && whichSuit != -1)
		{
			for(vector<Card>::iterator it = drawn.begin(); it != drawn.end(); ++it)
			{
				Card tempCard = *it;
				//cout << tempCard.name;
				if(tempCard.suit == whichSuit && tempCard.value == whichValue)
				{
					retMsg += " \e[1m<-----\e[0m";
					numerator++;
					break;
				}
				
			}
			denominator++;
			progress_bar.Progressed(i);
			//theProgress->update();
			//cout << "\n";

		}	
		else if(whichValue == -1){
			for(vector<Card>::iterator it = drawn.begin(); it != drawn.end(); ++it)
			{
				Card tempCard = *it;
				if(tempCard.suit == whichSuit)
				{
					retMsg += " \e[1m<-----\e[0m";
					numerator++;
					break;
				}
			}
	
			denominator++;
			progress_bar.Progressed(i);
			//theProgress->update();


		}
		else if(whichSuit == -1){
			for(vector<Card>::iterator it = drawn.begin(); it != drawn.end(); ++it)
			{
				Card tempCard = *it;
				if(tempCard.value == whichValue)
				{
					retMsg += " \e[1m<-----\e[0m";
					numerator++;
					break;
				}
			}
			denominator++;
			progress_bar.Progressed(i);
			//theProgress->update();


		}
		else{
			retMsg += "\n????\n";
		}
		retMsg += "\n";
	}



	double chance = (double)numerator/(double)denominator;
	chance = chance * 100;
	if(verbose)
	{
		retMsg += "\n\nAfter trying " + to_string(times) + " times, I think the chance is:\n" + to_string(chance) + "%" + " or " + to_string(numerator) + "/" + to_string(denominator) + "\n";
	}
	else
	{
		retMsg = "\n\nAfter trying " + to_string(times) + " times, I think the chance is:\n" + to_string(chance) + "%" + " or " + to_string(numerator) + "/" + to_string(denominator) + "\n";
	}

	cout << retMsg;


}

