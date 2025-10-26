#include "population.h"

population::population()
{
	populationsize = 0;
	nobility = 0;
	peasents = 0;
	merchants = 0;
	military = 0;
	jobsupply = 0;
	foodcare = 0;
	healthcare = 0;
	peasenttaxrate = 0;
	nobilitytaxrate = 0;
	merchanttaxrate = 0;
	militarytaxrate = 0;
	plagueactive = false;
	waractive = false;
	famineactive = false;
}

void population::setint(int a, int b, int c, int d, int e, int f, int g, int h)
{
	populationsize = a;
	nobility = b;
	peasents = c;
	merchants = d;
	military = e;
	jobsupply = f;
	foodcare = g;
	healthcare = h;
}

void population::setother(float a, float b, float c, float d, bool e, bool f, bool g)
{
	peasenttaxrate = a;
	nobilitytaxrate = b;
	merchanttaxrate = c;
	militarytaxrate = d;
	plagueactive = e;
	waractive = f;
	famineactive = g;
}

 void population::display() const
 {
	 cout << "Total population of country : " << populationsize << endl;
	 cout << "Total Nobility people of country : " << nobility << endl;
	 cout << "Total peasents  in country : " << peasents << endl;
	 cout << "Total merchants in country : " << merchants << endl;
	 //cout << "Total military in  country : " << military << endl;
 }
