#include "function.h"


long long factorial(long long x, long long y){
	long long out = 1;
	for(long long i = x; i > y; i--){
        out *= i;
	}
	return out;
}
