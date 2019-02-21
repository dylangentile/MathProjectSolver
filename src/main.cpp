#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "deck.h"
#include "generic.h"

using namespace std;




string inputter(string out){
	string input;
	cout << "\r(" << out << ")$";
	getline(cin, input);
	return input;
}


void help(){


	cout << "\n\n\n\t------------------------Help------------------------\n";
	cout << "\t\t------------Solvers------------\n";
	cout << "\tArg\t|Description\n\n";
	cout << "\t-e\t  Emperical solver. Solves the problem through experience\n\t\tby choosing, recording, and starting again.\n\t\t --A number can be added after this ('-e10')\n\t\t  to specify repitions. Default(10000).\n\n";
	cout << "\t-l\t  Logical Solver. Solves the problem by calculating all\n\t\tcombinations and choosing the matching ones.\n\n";
	cout << "\t\t------------Flags------------\n";
	cout << "\tArg\t|Description\n\n";
	cout << "\t-v\t  Verbose. Prints all combinations or draws(-l/-e mode)\n\n";
	cout << "\t-d\t  Description. Prints the problem description.\n\t\tOverrides all other args.\n\n";
	cout << "\t-o\t  Old method. Will get the solution through a \n\t\tnon-(Generic Probability Libary) solver. [deprecated]\n\n";


	cout << "\t\t------------Commands-----------\n";
	cout << "\tCommand\t|Description\n\n";
	cout << "   quit/q/exit    Exits the program\n\n";
	cout << "\th/help\t  Conjures the help menu\n\n";
	cout << "\t  info\t  Prints program info.\n\n";
	cout << "      editor/E\t  Opens the Generic Probability Libary problem editor.\n\n";






	inputter(" ");


}

void problem5(bool logic, int prescision, bool verbose){

	vector<string> desc;
	desc.push_back("yurmum");

	GenericObj *theobj = new GenericObj;
	try {
		theobj->initObj(verbose);
		theobj->initContainerArray(2, desc);
	}catch (const char* msg) {
     cerr << msg << endl;
   }
   vector<string> names;
	


	for(int i = 0; i < 52; i++){
		names.push_back("genericName" + to_string(i));
	}
	for(int i = 0; i < 4; i++){
		for(int j = 1; j < 14; j++){
			vector<int> data;
			data.push_back(i);
			data.push_back(j);
			try{
				theobj->fillContainerArray(data, names.at(1));
			}
			catch (const char* msg) {
   	  			cerr << msg << endl;
   			}
		}
	}
	Container x;
	x.mName = "hello";
	x.mInfo.push_back(1);
	std::vector<int> y;
	y.push_back(1);
	//if(theobj->match(x, y))
	{

	}
}


void problem1(bool logic, int prescision, bool verbose, bool old){
	if(old){
		Deck *thedeck = new Deck;
		thedeck->preInit(verbose);
		thedeck->deckInit(); 
		if(logic){
		thedeck->dependentProb(2, 1, -1);
		}
		else{
			thedeck->empericalEvidence(3, 1, 1, prescision);
		}
		delete thedeck;
		cout << "\n";
		string x = inputter("Again[n/Y]");
		if(tolower(x[0]) != 'n'){
			problem1(logic, prescision, verbose, old);
		}
	}
	else 
	{
		vector<string> desc;
		desc.push_back("Suit");
		desc.push_back("Number");

		GenericObj *theobj = new GenericObj;
		try 
		{
			theobj->initObj(verbose);
			theobj->initContainerArray(2, desc);
		}
		catch (const char* msg) 
		{
     		cerr << msg << endl;
   		}

   		for(int i = 0; i < 4; i++)
   		{
   			for (int j = 1; j < 14; j++)
   			{
   				vector<int> data;
   				string name;

   				data.push_back(i);
   				data.push_back(j);
   				if(j == 1)
				{
						name = "Ace of ";
				}
				else if(j >= 1 && j <= 10){
					stringstream ss;
					ss << j;
					string g;
					ss >> g;
					name = g + " of ";
				}
				else if(j == 11){
					name = "Jack of ";
				}
				else if(j == 12){
					name = "Queen of ";
				}
				else if(j == 13){
					name = "King of ";
				}
				else {
					name = "Unknown of ";
				}


				if(i == 0){
					
					name += "Spades";
				}
				else if(i == 1){
					name += "Hearts";
				}
				else if(i == 2){
					name += "Clubs";
				}
				else if(i == 3){
					name += "Diamonds";
				}
				else {
					name += "Unknown";
				}
				try
				{
					theobj->fillContainerArray(data, name);
				}
				catch (const char* msg) 
				{
     				cerr << msg << endl;
   				}
   			}
   		}

   		theobj->finished();
   		vector<vector<int> > want;
   		vector<int> tv, tv2;
   		tv.push_back(1);
   		tv.push_back(-1);
   		want.push_back(tv);
   		tv2.push_back(-1);
   		tv2.push_back(1);
   		//want.push_back(tv2);
   		int ret = -2;
   		try{
   			ret = theobj->dependentEmperical(2, want, false, true, true, prescision);
		}catch (const char* msg) {cerr << msg << endl;}
		delete theobj;
		if(ret == -1){
			cout << "\ndependentEmperical Returned -1\n";
		}
		else if(ret != -2){
			cout << "\n\nAfter trying " << prescision << " times, I think the chance is:\n" << (double)(ret * 100)/(double)prescision << "%" << " or " << ret << "/" << prescision << "\n";
		}
		string x = inputter("Again[n/Y]");
		if(tolower(x[0]) != 'n'){
			problem1(logic, prescision, verbose, old);
		}
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
		cout << "\nEnter the problem number '1' followed by a solver and then flags. \nType 'help' for more info.\n(INPUT)$";
		getline(cin, input);
		int problemtodo = -1;
		bool logic = true;
		bool verbose = false;
		bool old = false;
		int prescision = 10000;
		if(input == "q" || input == "quit" || input == "exit")
		{
			break;
		}
		else if(input == "h" || input == "help"){
			help();
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
                        length++;
						verbose = true;
					}
					if(input[length+1] == 'o'){
						old = true;
						length++;
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

			if(problemtodo == 5){
				problem5(logic, prescision, verbose);
			}
			else 
			{

			problem1(logic, prescision, verbose, old);
			
			}
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
