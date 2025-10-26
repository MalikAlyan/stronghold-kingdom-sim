#pragma once
# include<iostream>
# include<windows.h>
# include<string>
#include "leader.h"
#include "army.h"
#include "bank.h"
#include "market.h"
#include "resources.h"
# include"Kingdom.h"
# include"economy.h"
# include"player.h"
# include"population.h"
# include"kingelection.h"
# include<cstdlib>
# include<ctime>
using namespace std;
void addplayerdetails(player &);
void managekingdom(Kingdom &);
void manageelection(kingelection &);
void manageleadership();
void managemarket(market &);
void managepopulation(population &);
void manageresources(resources &);
void managearmy(army&);
void managebank(bank&);
void manageeconomy(Economy&);
