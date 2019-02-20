#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "deck.h"

using namespace std;




string inputter(string out){
	string input;
	cout << "\r(" << out << ")$";
	getline(cin, input);
	return input;
}

void problem1(bool logic, int prescision, bool verbose){
	Deck *thedeck = new Deck;
	thedeck->preInit(verbose);
	thedeck->deckInit(); 
	if(logic){
	thedeck->dependentProb(2, 1, -1);
	}
	else{
		thedeck->empericalEvidence(2, 1, -1, prescision);
	}
	delete thedeck;
	cout << "\n";
	string x = inputter("Again[n/Y]");
	if(tolower(x[0]) != 'n'){
		problem1(logic, prescision, verbose);
	}
}



void description(int what){
	ifstream ifs("../problems");
	string content((std::istreambuf_iterator<char>(ifs) ),
		(std::istreambuf_iterator<char>()));
	int length = content.length() - 1;
	int theit = 0;
	string thedescription;
	bool push = false;
	while(true){
		//cout << content[theit] << "\n";
		if(theit >= length){
			//thedescription = "\nCouldn't find a definition. :(\n";
			break;
		}
		if(push == true && content[theit] >= '0' && content[theit] <= '9'){
			push = false;
			break;
		}
		if(what < 10){
			if(what == content[theit] - '0'){
					push = true;
			}
        } else{
            string z;
            z.push_back(content[theit]);
            z.push_back(content[theit+1]);
            stringstream ss;
            ss << z;
            int comp;
            ss >> comp;
            if(what == comp){
                push = true;
                theit++;
                string h = to_string(what);
                thedescription.push_back(h[0]);
            }
            
        }
		if(push){
			thedescription.push_back(content[theit]);
		}
		theit++;
	}
	cout << "\n" << thedescription << "\n";
	inputter(" ");




}


int main(int argc, char const *argv[])
{

	string input;
	cout << "\t\t\t\t";
	string out = "Welcome!";
	for (int i=0; i<out.size(); ++i) 
	{
    	cout << out[i] << flush;
    	this_thread::sleep_for (chrono::milliseconds(35)); //completely pointless but 'cool'
  	}
	this_thread::sleep_for (chrono::milliseconds(200));
	while(true) //everything in here compensates for human error
	{
		cout << "\n\nProbability Problems:\n\n\t1)Cards\t\t2)CardsV2\t3)4_Coins\t4)ColorfulCards\n";
		cout << "\t5)Students\t6)3_Coins\t7)CardsV3\t8)3_Cards\n";
		cout << "\t9)Children\t10)4_Cards\t11)Tim&TomDice\t12)MARBLES!\n";
		cout << "\nEnter the problem number '1' followed by an arg. \n-d:description  -e:emperically  -l:logically\n(INPUT)$";
		getline(cin, input);
		int problemtodo = -1;
		bool logic = true;
		bool verbose = false;
		int prescision = 1000;
		if(input == "q" || input == "quit" || input == "exit")
		{
			break;
		}
		else if((input.size() == 1 && input[0] >= '1' && input[0] <= '9') || (input.size() == 2 && input[1] == ' '))
		{
			problemtodo = input[0] - '0';
			cout << "\n\nShall I solve 'e' EMPERICALLY or 'l' LOGICALLY?\n(e/l)$";
			getline(cin, input);
			while(input[0] != 'l' && input[0] != 'e'){
				cout << "\033[FPardon?\n";
				input = inputter("e/l");
			}
			if(input[0] == 'e'){
				logic = false;
			}
		}
		else if(input.size() == 2 && (input[0] >= '1' && input[0] <= '9' && input[1] >= '0' && input[1] <= '9'))
		{
			stringstream ss;
			ss << input;
			ss >> problemtodo;
			cout << "\n\nShall I solve 'e' EMPERICALLY or 'l' LOGICALLY?\n(e/l)$";
			getline(cin, input);
			while(input[0] != 'l' && input[0] != 'e'){
				cout << "\033[FPardon?\n";
				input = inputter("e/l");
			}
			if(input[0] == 'e'){
				logic = false;
			}
		}
		else
		{
			int length = 0;
			string temp;
			bool dodesc = false;
			while(length <= input.size()){
				if(input[length] >= '0' && input[length] <= '9'){
					temp.push_back(input[length]);
				}
				else if(input[length] == '-' /*&& (input[length+1] == 'd' || input[length+1] == 'l' || input[length+1] == 'e')*/){
					if(input[length+1] == 'd'){
						dodesc = true;
                        length++;
					}
					if(input[length+1] == 'e'){
						logic = false;
						string p = "";
                        while(input[length+2] >= '0' && input[length+2] <= '9'){
							p.push_back(input[length+2]);
							length++;
						}
						if(!p.empty()){
							stringstream ss;
							ss << p;
							ss >> prescision;
						}
                        length++;
					}
					if(input[length+1] == 'v'){
						verbose = true;
					}
				}
				else if(input[length] != ' ')
				{
					//cout << "\033[FPardon?\n";
					break;
				}
				length++;
			}
			//if(length == input.size()){
                stringstream ss;
                ss << temp;
                ss >> problemtodo;
				if(dodesc == true){
					description(problemtodo);
					problemtodo = -1;
				} 
				
			//}
		}
		

		if(verbose){
			cout << "verbosity";
		}
		if(problemtodo >= 1 && problemtodo <= 12){
			cout << "\n\nDoing " << problemtodo << ":";
			if(logic){
				cout << "logically\n";
				
			}
			else
			{
				cout << "emperically\n";
			}
			problem1(logic, prescision, verbose);

		}



	}


	cout << "\t\t\t\t";
	out = "Thank You!";
	for (int i=0; i<out.size(); ++i) 
	{
    	cout << out[i] << flush;
    	this_thread::sleep_for (chrono::milliseconds(35)); //completely pointless but 'cool'
  	}
	cout << "\n";

  	this_thread::sleep_for (chrono::milliseconds(200));

	return 0;
}
