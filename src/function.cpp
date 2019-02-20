#include "function.h"

#include <iostream>
long long factorial(long long x, long long y){
	long long out = 1;
	for(long long i = x; i > y; i--){
        out *= i;
	}
	return out;
}



Progress::Progress(){

}
Progress::~Progress(){

}


void
Progress::pInit(int denom){
	callCount = 0;
	inc = 0;
	step = 0;
	bot = denom;
	if(denom <= 100){

	}
	else if(denom > 100){
		int temp = denom;

		while(temp != 100){
			temp = temp / 10;
			inc++;
		}
	}

	std::cout << "\n\n[                   ] 00.00 %";
}

void 
Progress::update(){
	callCount++;

	if(callCount % inc == 0){
		step++;
		if(step % 8 == 0){
			std::cout << "\r[\u2588";
			for(int i = 0; i < 20-step; i++){
				std::cout << " ";
			}
			std::cout << "] " << (double)callCount/(double)bot << " %";
		}
		
	}


}