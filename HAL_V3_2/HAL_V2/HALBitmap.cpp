#include "HALBitmap.h"

HALBitmap::HALBitmap(int x, int y)
{
	map.SetSize(x,y);
}
void HALBitmap::setPixel(int x, int y, char red, char green, char blue)
{
	map(x,y)->Red = red;
	map(x,y)->Green = green;
	map(x,y)->Blue = blue;
}
void HALBitmap::save(char * fileName)
{
	map.WriteToFile(fileName);
}