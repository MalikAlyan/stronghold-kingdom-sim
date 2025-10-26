#pragma once
# include<iostream>
# include<cstdlib>
# include<ctime>
# include<string>
using namespace std;
class bank
{
public:
	float balance;
	float loanamount;
	float interestrate;
	int turns;
	int loanreturndate;
	float corruptionlevel;
	float auditcost;
	bool frauddetected;
	float securityexpanse;
	bank();
	virtual void loantaken(float,int,int);
	virtual void repayloan(float);
	virtual void applyinterest(int, float);
	void performaudit(float);
	virtual void input(float, float);
	void managesecurity(float);
	virtual void print();
	virtual void savedata();
};

