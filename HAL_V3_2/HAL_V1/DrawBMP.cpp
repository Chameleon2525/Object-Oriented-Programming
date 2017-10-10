/****************************************************************
*																*
* Matthew Wankling												*
* 20/07/06														*
* File: DrawBMP.cpp												*
* Description: implementation of audio data drawing function	*
*																*
****************************************************************/

#include "Wavfile/WavFile.h"
#include "DrawBMP.h"
#include "EasyBMP_Font.h"

void CDrawBMP::drawWavFile(char* wavFileName, char * bmpFileName)
{
	CWavFile wav;
	wav.openWav(wavFileName);

	double startSample = 0;
	double endSample = wav.getNumSamples()*wav.getNumChannels();

	
	long size = endSample;

	short channels = wav.getNumChannels();

	float* rawData = wav.getSampleData();
	float* newData = new float[size];

	for(long i=0;i<(long)size;i++)
	{
		newData[i]=rawData[(long)startSample+i];
	}
	drawData(newData,size,channels,bmpFileName);
}


void CDrawBMP::drawLine(float x1, float y1, float x2, float y2, int red, int green, int blue)
{
	RGBApixel linecolour;
	linecolour.Red=red;
	linecolour.Green=green;
	linecolour.Blue=blue;
	
	DrawLine(myBmp,x1,y1,x2,y2,linecolour);

}


void CDrawBMP::drawSampleBlock(char* wavfile, double startMS, double endMS)
{
	CWavFile wav;
	wav.openWav(wavfile);

	double startSample = startMS/1000*wav.getSampleRate()*wav.getNumChannels();
	double endSample = endMS/1000*wav.getSampleRate()*wav.getNumChannels();

	if( startSample>wav.getNumSamples() )
	{
			cout << "*******************WARNING*******************" << endl;
			cout << "The start time you have sent does not exist" << endl;
			cout << "The file is "<< wav.getNumSamples()/wav.getNumChannels()/wav.getSampleRate()*1000 
				<<" milliseconds long" << endl;
			cout << "You sent a start time of "<< startMS <<" milliseconds"<<endl;
			cout << "*********************************************"<<endl;
			exit(1);
	}

	if( endSample>wav.getNumSamples() )
	{
			cout << "*******************WARNING*******************" << endl;
			cout << "The end time you have sent does not exist" << endl;
			cout << "The file is "<< wav.getNumSamples()/wav.getNumChannels()/wav.getSampleRate()*1000 
				<<" milliseconds long" << endl;
			cout << "You sent an end time of "<< endMS <<" milliseconds"<<endl;
			cout << "*********************************************"<<endl;
			exit(1);
	}

	if(startMS>endMS)
	{
			cout << "*******************WARNING*******************" << endl;
			cout << "Your start time occurs after your end time" << endl;
			cout << "You sent:"<<endl;
			cout << "Start Time: "<< startMS <<" milliseconds"<<endl;
			cout << "End Time:   "<< endMS <<" milliseconds"<<endl;
			cout << "*********************************************"<<endl;
			exit(1);
	}

	long size = endSample-startSample;

	short channels = wav.getNumChannels();


	float* rawData = wav.getSampleData();
	float* newData = new float[size];

	for(long i=0;i<(long)size;i++)
	{
		newData[i]=rawData[(long)startSample+i];
	}
	drawData(newData,size,channels,"mattsnewtest.bmp");
}

