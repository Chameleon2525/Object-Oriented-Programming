/****************************************************************
*																*
* Matthew Wankling												*
* 20/07/06														*
* File: DrawBMP.h												*
* Description:  Class utilising EasyBMP to create bitmap images	*
*				of wave files									*
*																*
****************************************************************/

#include "EasyBMP.h"

#if !defined __MRWDRAWBMP__
#define __MRWDRAWBMP__


/**Class structure holds the data chunk information*/
class CDrawBMP  
{
private:
	void drawLine(float x1, float y1, float x2, float y2, int red, int green, int blue);
	void textOut(char* text, int left, int top);
	void drawData(float* data, long length, short channels, char* outfile);
	BMP myBmp;

public:

	CDrawBMP(){};
	void drawSampleBlock(char* wavfile, double startSample, double endSample);
	void drawWavFile(char* wavFileName, char * bmpFileName);
};


#endif