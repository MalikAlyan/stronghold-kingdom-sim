#pragma once
# include<iostream>
# include<string>
using namespace std;
enum factionVOTERS {
	nobility, peasents, merchants
};
class kingelection
{
public:
	factionVOTERS hello;
	string kingname;
	int faction[3];
	string style;
	int stability;
	float corruptionlevel;
	bool assasinationrisk;
	bool electionheld;
	float popularity;
	kingelection();
	virtual void  setvalues( int, int, int, int, float, float, string, string, bool, bool);
	virtual void  print() const ;
};

