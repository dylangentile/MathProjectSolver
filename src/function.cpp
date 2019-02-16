#include "function.h"


int factorial(int x, int y){
	int out = 1;
	for(int i = x; i > y; i--){
        out *= i;
	}
	return out;
}
