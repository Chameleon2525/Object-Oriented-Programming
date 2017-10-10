
#include "sine.h"

#define OUTPUT_DEVICE Pa_GetDefaultOutputDeviceID()


float SAMPLE_RATE = 44100;
float AMPLITUDE = 1.0f;
const int FRAMES_PER_BUFFER = 64;
const float PI = 3.14159265f;
const float PIX2 = PI*2;
int INCREMENT = 0;
float SINE_FREQUENCY = 1000.0;
float NORMALISED_FREQUENCY = SINE_FREQUENCY/SAMPLE_RATE;
float SINE_COEFF = NORMALISED_FREQUENCY * PIX2;





/* This routine will be called by the PortAudio engine when audio is needed.
** It may called at interrupt level on some machines so don't do anything
** that could mess up the system like calling malloc() or free().
*/
static int sineCallback(   
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
		left = (float)(sin(SINE_COEFF* INCREMENT++));
		right = left;

        *out++ = left * AMPLITUDE;  
        *out++ = right * AMPLITUDE;  
             
    }
    return finished;
}

/*******************************************************************/
int playSine(float frequency, int milliseconds)
{
	PortAudioStream *stream;
    PaError err;

	//error checking
	if(frequency < 20.0 || frequency > 20000.0)
	{
		cout << "ERROR - frequency not within audio range" << endl;
		cout << "Your frequency = " << frequency << endl;
		return 0;
	}
	if(milliseconds < 0)
	{
		cout << "ERROR - negative time!" << endl;
		cout << "Your milliseconds = " << milliseconds << endl;
		return 0;
	}

	SINE_FREQUENCY = frequency;
	NORMALISED_FREQUENCY = SINE_FREQUENCY/SAMPLE_RATE;
	SINE_COEFF = NORMALISED_FREQUENCY * PIX2;
    
     
    err = Pa_Initialize();
    checkError(err);

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
              SAMPLE_RATE,
              FRAMES_PER_BUFFER,
              0,				/* number of buffers, if zero then use default minimum */
              paClipOff,		/* we won't output out of range samples so don't bother clipping them */
              sineCallback,
              NULL );
    checkError(err);

    err = Pa_StartStream( stream );
    checkError(err);

    Pa_Sleep( milliseconds );

    err = Pa_StopStream( stream );
    checkError(err);

    err = Pa_CloseStream( stream );
    checkError(err);

    Pa_Terminate();
    return err;
}

void checkError(PaError err)
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