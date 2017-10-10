#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")


#ifndef __PILCMIDIAUDIO
#define __PILCMIDIAUDIO

//class definitions
class CMidiAudio
{
public:
	CMidiAudio();
	~CMidiAudio();
	void SendMidiMessage(unsigned char status, unsigned char data1, unsigned char data2);
private:	
	HMIDIOUT midiOutput;

};

#endif
