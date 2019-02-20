#pragma once



long long factorial(long long x, long long y);
class Progress{
public:
	Progress();
	~Progress();
	void pInit(int denom);
	void update();
	int callCount, inc, step, bot;

};