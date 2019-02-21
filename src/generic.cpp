#include "generic.h"
#include "progress_bar.hpp"

#include <iostream>
#include <random>
#include <algorithm>


using namespace std;

GenericObj::GenericObj(){
	retMsg = "";
	infoSize = 0;
}

GenericObj::~GenericObj(){



}


void 
GenericObj::initObj(bool verbosity){
	verbose = verbosity;
}


void 
GenericObj::initContainerArray(int dataSize, vector<string> descriptors){
		desc = descriptors;
		infoSize = dataSize;
		if(infoSize <= 0){
			throw "The infoSize is less than or equal to 0. Unacceptable!";
		}
		if(descriptors.size() != infoSize){
			throw "Not enough or too many descriptors!";
		}
}


void 
GenericObj::fillContainerArray(vector<int> info, string name){
	if(infoSize == 0){
		throw "Didn't run 'void GenericObj::initContainerArray(....)' on object yet. :(";
	}
	if(info.size() == infoSize){
		Container theContainer;
		theContainer.mInfo = info;
		theContainer.mName = name;
		ContainerArray.push_back(theContainer);
	}else{
		throw "Passed a vector<int> to fillContainerArray, but it's size didn't match the one initialized.";
	}
}

void
GenericObj::finished(){
	done = true;
	ContainerArrayCopy = ContainerArray;
}


bool
GenericObj::match(Container against, vector<int> with){
	/*
	int i =0;
	cout << "matching\n";
	vector<Container>::iterator it;
	for(it = ContainerArray.begin(); it != ContainerArray.end(); ++it){
		Container tempContainer = *it;
		cout << i << "\t"<< tempContainer.mName << "\n";
		i++;
	}
	*/

	if(with.size() != infoSize){
		throw "vector<int> of what you're looking for, has a size that doesn't match the amount of values in an object";
		return false;
	}
	else
	{
		int matches = 0;
		{
			int i = 0;
			vector<int>::iterator it;
			for(it = against.mInfo.begin(); it != against.mInfo.end(); ++it){
				if(with.at(i) != -1){
					if(*it == with.at(i)){
						matches++;
					}
				} 
				else
				{
					matches++;
				}

				i++;
			}
		}
		if(matches == with.size()){
			return true;
		}
	}
	return false;
}



