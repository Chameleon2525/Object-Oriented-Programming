#include "Synth.h"
#include "Plugin.h"
#include <iostream>
using namespace std;

plugin::plugin()
{
	samplingrate=44100;
	Bitrate=16;
	audbufflngth=0;
	chnum=0;
	pan=0;
	gain=0;
	mute=0;
	programnum=0;
	MIDIchnum=0;
}

synth::synth()
{
	samplingrate=44100;
	Bitrate=16;
}

synth::synth(int SR, int BR)
{
	samplingrate = SR;
	Bitrate = BR;
}

void synth::processaudio()
{
	cout << "processing audio..." <<endl;
}

void synth::stop()
{
	cout << "stopping..." <<endl;
}

void synth::start()
{
	cout << "starting..." <<endl;
}

void synth::reset()
{
	cout << "resetting..." << endl;
}