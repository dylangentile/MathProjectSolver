#include "generic.h"
#include <iostream>
#include "progress_bar.hpp"


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
GenericObj::dependentEmperical(int choose, vector<int> what, bool order, bool exactly, bool progress, int times){

}

int
GenericObj::independentEmperical(int choose, vector<int> what, bool order, bool exactly, bool progress, int times){
	if(!order)
	{
		if(!exactly)
		{

		}
	}

}

int
GenericObj::dependentLogical(int choose, vector<int> what, bool order, bool exactly, bool progress){

}

int
GenericObj::independentLogical(int choose, vector<int> what, bool order, bool exactly, bool progress){

}






















