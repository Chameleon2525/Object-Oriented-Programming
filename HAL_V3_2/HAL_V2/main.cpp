#include <iostream>
#include "WavFile/WavFile.h"
#include <cmath>
using namespace std;

int main()
{
	CWavFile Audio;
	Audio.openWav("C:/Temp/jazz.wav");
	int SampleRate = Audio.getSampleRate();
	long channels = Audio.getNumChannels();
	long length = Audio.getNumSamples();
	float sample= 0.0;
	float leftsample = 0.0;
	float rightsample = 0.0;
	float peak = 0.0;

	for(int i=0;i<length;i+2)
	{
		sample = Audio.getSample(i);
		peak = fabs(sample);
	}
	
	cout << peak;
	Audio.saveWav("C:\Temp/copy of jazz.wav");
	return 0;
}