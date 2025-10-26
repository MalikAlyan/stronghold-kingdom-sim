#pragma once
# include<iostream>
# include<string>
using namespace std;
class leader
{
public:
	string name;
	int age;
	int leadershipscore;
	leader(string, int, int);
	virtual void displayrole() = 0;
	virtual void showstats();

};
class king :public leader {
public:
	int kingstability;
	king(string, int, int, int);
	void displayrole();
	void rulekingdom();
};
class commander :public leader {
public:
	int armysize;
	commander(string, int, int, int);
	void displayrole() override;
	void commandarmy();
};
class merchant :public leader {
public:
	int marketinfluence;
	merchant(string, int, int, int);
	void displayrole();
	void managetrade();
};

