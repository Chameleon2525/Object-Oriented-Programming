#include "audio.h"

// create an instance of the CMidiAudio object
static CMidiAudio midi;

void playMidiNote(int note, int lengthMs, int amplitude)
{
	// error checking
	if(note > 127 || note < 0)
	{
		cout << "*******************************************************************" << endl;
		cout << "***************************ERROR***********************************" << endl;
		cout << "   Mid notes values can only be between 0 and 127" << endl;
		cout << "   Note = " << note << endl;
		cout << "*******************************************************************" << endl;
		exit(0);
	}

	if(lengthMs < 0)
	{
		cout << "*******************************************************************" << endl;
		cout << "***************************ERROR***********************************" << endl;
		cout << "   Negative length!!!" << endl;
		cout << "   lengthMs= " << lengthMs << endl;
		cout << "*******************************************************************" << endl;
		exit(0);
	}

	if(amplitude > 127 || amplitude < 0)
	{
		cout << "*******************************************************************" << endl;
		cout << "***************************ERROR***********************************" << endl;
		cout << "   Midi amplitude values can only be between 0 and 127" << endl;
		cout << "   amplitude = " << amplitude << endl;
		cout << "*******************************************************************" << endl;
		exit(0);
	}

	// create an instance of the CMidiAudio object
	//CMidiAudio midi;

	// we can now send a midi message like so...
	midi.SendMidiMessage(0x90,(unsigned char)note,(unsigned char)amplitude);

	// and wait for the note to sound
	delay(lengthMs);

	//turn off note
	midi.SendMidiMessage(0x90,(unsigned char)note,0);
}

void playChord(int note1, int note2, int note3, int lengthMs, int amplitude)
{
	int notearray[3] = {note1,note2,note3};
	for(int i = 0; i< 3; i++)
	{
		// error checking
		if(notearray[i] > 127 || notearray[i] < 0)
		{
			cout << "*******************************************************************" << endl;
			cout << "***************************ERROR***********************************" << endl;
			cout << "   Mid notes values can only be between 0 and 127" << endl;
			cout << "   Note " << i+1<< " = " <<notearray[i]<< endl;
			cout << "*******************************************************************" << endl;
			exit(0);
		}
	}

	if(lengthMs < 0)
	{
		cout << "*******************************************************************" << endl;
		cout << "***************************ERROR***********************************" << endl;
		cout << "   Negative length!!!" << endl;
		cout << "   lengthMs= " << lengthMs << endl;
		cout << "*******************************************************************" << endl;
		exit(0);
	}

	if(amplitude > 127 || amplitude < 0)
	{
		cout << "*******************************************************************" << endl;
		cout << "***************************ERROR***********************************" << endl;
		cout << "   Midi amplitude values can only be between 0 and 127" << endl;
		cout << "   amplitude = " << amplitude << endl;
		cout << "*******************************************************************" << endl;
		exit(0);
	}

	// create an instance of the CMidiAudio object
	//CMidiAudio midi;

	// we can now send a midi message like so...
	midi.SendMidiMessage(0x90,(unsigned char)note1,(unsigned char)amplitude);
	midi.SendMidiMessage(0x90,(unsigned char)note2,(unsigned char)amplitude);
	midi.SendMidiMessage(0x90,(unsigned char)note3,(unsigned char)amplitude);

	// and wait for the note to sound
	delay(lengthMs);

	//turn off note
	midi.SendMidiMessage(0x90,(unsigned char)note1,0);
	midi.SendMidiMessage(0x90,(unsigned char)note2,0);
	midi.SendMidiMessage(0x90,(unsigned char)note3,0);
}

void sendMidiMessage(int status, int data1, int data2)
{
	// error checking
	if(status > 255 || status < 127)
	{
		cout << "*******************************************************************" << endl;
		cout << "***************************ERROR***********************************" << endl;
		cout << "   status values can only be between 0 and 127" << endl;
		cout << "   status = " << status<< endl;
		cout << "*******************************************************************" << endl;
		exit(0);
	}

	if(data1 > 127 || data1 < 0)
	{
		cout << "*******************************************************************" << endl;
		cout << "***************************ERROR***********************************" << endl;
		cout << "   data1 values can only be between 0 and 127" << endl;
		cout << "   data1 = " << data1<< endl;
		cout << "*******************************************************************" << endl;
		exit(0);
	}

	if(data2 > 127 || data2 < 0)
	{
		cout << "*******************************************************************" << endl;
		cout << "***************************ERROR***********************************" << endl;
		cout << "   data2 values can only be between 0 and 127" << endl;
		cout << "   data2 = " << data2<< endl;
		cout << "*******************************************************************" << endl;
		exit(0);
	}
	//CMidiAudio midi;
	midi.SendMidiMessage((unsigned char)status,(unsigned char)data1,(unsigned char)data2);
	
}