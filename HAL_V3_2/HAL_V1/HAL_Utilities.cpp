#include "HAL_Utilities.h"

void delay(int milliSeconds)
{
	Sleep((long)milliSeconds);
}

void delay(long milliSeconds)
{
	Sleep(milliSeconds);
}