#ifndef Task_2_H
#define Task_2_H

class plugin
{
private:
	int samplingrate;
	int bitrate;
	int audbufflngth;
	int chnum;
	int pan;
	int gain;
	int mute;
	int programnum;
	int MIDIchnum;
public:
	plugin()
	{
	samplingrate=44100;
	bitrate=16;
	audbufflngth=0;
	chnum=0;
	pan=0;
	gain=0;
	mute=0;
	programnum=0;
	MIDIchnum=0;
	}

	virtual void processaudio()=0;
	virtual void stop()=0;
	virtual void start()=0;
	virtual void reset()=0;
};

#endif