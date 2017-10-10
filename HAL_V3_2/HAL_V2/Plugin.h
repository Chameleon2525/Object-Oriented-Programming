#ifndef Plugin_H
#define Plugin_H
#include "Synth.h"

class plugin
{
private:
	int audbufflngth;
	int chnum;
	int pan;
	int gain;
	int mute;
	int programnum;
	int MIDIchnum;
public:
	int samplingrate;
	int Bitrate;
	plugin();
	virtual void processaudio()=0;
	virtual void stop()=0;
	virtual void start()=0;
	virtual void reset()=0;
};

#endif