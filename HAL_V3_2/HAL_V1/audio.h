#define _CRT_SECURE_NO_DEPRECATE  // see http://forums.microsoft.com/MSDN/ShowPost.aspx?PostID=126427&SiteID=1
#include "HAL_Utilities.h"
#include "midi.h"
#include <iostream>
using namespace std;
#include "sine.h"

void playMidiNote(int note, int length, int amplitude);
void playChord(int note1, int note2, int note3, int lengthMs, int amplitude);
void sendMidiMessage(int status, int data1, int data2);

