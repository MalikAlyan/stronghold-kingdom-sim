#include "market.h"
# include<fstream>
market::market()
{
	foodprice = 15;
	woodprice = 25;
	weaponsprice = 35;
	foodstock = 1200;
	woodstock = 1300;
	weaponsstock = 1400;
	smuggling = false;
	tradeaggrementactive = false;
	trustlevel = 65;
	srand(time(0));
}

void market::updateprices()
{
	foodprice = 7 + rand() % 6;
	woodprice = 14 + rand() % 8;
	weaponsprice = 21 + rand() % 10;
	cout << "Market prices have been updated based on supply/demand.\n";
}

void market::trade(string name, float amount, bool issmuggled)
{
	int price = 0;
	if (name == "food" || name == "FOOD") {
		price = foodprice * amount;
		foodstock -= amount;
	}else if (name == "wood" || name == "WOOD") {
		price = woodprice * amount;
		woodstock -= amount;
	}else if (name == "weapons" || name == "Weapons") {
		price = weaponsprice * amount;
		weaponsstock -= amount;
	}
	else {
		cout << "Sorry you Have enetered wrong resource name \n";
	}
	cout << "Traded " << amount << " units of " << name << " for " << price << " gold.\n";
	if (issmuggled) {
		srand(time(0));
		int chance = rand() % 100;
		if (chance < 30) {
			smuggling = true;
			trustlevel -= 10;
			cout << "⚠️ Smuggler caught! Trust with other factions decreased.\n";
		}
		else {
			cout << "Smuggling succeeded undetected.\n";
		}
	}
}

void market::formtradeagrement()
{
	tradeaggrementactive = true;
	trustlevel += 15;
	cout << " Trade agreement formed. Trust increased.\n";
}

void market::breakaggrement()
{
	tradeaggrementactive = false;
	trustlevel -= 10;
	cout << "Trade agrement Broken . Trust Decreased .\n";
}

void market::showmarketstatus()
{
	cout << "\n--- Market & Diplomacy Status ---\n";
	cout << "Food Price: " << foodprice << " | Stock: " << foodstock << endl;
	cout << "Wood Price: " << woodprice << " | Stock: " << woodstock << endl;
	cout << "Weapons Price: " << weaponsprice << " | Stock: " << weaponsstock << endl;
	cout << "Trade Agreement: " << (tradeaggrementactive ? "Active" : "None") << endl;
	cout << "Trust Level: " << trustlevel << "/100\n";
	cout << "Smuggler Detected: " << (smuggling ? "Yes" : "No") << endl;
}
void market::save()
{
	ofstream write("save.txt", ios::app);
	if (write.is_open()) {
		write << "\n--- Market & Diplomacy Status ---\n";
		write << "Food Price: " << foodprice << " | Stock: " << foodstock << endl;
		write << "Wood Price: " << woodprice << " | Stock: " << woodstock << endl;
		write << "Weapons Price: " << weaponsprice << " | Stock: " << weaponsstock << endl;
		write << "Trade Agreement: " << (tradeaggrementactive ? "Active" : "None") << endl;
		write << "Trust Level: " << trustlevel << "/100\n";
		write << "Smuggler Detected: " << (smuggling ? "Yes" : "No") << endl;
		write.close();
	}
	else{
		cout << "\n SORRY SUCH FILE IS NOT FOUND !\n\n";
    }
}
