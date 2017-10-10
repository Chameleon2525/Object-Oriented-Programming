#include <iostream>
#include <fstream>
#include <cstdlib> 
using namespace std;
#include "audio.h"



class myGain
{
	float gain;
public:
	myGain()
	{
		gain = 0.5;
	}
	float* processStereo(float* inputs)
	{
		inputs[0] = inputs[0] * gain;
		inputs[1] = inputs[1] * gain;
		return inputs;
	}
};

int main () 
{
	myGain myEffect;
	float* st = new float[2];
	st[0] = 0.2;
	st[1] = 0.3;
	st = myEffect.processStereo(st);
	cout << st[1];

}

