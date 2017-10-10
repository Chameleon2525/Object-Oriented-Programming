#include <iostream>
using namespace std;
#include "WavFile/WavFile.h"
#include "math.h"

// week 1 getting started 

int main()
{
	CWavFile waveFile;
	waveFile.openWav("C://HALSounds/monoTone.wav");

	int numSamples = waveFile.getNumSamples();
	float leftSample = 0.0;
	float rightSample = 0.0;
	float volume = 0.5;

	for(int i = 0; i < numSamples; i++)
	{
		leftSample = waveFile.getSample(i);

		leftSample = leftSample * volume;

		waveFile.setSample(leftSample,i);
	}

	waveFile.saveWav("C://HALSounds/gain.wav");

	// fade file in
	float numfadeInSeconds = 0.5; 
	int numFadeInSamples = waveFile.getSampleRate() * numfadeInSeconds;
	float increment = 1.0/numFadeInSamples;
	volume = 0.0;

	for(int i = 0; i < numFadeInSamples; i++)
	{
		leftSample = waveFile.getSample(i);

		leftSample = leftSample * volume;

		volume = volume + increment;

		waveFile.setSample(leftSample,i);
	}

	waveFile.saveWav("C://HALSounds/fadeIn.wav");

	// fade file in log
	numfadeInSeconds = 0.5; 
	numFadeInSamples = waveFile.getSampleRate() * numfadeInSeconds;
	increment = 1.0/numFadeInSamples;
	volume = 0.0;

	for(int i = 0; i < numFadeInSamples; i++)
	{
		leftSample = waveFile.getSample(i);

		if( i == 0)
		{
			leftSample = 0.0;
		}
		else
		{
			leftSample = leftSample * volume;
		}

		volume = volume + increment;
		
		waveFile.setSample(leftSample,i);
	}

	waveFile.saveWav("C://HALSounds/fadeInLog.wav");
	

	// reverse
	float startSamp = 0.0;
	float endSamp = 0.0; 
	
	for(int start =0, end = waveFile.getNumSamples()-1; start < (waveFile.getNumSamples()/2.0); start++,end--)
	{
		startSamp = waveFile.getSample(start);
		endSamp = waveFile.getSample(end);
				
		waveFile.setSample(endSamp,start);
		waveFile.setSample(startSamp,end);

	}
	waveFile.saveWav("C://HALSounds/reverse.wav");

	// panning

	// create stereo wav file
	CWavFile stWav;
	stWav.newWav(44100,16,waveFile.getNumSamples(),2);
	int monoCount =0;

	for(int i = 0; i < stWav.getNumSamples(); i = i+2)
	{
		leftSample = waveFile.getSample(monoCount++);
		rightSample = 0.0;

		stWav.setSample(leftSample,i);
		stWav.setSample(rightSample,i+1);
	}

	stWav.saveWav("C://HALSounds/leftOnly.wav");




	return 0;
}