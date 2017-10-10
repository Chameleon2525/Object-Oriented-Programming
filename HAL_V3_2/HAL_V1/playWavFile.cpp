
#include "playWavFile.h"

#define OUTPUT_DEVICE Pa_GetDefaultOutputDeviceID()

const int FRAMES_PER_BUFFER2 = 64;

int INCREMENT2 = 0;
CWavFile wav;
bool IS_STEREO = false;





/* This routine will be called by the PortAudio engine when audio is needed.
** It may called at interrupt level on some machines so don't do anything
** that could mess up the system like calling malloc() or free().
*/
static int callback(   
						  void *inputBuffer, 
						  void *outputBuffer,
                          unsigned long framesPerBuffer,
                          PaTimestamp outTime, 
						  void *userData )
{
    float *out = (float*)outputBuffer;
    unsigned long i;
    int finished = 0;

	float left = 0.0;
	float right = 0.0;

	for( i=0; i<framesPerBuffer; i++ )
    {
		if(INCREMENT2 >= wav.getNumSamples())
		{
			finished = 1;
			left = 0.0;
			right = 0.0;
		}
		else
		{
			if(IS_STEREO)
			{
				left = wav.getSample(INCREMENT2++);
				right = wav.getSample(INCREMENT2++);
			}
			else
			{
				left = wav.getSample(INCREMENT2++);
				right = left;
			}
		}

		

        *out++ = left;  
        *out++ = right;  
             
    }
    return finished;
}

/*******************************************************************/
int playWavFile(char* wavFileName)
{
	PortAudioStream *stream;
    PaError err;

	//error checking
	wav.openWav(wavFileName);

	err = Pa_Initialize();
    checkError2(err);

    err = Pa_OpenStream(
              &stream,
              paNoDevice,		/* default input device */
              0,				/* no input */
              paFloat32,		/* 32 bit floating point input */
              NULL,
              OUTPUT_DEVICE,
              2,				/* stereo output */
              paFloat32,		/* 32 bit floating point output */
              NULL,
			  wav.getSampleRate(),
              64,
              0,				/* number of buffers, if zero then use default minimum */
              paClipOff,		/* we won't output out of range samples so don't bother clipping them */
              callback,
              NULL );
    checkError2(err);

    err = Pa_StartStream( stream );
    checkError2(err);

	while( Pa_StreamActive( stream ) )
    {
        Pa_Sleep(100); 
    }

    err = Pa_StopStream( stream );
    checkError2(err);

    err = Pa_CloseStream( stream );
    checkError2(err);

    Pa_Terminate();
    return err;
}

void checkError2(PaError err)
{
	if( err != paNoError )
	{
		Pa_Terminate();
		fprintf( stderr, "An error occured while using the portaudio stream\n" );
		fprintf( stderr, "Error number: %d\n", err );
		fprintf( stderr, "Error message: %s\n", Pa_GetErrorText( err ) );
		exit(0);
	}
}