#pragma once
# include<iostream>
# include<string>
using namespace std;
class population
{
public:
	int populationsize;
	int nobility;
	int peasents;
	int merchants;
	int military;
	float peasenttaxrate;
	float nobilitytaxrate;
	float merchanttaxrate;
	float militarytaxrate;
	int foodcare;
	int jobsupply;
	int healthcare;
	bool plagueactive;
	bool waractive;
	bool famineactive;
	population();
	void setint(int, int, int, int, int, int, int, int);
	void setother(float, float, float, float, bool, bool, bool);
	virtual void display() const;
};

