// kingdom.h
#ifndef KINGDOM_H
#define KINGDOM_H

#include <string>
#include <iostream>
#include "leader.h"
#include "army.h"
#include "bank.h"
#include "market.h"
#include "resources.h"
using namespace std;

class Kingdom {
    king* king1;
    army* army1;
    bank* bank1;
    market* market1;
    int population;

public:
    Kingdom(string kingName,int,int,int);
    void taxPeople();
    void randomEvent();
    void saveState();
    void loadState();
    void run();
    ~Kingdom();
};

#endif
