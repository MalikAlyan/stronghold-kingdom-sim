#pragma once
# include<iostream>
# include<string>
# include<fstream>
using namespace std;
class army
{
public:
	army();
	int armysize;
	int traininglevel;
	float morale;
	bool ispaid;
	string generalname;
	int barackcapacity;
	float corruptionlevel;
	int weaponstock;
	float warduration;
	virtual void input(int, int, int, int, float, float, float, string, bool);
	virtual void display() const;
	virtual void savetofile();
};