#include <iostream>
#include "Version.h"
#include "audio.h"
using namespace std;

class MIDImessage
{
       private:
              int status;
              int data1;
              int data2;
       public:
              MIDImessage()
              {
                     int status=0x90;
                     int data1=60;
                     int data2=0x7f;
              }

       void validdatabyte(int data)
       {
              if(data<128&&data>=0)
              {
                     data1=data;
                     data2=data;
              }
              else
              {
                     data1=0;
                     data2=0;
              }
       }

       void validstatusbyte(int validstatus)
       {
              if(validstatus<256&&validstatus>=128)
              {
                     status=validstatus;
              }
              else
              {
                     status=0;
              }
       }

       void setNoteonMessage(int Noteon)
       {
              if(Noteon>0x8f&&Noteon<0xA0)
              {
                  status=Noteon;
              }
			  else
			  {
				  status=0;
			  }
       }
 
       void setNoteoffMessage(int Noteoff)
       {
              if(Noteoff>0x7f&&Noteoff<0x90)
              {
                     status=Noteoff;
              }
			  else
			  {
				  status=0;
			  }
       }

       void setprogramchange(int programchange)
       {

              if(programchange<0xB9&&programchange<0xD0)
              {
                     status=programchange;
              }
			  else
			  {
				  status=0;
			  }
	   }
      
	   void setstartnote(int startnote)
	   {
		   if(startnote>59&&startnote<72)
		   {
			   data1=startnote;
		   }
		   else
		   {
			   data1=0;
		   }
	   }

	   int getMIDIstatus()
	   {
			return status;
	   }

	   int getMIDIdata1()
	   {
		   return data1;
	   }

	   int getMIDIdata2()
	   {
		   return data2;
	   }
};

int main()
{
	MIDImessage Startnote[11];
	Startnote.status(noteon);
	for(int count=60;count<72;count++)
	{
		Startnote.data1(count)
	}
	
	SendMIDIMessage(
	cout << "Please enter the letter corresponding to the scale you would like to hear ( C = Chromatic, M = Major, min = minor ) : " <<endl;
	cin >> scale;
	ChromaticScale(int startnote)
	{
		if(scale="C"||"c")
		{
			startnote

	

const int scaleamt = 9;
const int chromaticamt = 13;
char scaletype;
int startnote;
char scaledirection;
int scalerepeat;
int pause;
char instrument;

cout << "Enter a start note for the scale between 0 and 127: " <<endl;
cin >> startnote;
cout << "Type A for an ascending scale or D for a descending scale: " <<endl;
cin >> scaledirection;
cout << "Enter the pause length you want between each note(ms) : " <<endl;
cin >> pause;
cout << "Which instrument would you like to play this? ( G = guitar, P = piano, O = organ ) : " <<endl;
cin >> instrument;

if(scaletype="C"||"c")
{
	if(scaledirection="A"||"a")
		for(int count=0;count<chromaticamt;count++)
			{
				int AC[chromaticamt] = {startnote, startnote+1, startnote+2, startnote+3, startnote+4, startnote+5, startnote+6, startnote+7, startnote+8, startnote+9, startnote+10, startnote+11, startnote+12};
					sendMidiMessage(0x90, AC[count], 0x7f);
					delay(pause);
					sendMidiMessage (0x80, AC[count], 0x7f);
			}
	if(scaledirection="D"||"d")
	{
		for(int count=0;count<chromaticamt;count++)
		{
				
				int DC[chromaticamt] = {startnote, startnote-1, startnote-2, startnote-3, startnote-4, startnote-5, startnote-6, startnote-7, startnote-8, startnote-9, startnote-10, startnote-11, startnote-12};
				sendMidiMessage(0x90, DC[count], 0x7f);
				delay(pause);
				sendMidiMessage (0x80, DC[count], 0x7f);
		}
	}
	else
	{
		error();
	}
}
if(scaletype="M"||"m")
{
	if(scaledirection="A"||"a")
		for(int count=0;count<scaleamt;count++)
			{
				int AM[scaleamt] = {startnote, startnote+2, startnote+4, startnote+5, startnote+7, startnote+9, startnote+11, startnote+12};
					sendMidiMessage(0x90, AM[count], 0x7f);
					delay(pause);
					sendMidiMessage (0x80, AM[count], 0x7f);
			}
	if(scaledirection="D"||"d")
	{
		for(int count=0;count<scaleamt;count++)
		{
				int DM[scaleamt] = {startnote, startnote-1, startnote-3, startnote-5, startnote-7, startnote-8, startnote-10, startnote-12};
				sendMidiMessage(0x90, DM[count], 0x7f);
				delay(pause);
				sendMidiMessage (0x80, DM[count], 0x7f);
		}
	}
	else
	{
		error();
	}
}
if(scaletype="Min"||"min"||"MIN")
{
	if(scaledirection="A"||"a")
		for(int count=0;count<scaleamt;count++)
			{
				int AMin[scaleamt] = {startnote, startnote+2, startnote+3, startnote+5, startnote+7, startnote+8, startnote+10, startnote+12};
					sendMidiMessage(0x90, AMin[count], 0x7f);
					delay(pause);
					sendMidiMessage (0x80, AMin[count], 0x7f);
			}
	if(scaledirection="D"||"d")
	{
		for(int count=0;count<scaleamt;count++)
		{
				int DMin[scaleamt] = {startnote, startnote-2, startnote-4, startnote-5, startnote-7, startnote-9, startnote-10, startnote-12};
				sendMidiMessage(0x90, DMin[count], 0x7f);
				delay(pause);
				sendMidiMessage (0x80, DMin[count], 0x7f);
		}
	}
	else
	{
		error();
	}
}
else
	{
		error();
	}
return 0;
}










