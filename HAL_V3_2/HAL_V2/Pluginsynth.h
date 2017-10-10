#ifndef Pluginsynth_H
#define Pluginsynth_H

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

class synth:public plugin
{
public:
	synth();
	synth(int, int);
	void processaudio();
	void stop();
	void start();
	void reset();
};

#endif