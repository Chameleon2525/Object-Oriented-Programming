#include <iostream>

#include <fstream>
#include <string>
using namespace std;
#include "EasyBMP.h"

#ifndef __PLHALBITMAP__
#define __PLHALBITMAP__

class HALBitmap
{
	BMP map;

public:
	HALBitmap(int x, int y);
	void setPixel(int x, int y, char red, char green, char blue);	
	void save(char * fileName);
};



#endif