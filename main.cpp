// main.cpp
#include "Kingdom.h"
# include"definitions.h"
int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	string name;
	cout << "Enter Name :";
	cin.ignore();
	getline(cin, name);
	player play(name);
	string name1;
	int age, leadership, stability;
	cout << "Please Enter name of King : ";
	cin.ignore();
	getline(cin, name1);
	cout << "Please Enter age of King : ";
	cin >> age;
	cout << "Please Enter Leadership Score of King : ";
	cin >> leadership;
	cout << "Please Stability Level  of King : ";
	cin >> stability;
	Kingdom kingdom1(name1, age, leadership, stability);
	kingelection election;
	market amount;
	population hello;
	resources resource;
	army Army;
	bank Bank;
	Economy economy;
	while (1) {
		SetConsoleTextAttribute(hConsole, 5);
		cout << " MAIN MENU : \n";
		cout << "1 - Start game \n" << "2 - Show game status \n";
		cout << "3 - Save All Data To File\n"<<"4 -Exit\n";
		int choice;
		cout << "Enter Choice : ";
		cin >> choice;
		if (choice == 1) {
			while (1) {
				SetConsoleTextAttribute(hConsole, 6);
				cout << "\n\t\t\t\t =  = = = STRONG HOLD KINGDOM MANAGEMENT = = = =\t\t\t\n\n";
				cout << "1.1 - Add player Details \n" << "1.2 - Build A kingdom\n";
				cout << "1.3 -Arrange Election for King\n" << "1.4 - Add leadership\n";
				cout << "1.5 -Manage Market Influence\n" << "1.6 -Add population Details \n";
				cout << "1.7 -Manage Resources\n" << "1.8 -Control Army\n";
				cout << "1.9 -Manage Bank system\n" << "1.10 -Handle economy\n";
				cout << "1.11 -Exit from Program\n";
				int opinion;
				cout << "Now you can Enter Your choice : ";
				cin >> opinion;
				if (opinion == 1) {
					addplayerdetails(play);

				}
				else if (opinion == 2) {
					managekingdom(kingdom1);
				}
				else if (opinion == 3) {
					manageelection(election);

				}
				else if (opinion == 4) {
					manageleadership();
				}
				else if (opinion == 5) {
					managemarket(amount);
				}
				else if (opinion == 6) {
					managepopulation(hello);
				}
				else if (opinion == 7) {
					manageresources(resource);
				}
				else if (opinion == 8) {
					managearmy(Army);
				}
				else if (opinion == 9) {
					managebank(Bank);
				}
				else if (opinion == 10) {
					manageeconomy(economy);
				}
				else if (opinion == 11) {
					cout << "Ok It's your Own Choice To Exit from Menu \n\n";
					break;
				}
				else {
					cout << "WRONG INPUT ! \n\n";
					continue;
				}
			}
		}
		else if (choice == 2) {
			cout << "\n\t\t\t\t - - - -DETAILS OF PLAYER - - - -\n\n ";
			play.showstatus();
			cout << "\n\t\t\t\t - - - -DETAILS OF ARMY - - - -\n\n ";
			Army.display();
			cout << "\n\t\t\t\t - - - -DETAILS OF RESOURCES - - - -\n\n ";
			resource.print();
		}
		else if (choice == 3) {
			play.save();
			amount.save();
			resource.save();
			Army.savetofile();
			Bank.savedata();
			economy.save();
			cout << "Congratulation All information has been Saved successfuly  ! \n\n";
		}
		else if(choice==4) {
			cout << "NOW YOU ARE EXITING FROM YOUR MAIN PROGRAM\n\n";
			break;
		}
		else {
			cout << "WRONG INPUT\n\n";
			continue;
		}
	}
}
