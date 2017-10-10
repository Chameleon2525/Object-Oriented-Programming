#include <iostream>
#include "Version.h"
#include <ctime>
#include "Timeclass.h"
using namespace std;

int main()
{
	timeclass presenttime;
	presenttime.getseconds(32);
	presenttime.getminutes(23);
	presenttime.gethours(13);
	presenttime.getdate(06);
	presenttime.getmonth(10);
	time_t Now = time(0);
	cout << "The date today is: " << ctime(&Now) << endl; //Displays the time at which the program is executed
	return 0;
}
	
	