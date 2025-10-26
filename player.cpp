#include "player.h"
# include<fstream>
player::player(string name)
{
	playername = name;
	for (int i = 0;i < 5;i++) {
		allies[i] = "Unknown";
	}
	for (int i = 0;i <5;i++) {
		enemy[i] = "Unknown";
	}
	for (int i = 0;i < 10;i++) {
		messages[i] = "Empty";
	}
	trustlevel = 80;
	messagecount = 0;
	allycount = 0;
	enemycount = 0;
}
void player::sendmessage(string a, string b)
{
	if (messagecount < 10) {
		messages[messagecount++] = " To "  +a + " : " + b;
		cout << "Message sent to " << a << ".\n";
	}
	else {
		cout << "Sorry message History is full \n";
	}
}

void player::receivemessage(string a, string b)
{
	if (messagecount < 10) {
		messages[messagecount++] = " From " + a + " : " + b;
		cout << "Message received from " << a << ".\n";
	}
	else {
		cout << "Sorry message History is full \n";
	}
}

void player::deletemessage(string text)
{
	bool found = false;
	for (int i = 0;i < messagecount;i++) {
		if (messages[i] == text) {
			for (int j = i;j < messagecount - 1;j++) {
				messages[j] = messages[j + 1];
			}
			messagecount--;
			found = true;
			cout << "Message deleted: \"" << text << "\"\n";
			break;
		}
	}
	if (!found) {
		cout << "Message not found.\n";
	}
}

void player::clearallhistory()
{
	messagecount = 0;
	cout << "All messages have been cleared from History \n";
}

void player::formally(string a)
{
	if (allycount < 5) {
		allies[allycount++] = a;
		cout << "Alliance formed with " << a << endl;
	}
	else {
		cout << "Sorry alliance limit has been approached\n";
	}
}

void player::breakalliance(string formerAlly)
{
	for (int i = 0; i < allycount; i++) {
		if (allies[i] == formerAlly) {
			allies[i] = allies[allycount - 1]; // replace with last
			allycount--;

			if (enemycount < 5) {
				enemy[enemycount++] = formerAlly;
				trustlevel -= 20;
				cout << "Alliance with " << formerAlly << " broken! Trust reduced.\n";
			}
			else {
				cout << "Enemy list full!\n";
			}
			return;
		}
	}
	cout << "No alliance with " << formerAlly << " found.\n";
}

void player::betray(string target)
{
	if (enemycount < 5) {
		enemy[enemycount++] = target;
		trustlevel -= 25;
		cout << playername << " has betrayed " << target << "! Trust now: " << trustlevel << endl;
	}
	else {
		cout << "Sorry Enemy list is full \n";
	}
}

void player::showenemy()
{
	cout << "\nEnemies: ";
	for (int i = 0;i < enemycount;i++) {
		cout << enemy[i] << " ";
	}
	cout<<endl;
}

void player::showallies()
{
	cout << "\nAllies: ";
	for (int i = 0;i < allycount;i++) {
		cout << allies[i] << " ";
	}
	cout << endl;
}

void player::showmessages()
{
	cout << "\n--- Message History ---\n";
	for (int i = 0;i < messagecount;i++) {
		cout << messages[i] << " \n";
	}
	cout << endl;
}

void player::showstatus()
{
	cout << "\n--- Player Status ---\n";
	cout << "Player Name : " << playername << endl;
	cout << "Trust Level : " << trustlevel << endl;
	showallies();
	showenemy();
}

void player::save()
{
	ofstream write("save.txt", ios::app);
	if (write.is_open()) {
		write << "\n\t\t\t\t =  = = = STRONG HOLD KINGDOM MANAGEMENT = = = =\t\t\t\n\n";
		write << "\n--- Player Status ---\n";
		write << "Player Name : " << playername << endl;
		write << "Trust Level : " << trustlevel << endl;
	    write << "\n--- Message History ---\n";
		for (int i = 0;i < messagecount;i++) {
			write << messages[i] << " \n";
		}
		write << endl;
		write << "\nAllies: ";
		for (int i = 0;i < allycount;i++) {
			write << allies[i] << " ";
		}
		write << endl;
		write << "\nEnemies: ";
		for (int i = 0;i < enemycount;i++) {
			write << enemy[i] << " ";
		}
		write << endl;
		write.close();
	}
	else {
		cout << "SUCH FILE IS NOT FOUND ! \n\n";
	}
}

