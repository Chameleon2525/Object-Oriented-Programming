#include <iostream>
#include "audio.h"
using namespace std;

int main ()
{
	char userinput;
	cout << "please enter D for a descending scale or A for an ascending scale -";
	cin >> userinput << endl;
	if(userinput == 'D')
	{
     for(int x = 60; x<72; x++)
     {
	  //send note on
	  sendMidiMessage(0x80,x,0x7f);
		
	  delay(2000);

	  // send note off
	  sendMidiMessage(0x80,x,0x7f);
      }
	}
	if (userinput = 'A')
	{
      for(int x = 60; x<58; x--)
     {
	  //send note on
	  sendMidiMessage(0x80,x,0x7f);
		
	  delay(2000);

	  // send note off
	  sendMidiMessage(0x80,x,0x7f);
      }

return 0;
}