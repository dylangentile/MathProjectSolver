//PROBLEM 1
#include "deck.h"
#include <iostream>
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
	string representation = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cardArray = new Card[52];
	int x = 0;
	for(int i = 0; i < 4; i++)
  	{
		for(int j = 0; j < 13; j++)
		{
			cardArray[x].suit = i;
			cardArray[x].value = j+1; //counting from one allows the cardvalues to match real life and not be all one less
			cardArray[x].name = representation[x];
			x++; 
		}
	}
  
}

void 
Deck::sequencedDraw(int &numerator, deque<int> &taken, int nesting, int whichsuit, int whichvalue){

	for(int i = 0; i < 52; i++){
		deque<int>::iterator it;
		bool skip = false;
		for(it = taken.begin(); it != taken.end(); it++){
			if(*it == i){
				skip = true;
				break;
			}
		}
		if(!skip){
			taken.push_back(i);
			retMsg.push_back(cardArray[i].name);
			if(nesting > 0){			
				sequencedDraw(numerator, taken, (nesting - 1), whichsuit, whichvalue);
			}
			if(whichsuit == -1 && whichvalue == -1)
			{
				
				numerator = 100;
				break;
			}
			else if(whichsuit == -1 || whichvalue == -1)
			{
				if(whichsuit == -1)
				{
					if(whichvalue == cardArray[i].value){
						numerator++;
	                    retMsg += " <----";
					}

				}
				else if(whichvalue == -1)
				{
					if(whichsuit == cardArray[i].suit){
						numerator++;
	                    retMsg += " <----";
					}
				}
			}
			else
			{
				if(whichsuit == cardArray[i].suit && whichvalue == cardArray[i].value){
					numerator++;
	                retMsg += " <----";

				}
			}



		}





		taken.pop_back();

	}

}
void
Deck::drawprob(int choose, int whichsuit, int whichvalue){ //a -1 value means it can be any suit/value
	deque<int> taken;
	int numerator = 0;


	int denominator = factorial(sample, sample - choose);

	choose--;

	for(int i = 0; i < 52; i++)
	{
		taken.push_back(i);
		retMsg.push_back(cardArray[i].name);
		if(choose > 0)
		{
			sequencedDraw(numerator, taken, (choose - 1), whichsuit, whichvalue);
		}
		if(whichsuit == -1 && whichvalue == -1)
		{
			
			numerator = denominator;
			break;
		}
		else if(whichsuit == -1 || whichvalue == -1)
		{
			if(whichsuit == -1)
			{
				if(whichvalue == cardArray[i].value){
					numerator++;
                    retMsg += " <----";
				}

			}
			else if(whichvalue == -1)
			{
				if(whichsuit == cardArray[i].suit){
					numerator++;
                    retMsg += " <----";
				}
			}
		}
		else
		{
			if(whichsuit == cardArray[i].suit && whichvalue == cardArray[i].value){
				numerator++;
                retMsg += " <----";

			}
		}
		retMsg.push_back('\n');
		taken.pop_back();
	}

	double probabilty = (double)numerator/(double)denominator;
	cout << retMsg << "\n\nThe chance of getting this is: \n" << probabilty * 100 << "%" << " or " << numerator << "/" << denominator << "\n";
	string input;
	cout << "\n\n(CONFIRM)$";
	getline(cin, input);
}

