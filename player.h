#pragma once
# include<iostream>
# include<string>
using namespace std;
class player
{
public:
	string playername;
	string allies[5];
	string enemy[5];
	string messages[10];
	int allycount;
	int enemycount;
	int messagecount;
	int trustlevel;
	player(string name);
	void sendmessage(string, string);
	void receivemessage(string, string);
	void deletemessage(string);
	void clearallhistory();
	void formally(string);
	void breakalliance(string);
	void betray(string);
	void showenemy();
	void showallies();
	void showmessages();
	void showstatus();
	void save();
};

