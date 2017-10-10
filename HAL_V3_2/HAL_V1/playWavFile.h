#include <cmath>
#include <iostream>
using namespace std;
#include "portaudio.h"
#include "Wavfile/WavFile.h"

void checkError2(PaError err);
int playWavFile(char* wavFileName);
