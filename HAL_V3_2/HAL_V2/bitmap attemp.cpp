#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef unsigned int UINT;
typedef unsigned int DWORD;
typedef signed int LONG;
typedef unsigned short WORD;
typedef unsigned char BYTE;
const int WIDTH = 256;
const int HEIGHT = 256;
const int BITPERPIXEL = 24;

typedef struct tagBITMAPFILEHEADER 
{
     UINT    bfType;
     DWORD   bfSize;
     UINT    bfReserved1;
     UINT    bfReserved2;
     DWORD   bfOffBits;
 } BITMAPFILEHEADER;
typedef struct tagBITMAPINFOHEADER {    /* bmih */
     DWORD   biSize;
     LONG    biWidth;
     LONG    biHeight;
     WORD    biPlanes;
     WORD    biBitCount;
     DWORD   biCompression;
     DWORD   biSizeImage;
     LONG    biXPelsPerMeter;
     LONG    biYPelsPerMeter;
     DWORD   biClrUsed;
     DWORD   biClrImportant;
 } BITMAPINFOHEADER;

 typedef struct tagRGBQUAD {     /* rgbq */
     BYTE    rgbBlue;
     BYTE    rgbGreen;
     BYTE    rgbRed;
     BYTE    rgbReserved;
 } RGBQUAD;

//http://www.whisqu.se/per/docs/graphics52.htm


class BitMap
{
	BITMAPFILEHEADER bmfh;
	BITMAPINFOHEADER bmih;
	//RGBQUAD          aColors[];
	//BYTE             aBitmapBits[WIDTH * HEIGHT];
	RGBQUAD data[WIDTH * HEIGHT];
	

public:
	BitMap()
	{
		bmfh.bfType = 'BM';
		bmfh.bfReserved1 = 0;
		bmfh.bfReserved2 = 0;
		bmfh.bfSize = sizeof(data) + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
		bmfh.bfOffBits = sizeof( BITMAPFILEHEADER ) + sizeof( BITMAPINFOHEADER);

		cout << "bmfh.bfSize " << bmfh.bfSize << endl;;
		cout << "bmfh.bfOffBits " << bmfh.bfOffBits << endl;

		bmih.biSize = 40;
		bmih.biWidth = WIDTH;
		bmih.biHeight = HEIGHT;
		bmih.biPlanes = 1;
		bmih.biBitCount = BITPERPIXEL;
		bmih.biCompression = 0;
		bmih.biSizeImage = WIDTH * HEIGHT;
		bmih.biXPelsPerMeter = 0;
		bmih.biYPelsPerMeter = 0;
		bmih.biClrUsed = 0;
		bmih.biClrImportant = 0;

		//set all to a colour
		for(int h = 0; h<HEIGHT * WIDTH; h++)
		{
			data[h].rgbBlue = 0xff;
		}


	}
};

int main () 
{
  BitMap bm;
  ofstream file("C:\\temp/hello.bmp");
  file.write((const char *)&bm,sizeof(bm));
  file.close();
  return 0;
}

