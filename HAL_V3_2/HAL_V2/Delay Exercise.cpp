#include <iostream>
#include"Version.h"
#include "WavFile/WavFile.h"
using namespace std;


int main()
{
	//Exercise 1
	int buffer[5]={0,0,0,0,0};
	int out = 0;
	int in = 3;
	int x = 0;

	for(int i = 0;i<10;i++)
	{
		cout << "Insert a number  ";
		cin >> x;
		buffer[in]=x;
		in++;
		if(in == 5)
		{
			in = 0;
		}
		cout << buffer[out];
		out++;
		if(out == 5)
		{
			out = 0; 
		}
	}

	//Exercise 2
	CWavFile Dlytest;
	Dlytest.openWav("C:\Temp\Clap.wav");
	float SampleRate = Dlytest.getSampleRate();
	long channels = Dlytest.getNumChannels();
	long length = Dlytest.getNumSamples();
	float Samples[44000];
	float input_index = SampleRate/2;
	float output_index = 0;

	for(int i=0;i<length;i++)
	{
		Samples[input_index] = leftSample;
		leftSample = samples[output_index];
	}




	Dlytest.saveWav("C:\Temp\Clapdelay.wav");

	return 0;
}

