#include "bank.h"
# include<fstream>
bank::bank()
{
	balance = 0;
	loanamount = 0;
	interestrate = 0;
	turns = 0;
	loanreturndate = 0;
	corruptionlevel = 0;
	auditcost = 0;
	frauddetected = false;
	securityexpanse = 0;
}

void bank::loantaken(float amount, int a, int b)
{
	loanamount += amount;
	balance += amount;
	loanreturndate += b;
	turns += a;
	cout << "Loan of " << amount << " taken for " << turns << " turns.\n";
	cout << "Return by day: " << loanreturndate << endl;
}

void bank::repayloan(float amount)
{
	if (amount <= balance) {
		balance -= amount;
		loanamount-= amount;
		if (loanamount < 0) {
			loanamount = 0;
		}
		cout << "Repaid loan: " << amount << endl;
	}
	else {
		cout << "Not Enough balance to Repay Loan \n";
	}
}

void bank::applyinterest(int currentday, float rate)
{
	if (loanamount > 0 && turns > 0) {
		loanamount += loanamount * interestrate;
		turns--;
		if (currentday > loanreturndate) {
			cout << "Loan is overdue! Penalties may apply.\n";
		}
		cout << "Interest applied. New loan amount: " << loanamount<< ", Turns left: " << turns << endl;
		srand(time(0));
		int risk = static_cast<int>((corruptionlevel * 100) - (securityexpanse / 100)); // Risk score
		int chance = rand() % 100;

		if (chance < risk) {
			frauddetected = true;
			cout << "⚠️ FRAUD DETECTED! Some funds have been stolen!\n";
			int stolen = loanamount * 0.2; // 20% loss
			loanamount -= stolen;
			if (loanamount < 0) loanamount = 0;
			cout << "Stolen amount: " << stolen << endl;
		}
	}
}

void bank::performaudit(float cost)
{
	auditcost = cost;
	if (balance >= auditcost) {
		balance -= auditcost;
		corruptionlevel -= 0.01;
		if (corruptionlevel < 0.0) corruptionlevel = 0.0;
		frauddetected = false;
		cout << "Audit performed. Corruption slightly reduced.\n";
	}
	else {
		cout << "Not enough funds to perform audit.\n";
	}
}

void bank::input(float a, float b)
{
	balance = a;
	corruptionlevel = b;
}

void bank::managesecurity(float amount)
{
	if (amount <= balance) {
		balance -= amount;
		securityexpanse += amount;
		corruptionlevel -= 0.005;
		if (corruptionlevel < 0) corruptionlevel = 0;

		cout << "Security increased by spending " << amount << ".\n";
		cout << "Corruption slightly reduced.\n";
	}
	else {
		cout << "Not enough balance to spend on security \n";
	}
}

void bank::print()
{
	cout << "\n--- Bank Status ---\n";
	cout << "Bank Balance:    " << balance << endl;
	cout << "Loan Amount:     " << loanamount << endl;
	cout << "Turns to Repay:  " << turns << endl;
	cout << "Return Date:     " << loanreturndate << endl;
	cout << "Corruption Level:" << corruptionlevel * 100 << "%" << endl;
	cout << "Fraud Detected:  " << (frauddetected ? "Yes" : "No") << endl;
}

void bank::savedata()
{
	ofstream write("save.txt", ios::app);
	if (write.is_open()) {
		write << "\n--- Bank Status ---\n";
		write << "Bank Balance:    " << balance << endl;
		write << "Loan Amount:     " << loanamount << endl;
		write << "Turns to Repay:  " << turns << endl;
		write << "Return Date:     " << loanreturndate << endl;
		write << "Corruption Level:" << corruptionlevel  << "%" << endl;
		write << "Fraud Detected:  " << (frauddetected ? "Yes" : "No") << endl;
		write.close();
	}
	else {
		cout << "SORRY WE HAVE NOT FOUND FILE ! \n";
	}
}
