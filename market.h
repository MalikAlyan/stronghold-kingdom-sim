#pragma once
# include<iostream>
# include<string>
# include<cstdlib>
# include<ctime>
using namespace std;
class market
{
public:
	float foodprice;
	float woodprice;
	float weaponsprice;
	float foodstock;
	float woodstock;
	float weaponsstock;
	float trustlevel;
	bool smuggling;
	bool tradeaggrementactive;
	market();
	void updateprices();
	void trade(string, float, bool);
	void formtradeagrement();
	void breakaggrement();
	void showmarketstatus();
	void save();
};

