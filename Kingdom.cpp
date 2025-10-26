// kingdom.cpp
#include "Kingdom.h"
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <iostream>
#include "leader.h"
#include "army.h"
#include "bank.h"
#include "market.h"
#include "resources.h"
using namespace std;

Kingdom::Kingdom(string kingName,int a,int b,int c) {
    king1 = new king(kingName,a,b,c);
    army1= new army();
    bank1= new bank();
    market1 = new market();
    population = 1000;
}
void Kingdom::taxPeople() {
    try {
        srand(time(0));
        int tax = rand() % 100;
        int corruption = rand() % 15;
        bank1->input(tax,corruption);
        cout << "Collected " << tax << " gold in taxes.\n";
    }
    catch (exception& e) {
        cout << "Taxation error: " << e.what() << endl;
    }
}

void Kingdom::randomEvent() {
    srand(time(0));
    int event = rand() % 3;
    switch (event) {
    case 0: cout << "A plague has spread! Population decreases.\n"; population -= 100; break;
    case 1: cout << "Market crash! Resources lost.\n"; market1->trade("food", -20,false); break;
    case 2: cout << "Good harvest! Food increased.\n"; market1->trade("food", 30,false); break;
    }
}

void Kingdom::saveState() {
    ofstream file("save.txt",ios::app);
    if (!file) throw runtime_error("Failed to open file.");
    float treasury;
    cout << "please enter treasury amount : ";
    cin >> treasury;
    file << bank1->balance << " " << bank1->corruptionlevel;
    file << population  << endl;
    file.close();
    cout << "Game state saved successfully.\n";
}

void Kingdom::loadState() {
    ifstream file("save.txt");
    if (!file) throw runtime_error("Failed to open file.");
    file >> population;
    file >> bank1->balance >> bank1->corruptionlevel;
    file.close();
    cout << "Game state loaded successfully.\n";
}

void Kingdom::run() {
    int choice;
    do {
        cout << "\n=== Stronghold Kingdom Menu ===\n";
        cout << "1. Tax People\n2. Show Market\n3. Trigger Random Event\n4. Save\n5. Load\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1: taxPeople(); break;
        case 2: market1->showmarketstatus(); break;
        case 3: randomEvent(); break;
        case 4: saveState(); break;
        case 5: loadState(); break;
        }
    } while (choice != 0);
}

Kingdom::~Kingdom() {
    delete king1;
    delete army1;
    delete bank1;
    delete market1;
    cout << "Kingdom instance destroyed.\n";
}
