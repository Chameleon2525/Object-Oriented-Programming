#include "midi.h"
#include <iostream>
using namespace std;

union midiUnion
{
	long l;
	struct bytes
	{
		char b0;
		char b1;
		char b2;
		char b3;
	}b;
};
/*
 CMidi Audio definitions
 */

//constructor
CMidiAudio::CMidiAudio()
{
	int result  = 0;
	result = midiOutOpen(&midiOutput, (UINT)-1, 0, 0, CALLBACK_NULL);
	if( result != MMSYSERR_NOERROR)
	{	
		cout << "*******************************************************************" << endl;
		cout << "***************************ERROR***********************************" << endl;
		cout << "There is a problem with opening Midi output" << endl; 
		cout << "*******************************************************************" << endl;
		exit(0);
	}
}

CMidiAudio::~CMidiAudio()
{
	midiOutClose(midiOutput);
}

void CMidiAudio::SendMidiMessage(unsigned char status, unsigned char data1, unsigned char data2)
{
	midiUnion mid;

	mid.b.b0 = status;
	mid.b.b1 = data1;
	mid.b.b2 = data2;
	mid.b.b3 = 0;

	midiOutShortMsg(midiOutput, mid.l);
}