int
GenericObj::dependentEmperical(int choose, vector<vector<int> > what, bool order, bool exactly, bool progress, int times){
	if(what.size() > choose){
		throw "You are saying you want to choose more cards than you have.";
		return -1;
	}


	if(done)
	{
		

		ProgressBar theprogress(times, "Calculating");
		
		if(!order)
		{
			if(!exactly) //not 1 or more, but instead only once, etc
			{

				int theMatches = 0;
				int theTries = 0;

				for(int i = 0; i < times; i++)
				{
					if(progress)
					{
						theprogress.Progressed(i);
					}
					vector<Container> taken;
					ContainerArray = ContainerArrayCopy;
					random_shuffle(ContainerArray.begin(), ContainerArray.end());
					for(int q = 0; q < choose; q++)
					{
						taken.push_back(ContainerArray.back());
						retMsg += taken.back().mName;
						if(taken.back().mName.size() >= 16)
						{
							retMsg += "\t";
						}
						else{
							retMsg += "\t\t";
						}
						ContainerArray.pop_back();
					}
					int matchings = 0;
					vector<vector<int> > modWhat = what;
					vector<vector<int> > used;
					for(vector<Container>::iterator qi = taken.begin(); qi != taken.end(); ++qi)
					{
						
						for(vector<vector<int> >::iterator theit = modWhat.begin(); theit != modWhat.end(); ++theit)
						{
						if(match(*qi, *theit))
							{
								used.push_back(*theit);
								modWhat.erase(theit);
								matchings++;
								break;
							}

						}
					}
					if(matchings == what.size()){
						theMatches++;
						retMsg+= " <------";
					}
					theTries++;
					retMsg+="\n";
				}
				if(verbose){
					cout << "\n\n" << retMsg;
				}
				return theMatches;


			}
			else
			{

				int theMatches = 0;
				int theTries = 0;

				for(int i = 0; i < times; i++)
				{
					if(progress)
					{
						theprogress.Progressed(i);
					}
					vector<Container> taken;
					ContainerArray = ContainerArrayCopy;
					random_shuffle(ContainerArray.begin(), ContainerArray.end());
					for(int q = 0; q < choose; q++)
					{
						taken.push_back(ContainerArray.back());
						retMsg += taken.back().mName;
						if(taken.back().mName.size() >= 16)
						{
							retMsg += "\t";
						}
						else{
							retMsg += "\t\t";
						}
						ContainerArray.pop_back();
					}
					int matchings = 0;
					vector<vector<int> > modWhat = what;
					for(vector<Container>::iterator qi = taken.begin(); qi != taken.end(); ++qi)
					{
						
						for(vector<vector<int> >::iterator theit = modWhat.begin(); theit != modWhat.end(); ++theit)
						{
						if(match(*qi, *theit))
							{
								modWhat.erase(theit);
								matchings++;
								break;
							}

						}
					}
					if(matchings == what.size()){
						theMatches++;
						retMsg+= " <------";
					}
					theTries++;
					retMsg+="\n";
				}
				if(verbose){
					cout << "\n\n" << retMsg;
				}
				return theMatches;
			}
		}
		else
		{
			int theMatches = 0;
			int theTries = 0;
			for(int i = 0; i < times; i++){
				if(progress)
				{
					theprogress.Progressed(i);
				}
				vector<Container> taken;
				ContainerArray = ContainerArrayCopy;
				
				random_shuffle(ContainerArray.begin(), ContainerArray.end());
				for(int q = 0; q < choose; q++)
				{
					taken.push_back(ContainerArray.back());
					retMsg += taken.back().mName;
					if(taken.back().mName.size() >= 16)
					{
						retMsg += "\t";
					}
					else{
						retMsg += "\t\t";
					}
					ContainerArray.pop_back();
				}
				int matchings = 0;
				int z = 0;
				for(vector<Container>::iterator qi = taken.begin(); qi != taken.end(); ++qi)
				{
					
					if(z < what.size()){
						if(match(*qi, what.at(z)))
						{
							matchings++;
						}
					} else {
						break;
					}


					z++;
				}
				if(matchings == what.size()){
					theMatches++;
					retMsg+= " <------";
				}
				theTries++;
				retMsg+="\n";
			}
			if(verbose)
			{
					cout << "\n\n" << retMsg;
			}
			return theMatches;
		}
	} 
	else 
	{
		throw "You didn't call 'void GenericObj::finished()' yet, so you cannot do any solutions.";
		return -1;
	}



	return -1;

}

int
GenericObj::independentEmperical(int choose, vector<vector<int> > what, bool order, bool exactly, bool progress, int times){
	if(done)
	{

	}
	else
	{
		throw "You didn't call 'void GenericObj::finished()' yet, so you cannot do any solutions.";
		return -1;
	}	

}

int
GenericObj::dependentLogical(int choose, vector<vector<int> > what, bool order, bool exactly, bool progress){
	if(done)
	{

	}
	else
	{
		throw "You didn't call 'void GenericObj::finished()' yet, so you cannot do any solutions.";
		return -1;
	}
}



int
GenericObj::independentLogical(int choose, vector<vector<int> > what, bool order, bool exactly, bool progress){
	
	vector<vector<int> > tempVect;
	for(vector<vector<int> >::reverse_iterator it = tempVect.rbegin(); it != tempVect.rend(); ++it){
		tempVect.push_back(*it);
	}
	
	if(what.size() != choose){
		throw "For logical solves the what vector must match the choose int";
	}
	if(done)
	{
		if(order)
		{
			if(exactly)
			{
				int theMatches = 0;
				int theTries = ContainerArray.size();

				vector<Container> mod;
				for(int i = 0; i < theTries; i++){
					mod.push_back(ContainerArray.back());
										
				}

				
			}
		}
	}
	else
	{
		throw "You didn't call 'void GenericObj::finished()' yet, so you cannot do any solutions.";
		return -1;
	}
}






















