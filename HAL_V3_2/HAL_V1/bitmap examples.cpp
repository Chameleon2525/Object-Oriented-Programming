#include <iostream>
#include <fstream>
#include <cstdlib> 
using namespace std;
#include "HALBitmap.h"

int main () 
{
	HALBitmap map(256,256);
	int x, y;
	char red,green,blue;

	// fill with black
	red = 0;
	green = 0;
	blue = 0;
	for(x = 0;x <256;x++)
	{
		for(y = 0; y < 256; y++)
		{
		  map.setPixel(x, y, red, green, blue);
		}
	}
	
	// draw vertical line
	red = 0xff;
	green = 0xff;
	blue = 0xff;
	x = 256/2;
	for(y = 0; y < 256; y++)
	{
		map.setPixel(x, y, red, green, blue);
	}

	// draw horizontal line
	y = 256/2;
	red = 0x7f;
	green = 0x7f;
	blue = 0x7f;

	for(x = 0; x < 256;x++)
	{
		map.setPixel(x, y, red, green, blue);
	}

	map.save("C://temp/map.bmp");

	HALBitmap random(256,256);
	// fill with black
	for(x = 0;x <256;x++)
	{
		for(y = 0; y < 256; y++)
		{
			red = rand();
			green = rand();
			blue = rand();
			random.setPixel(x,y,red,green,blue);
		}
	}
	random.save("C://temp/rand.bmp");
  
	return 0;
}

