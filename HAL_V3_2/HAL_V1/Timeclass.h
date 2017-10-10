#include <iostream>
#ifndef TIME_CLASS_H
#define TIME_CLASS_H


class timeclass
{
	private:
		int seconds;
		int minutes;
		int hours;
		int date;
		int month;
		int year;
	public:
		timeclass();
		~timeclass();
		void setseconds(int);
		int getseconds(int);
		void setminutes(int);
		int getminutes(int);
		void sethours(int);
		int gethours(int);
		void setdate(int);
		int getdate(int);
		void setmonth(int);
		int getmonth(int);
		void setyear(int);
		int getyear(int);
		
};

#endif