void CDrawBMP::drawData(float* data, long length, short channels, char* outfile)
{
	myBmp.SetSize(1000,400);

	float newX = 21;
	float newY = 0;
	float oldY = 200;
	float oldX = 20;
	float newX1 = 21;
	float newY1 = 0;
	float oldY1 = 200;
	float oldX1 = 20;

	int i=0;
	int j=0;
	int k=0;

	if(length>(960*channels))
	{
	
		int samplesPerPixel = length/(960);	//how many samples within one pixel	

		if(samplesPerPixel%channels!=0)
		{
			int temp = samplesPerPixel/channels;	//samples per pixel MUST be a multiple of number of channels
			samplesPerPixel=temp*channels;			//this routine makes sure it is, byt taking it down to the next 
		}											//lowest multiple

		float peaksArray[6][960][2];	//declare our array, three dimensional
										// 1) 6   - maximum of six channels
										// 2) 960 - the number of pixels across the bitmap
										// 3) 2   - one space for the highest sample in the block, one space for the lowest

		long count=0;	

		for(k=0;k<6;k++)		//fill up minimum array with 2's (otherwise array is set to large minus number
		{
			for(i=0;i<960;i++)
			{
				peaksArray[k][i][0]=-2;
				peaksArray[k][i][1]=2;	 //and will never be filled with minimum samples in the following loop
			}
		}										


		drawLine(20,10,20,390,10,180,10);	// two vertical lines at left of screen, y axis

		float high, low;

		for(k=0;k<channels;k++)				//for each channels
		{
			float offset = (200/channels) * ( ((k+1)*2) -1);

			for(i=0;i<960;i++)				//for each element of the array:
			{
				for(j=count;j<count+samplesPerPixel;j=j+channels)	//loop round all the samples in the block we are looking at
				{
					if(data[j+k] > peaksArray[k][i][0])		//if the sample is larger than that currently saved:
					{
						peaksArray[k][i][0]=data[j+k];		//save the sample over the top.
					}	

					if(data[j+k] < peaksArray[k][i][1])		//if the sample is less than that currently saved:
					{
						peaksArray[k][i][1]=data[j+k];		//save the sample over the top.
					}
				}

				count=count+samplesPerPixel;					//cause a jump to the next sample block
				
				newX=newX+1;

				

				high = ( offset )   -   (  peaksArray[k][i][0] * ( (200/channels) -10 )  );
				low =  ( offset )   -   (  peaksArray[k][i][1] * ( (200/channels) -10 )  );

				if(high==low)
				{	low=low-1;	}

				drawLine(newX,high,newX,low,64,0,128);	
				
				/*cout<<"k "<<k<<"\ti "<<i<<"\tj "<<j<<endl;

				cout<<"Hi Samp: "<<peaksArray[k][i][0]<<"\tHi Pix: "<<high 
					<<"Lo Samp "<<peaksArray[k][i][1]<<"\tLo Pix: "<<low<<endl<<endl;*/

			}

			//************************************************
			//DRAW AXIS
			drawLine(21,offset,980,offset,10,180,10);
			//************************************************

			count=0;
			newX = 21;
		}
			
		//cout<<endl<<endl<<samplesPerPixel<<endl;

	}

	else
	{
		if(channels==1)
		{
			for(i=0;i<length;i++)
			{
				newY = 200 - (190 * data[i]);

				drawLine(oldX,oldY,newX,newY,64,0,128);
				oldX=newX;
				oldY=newY;
				newX=newX+1;
			}

		}	

		if(channels==2)
		{
			for(i=0;i<length;i=i+2)
			{
				newY = 100 - (80 * data[i]);
				drawLine(oldX,oldY,newX,newY,64,0,128);
				oldX=newX;
				oldY=newY;
				newX=newX+1;

				newY1 = 300 - (80 * data[i]);
				drawLine(oldX1,oldY1,newX1,newY1,64,0,128);
				oldX1=newX1;
				oldY1=newY1;
				newX1=newX1+1;
			}

		}	

	}

	myBmp.WriteToFile(outfile);
}

void CDrawBMP::textOut(char* text, int left, int top)
{
	RGBApixel mine;
	mine.Red=0;
	mine.Green=0;
	mine.Blue=0;
	
	PrintString(myBmp,text,left,top,8,mine);
}



//**********************************************************************************************
//TWO OTHER WAYS OF DOING THINGS
//
// ONE) SIMPLY PLOT EVERY OTHER nth SAMPLE AND DRAW BETWEEN
//
// TWO) FIND THE SAMPLE WITH THE HIGHEST VALUE AND USE THAT TO DRAW TO THE NEXT ONE
/*
//	float sample;
//	float offset;
//	float newY;	

	float peaksArray[960];	//we have 960 'slots' in the array, corresponding to 760 pixels in the x axis
	long count = 0;

	for(i=0;i<960;i++)	//for each element of the array:
	{
		for(int j=count;j<count+samplesPerPixel;j++)	//loop round all the samples in the block we are looking at
		{
			if(mywav.getSample(j) > peaksArray[i])		//if the sample is larger than that currently saved:
			{
				peaksArray[i]=mywav.getSample(j);		//save the sample over the top.
			}	
			else
			{
				if( sqrt(mywav.getSample(j)*mywav.getSample(j)) > peaksArray[i])
				{
					peaksArray[i]=mywav.getSample(j);
				}
			}
		}
		count=count+samplesPerPixel;					//cause a jump to the next sample block
	}

	for(i=0;i<mywav.getNumSamples();i=i+samplesPerPixel) /*i<760;i++)
	{
		sample = mywav.getSample(i); //peaksArray[i];
		offset=(190*sample);
		newY=200-offset;
		wavBMP.drawLine(oldX,oldY,newX,newY);
		oldX=newX;
		oldY=newY;
		newX=newX+1;
	}



*/