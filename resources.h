#pragma once
# include<iostream>
# include<string>
using namespace std;
class resources
{
public:
	int wood;
	int stone;
	int iron;
	int gold;
	int food;
	int weapons;
	int storagecapacity;
	bool iswinter;
	bool saferoute;
	resources();
	void produceresources();
	void useresources(int, int);
	void applyweathereffect();
	void disruptroute();
	void repairroute();
	virtual void print();
	void save();
};

