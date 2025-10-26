
#include "economy.h"
# include<fstream>
Economy::Economy() {
    treasury = 10000;
    taxRatePeasants = 0.1;
    taxRateMerchants = 0.15;
    taxRateNobility = 0.2;
    inflationRate = 1.0;
    publicServiceCost = 2000;
    corruptionLevel = 0.05;
    uncollectedTaxes = 0;
    revoltRisk = 0;
    tradeIncome = 0;
}

void Economy::collectTaxes(int peasants, int merchants, int nobility)
{
    int total = (peasants * taxRatePeasants + merchants * taxRateMerchants + nobility * taxRateNobility) * 10;
    int loss = total * corruptionLevel;
    treasury += (total - loss);
    uncollectedTaxes = loss;
    cout << "Collected Taxes: " << total - loss << endl;
    cout << "Lost to Corruption: " << loss << endl;
}

void Economy::spendOnServices(int amount)
{
    if(amount <= treasury) {
        cout << amount << " : Spent on Public Services \n";
        treasury -= amount;
    }
    else {
        cout << "Not enough money in treasury!\n";
    }
}

void Economy::applyInflation()
{
    inflationRate += 0.02;
    treasury = treasury * (1.0 / inflationRate);
    cout << "Inflation increased! Current rate: " << inflationRate << endl;
}

void Economy::updateRevoltRisk()
{
    if (uncollectedTaxes > 10, 000) {
        revoltRisk = 50;
    }
    else {
        revoltRisk = 20;
    }
}

void Economy::showEconomyStatus()
{
    cout << "\n--- Economy Status ---\n";
    cout << "Treasury: " << treasury << endl;
    cout << "Inflation Rate: " << inflationRate << endl;
    cout << "Corruption Level: " << corruptionLevel * 100 << "%" << endl;
    cout << "Uncollected Taxes: " << uncollectedTaxes << endl;
    cout << "Revolt Risk: " << revoltRisk << "%" << endl;
}

void Economy::save()
{
    fstream write("save.txt", ios::app);
    if (write.is_open()) {
        write << "\n--- Economy Status ---\n";
        write << "Treasury: " << treasury << endl;
        write << "Inflation Rate: " << inflationRate << endl;
        write << "Corruption Level: " << corruptionLevel * 100 << "%" << endl;
        write << "Uncollected Taxes: " << uncollectedTaxes << endl;
        write<< "Revolt Risk: " << revoltRisk << "%" << endl;
        write.close();
    }
    else {
        cout << "SORRY NO SUCH FILE IS FOUND ! \n\n";
    }
}

