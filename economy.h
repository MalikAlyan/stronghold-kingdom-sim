#pragma once
# include<iostream>
# include<string>
using namespace std;
// economy.h

class Economy {
public:
    int treasury;
    float taxRatePeasants;
    float taxRateMerchants;
    float taxRateNobility;
    float inflationRate;
    int publicServiceCost;
    float corruptionLevel;
    int uncollectedTaxes;
    int revoltRisk;
    int tradeIncome;
    Economy();
    void collectTaxes(int peasants, int merchants, int nobility);
    void spendOnServices(int amount);
    void applyInflation();
    void updateRevoltRisk();
    void showEconomyStatus();
    void save();
};


