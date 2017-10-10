#include <iostream>
#include <ctime>
#include "Timeclass.h"

//defining the functions of the timeclass

void timeclass::setseconds(int validsec)
{
	if(validsec>=0||validsec<=60)
	{
		seconds = validsec;
	}
	else
	{
		seconds = 0;
	}
}

int timeclass::getseconds(int s)
{
	return seconds;
}

void timeclass::setminutes(int validmin)
{
	if(validmin>=0||validmin<=60)
	{
		minutes = validmin;
	}
	else
	{
		minutes = 0;
	}
}

int timeclass::getminutes(int m)
{
	return minutes;
}

void timeclass::sethours(int validhr)
{
	if(validhr>=0||validhr<24)
	{
		hours = validhr;
	}
	else
	{
		hours = 0;
	}
}

int timeclass::gethours(int h)
{
	return hours;
}

void timeclass::setdate(int validdate)
{
	if(validdate>0||validdate<=31)
	{
		date = validdate;
	}
	else
	{
		date = 0;
	}
}

int timeclass::getdate(int d)
{
	return date;
}

void timeclass::setmonth(int validmth)
{
	if(validmth>0||validmth<=12)
	{
		month = validmth;
	}
	else
	{
		month = 0;
	}
}

int timeclass::getmonth(int m)
{
	return month;
}

void timeclass::setyear(int validyr)
{
	if(validyr>0||validyr<=2500)
	{
		month = validyr;
	}
	else
	{
		month = 0;
	}
}

int timeclass::getyear(int y)
{
	return year;
}

timeclass::timeclass()
{
	seconds = 0;
	minutes = 0;
	hours = 0;
	date = 1;
	month = 1;
	year = 2012;
}

timeclass::~timeclass()
{
}