#define Time_class
#ifndef Time_class

class time
{
	private:
		int seconds;
		int minutes;
		int hours;
		int date;
		int month;
		int year;
	public:
		void setseconds(int validsec);
		int getseconds(int s);
		void setminutes(int validmin);
		int getminutes(int m);
		void sethours(int validhr);
		int gethours(int h);
		void setdate(int validdate);
		int getdate(int d);
		void setmonth(int validmth);
		int getmonth(int m);
		void setyear(int validyr);
		int getyear(int y);
};

