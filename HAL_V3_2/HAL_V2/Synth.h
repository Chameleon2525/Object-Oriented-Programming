#ifndef Synth_H
#define Synth_H
#include "Plugin.h"

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