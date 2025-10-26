#include "definitions.h"
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void addplayerdetails(player &play) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Now we Are Showing Logo for you :\n\n";
	system("start \"\" \"C:\\Users\\pc\\Downloads\\Project_OOP\\player logo.jpeg\"");
	while (1) {
		SetConsoleTextAttribute(hConsole, 11);
		cout << "1.1.1 -Send Message\n" << "1.1.2 -Receive Message\n";
		cout << "1.1.3 -Delete Message\n" << "1.1.4 -Clear All Message History\n";
		cout << "1.1.5 -Form An Ally\n" << "1.1.6 -Break An Alliance\n";
		cout << "1.1.7 -Want To Betray\n" << "1.1.8 -Show Enemy List\n";
		cout << "1.1.9 -Show Allies List\n" << "1.1.10 -Show All Messages\n";
		cout << "1.1.11 -Show Player Status\n" << "1.1.12 -Exit\n";
		SetConsoleTextAttribute(hConsole, 3);
		int choice1;
		cout << "Please enter Your Choice : ";
		cin >> choice1;
		if (choice1 == 1) {
			string to, message;
			cout << "Please Type Name of Person :";
			cin.ignore();
			getline(cin, to);
			cout << "Please Type Message : ";
			getline(cin, message);
			play.sendmessage(to, message);
		}
		else if (choice1 == 2) {
			string from, message;
			cout << "Please Type Name of Person :";
			cin.ignore();
			getline(cin, from);
			cout << "Please Type Message : ";
			getline(cin, message);
			play.receivemessage(from, message);
		}
		else if (choice1 == 3) {
			string message;
			cout << "Plz Type Which Message Do You Want to Delete : ";
			cin.ignore();
			getline(cin, message);
			play.deletemessage(message);
		}
		else if (choice1 == 4) {
			play.clearallhistory();
		}
		else if (choice1 == 5) {
			string ally;
			cout << "Plz type With Which Do you want to Form An Ally : ";
			cin.ignore();
			getline(cin, ally);
			play.formally(ally);
		}
		else if (choice1 == 6) {
			string ally;
			cout << "Plz type With Which Do you want to Break An Ally : ";
			cin.ignore();
			getline(cin, ally);
			play.breakalliance(ally);
		}
		else if (choice1 == 7) {
			string x;
			cout << "Whom Person do you want to Betray : ";
			cin.ignore();
			getline(cin, x);
			play.betray(x);
		}
		else if (choice1 == 8) {
			play.showenemy();
		}
		else if (choice1 == 9) {
			play.showallies();
		}
		else if (choice1 == 10) {
			play.showmessages();
		}
		else if (choice1 == 11) {
			SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			play.showstatus();
		}
		else if (choice1 == 12) {
			cout << "Ok it's YOur Own Choice To Exit \n";
			break;
			return;
		}
		else {
			cout << "Sorry YOu Have Entered a wrong input Please try Again\n";
			continue;
		}
	}
}
void managekingdom(Kingdom &kingdom1) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "\nNow We Are Showing Your Kingdom Picture :\n\n";
	system("start \"\" \"C:\\Users\\pc\\Downloads\\Project_OOP\\kingdom.jpg\"");
	while (1) {
		SetConsoleTextAttribute(hConsole, 10);
		cout << "1.2.1 -Do you want to Implement Taxation\n" << "1.2.2 -Impement Random Event\n";
		cout << "1.2.3 -Save Data To File\n" << "1.2.4 -Load State\n";
		cout << "1.2.5 -Implement A Run Function\n" << "1.2.6 -Exit\n";
		SetConsoleTextAttribute(hConsole, 8);
		int choice1;
		cout << "Please enter Your Choice : ";
		cin >> choice1;
		if (choice1 == 1) {
			kingdom1.taxPeople();
		}
		else if (choice1 == 2) {
			kingdom1.randomEvent();
		}
		else if (choice1 == 3) {
			kingdom1.saveState();
		}
		else if (choice1 == 4) {
			kingdom1.loadState();
		}
		else if (choice1 == 5) {
			SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			kingdom1.run();
		}
		else if (choice1 == 6) {
			cout << "Ok it's your own choice to Exit \n";
			break;
			return;
		}
		else {
			cout << "Sorry You Have entered a wrong input \n";
			continue;
		}
	}
}

void manageelection(kingelection &election)
{
	cout << "Now You are Going To held Election\n\n";
	system("start \"\" \C:\\Users\\pc\\Downloads\\Project_OOP\\election.jpeg\"");
	while (1) {
		SetConsoleTextAttribute(hConsole, 1);
		cout << "1.3.1 -Add King Details\n" << "1.3.2 -Display All Details about King\n";
		cout << "1.3.3 -Exit\n";
		SetConsoleTextAttribute(hConsole, 4);
		int choice1;
		cout << "Please Enter your Choice : ";
		cin >> choice1;
		if (choice1 == 1) {
			if (election.electionheld) {
				cout << "Sorry Election Has held And king has Selected \n";
				election.print();
				break;
			}
			else {
				string name, style;
				int a, b, c, d;
				float e, f;
				cout << "Enter Name Of King : ";
				cin.ignore();
				getline(cin, name);
				cout << "Please Enter Style of King : ";
				getline(cin, style);
				cout << "Please Enter Faction Of Nobility voters : ";
				cin >> a;
				cout << "Please Enter faction of Peasent voters : ";
				cin >> b;
				cout << "Please Enter Faction of Merchant Voters : ";
				cin >> c;
				cout << "Now Please Enter stability Level of King : ";
				cin >> d;
				srand(time(0));
				e = rand() % 85;
				f = rand() % 20;
				if (e > 50 && f < 10) {
					election.setvalues(a, b, c, d, f, e, name, style, true, false);
					cout << "Congratulations Election Has held Successfully !\n";
				}
				else {
					election.setvalues(a, b, c, d, f, e, name, style, false, false);
					cout << "Elections Have not Held !\n";
				}
			}
		}
		else if (choice1 == 2) {
			if (election.electionheld) {
				cout << "Election Has held Successfully !\n";
				election.print();
			}
			else {
				SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
				cout << "Election Has not Held !\n";
				election.print();
			}
		}
		else if (choice1 == 3) {
			cout << "Ok it's Your Own Choice To exit \n";
			break;
			return;
		}
		else {
			cout << "Sorry you have entered a wrong Input \n";
			continue;
		}
	}
}

void manageleadership()
{
	while (1) {
		SetConsoleTextAttribute(hConsole, 5);
		cout << "1.4.1 -Add Leadership Details For King \n" << "1.4.2 -Add Details for Commander of Army\n";
		cout << "1.4.3 -Add Details for Head of Merchants\n" << "1.4.4 -Exit\n";
		int choice1;
		SetConsoleTextAttribute(hConsole, 6);
		cout << "Plz Enter Your Choice : ";
		cin >> choice1;
		if (choice1 == 1) {
			int age, leadership;
			string name;
			cout << "Plz Enter Name of King : ";
			cin.ignore();
			getline(cin, name);
			cout << "Plz Enter Age of King : ";
			cin >> age;
			srand(time(0));
			leadership = rand() % 65 + 15;
			int stability = rand() % 60 + 15;
			king hello(name, age, leadership, stability);
			cout << "1.4.1.1 -Make Role \n" << "1.4.1.2 -Display Details \n";
			int x;
			cout << "Enter Your Choice : ";
			cin >> x;
			if (x == 1) {
				hello.rulekingdom();
				cout << "This Is YOur King Picture \n\n";
				system("start \"\" \"C:\\Users\\pc\\Downloads\\Project_OOP\\leader.jpg\"");
			}
			else if (x == 2) {
				SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
				hello.displayrole();
			}
			else {
				cout << "Sorry You Have Entered wrong input \n";
				continue;
			}
		}
		else if (choice1 == 2) {
			int age, leadership;
			string name;
			cout << "Plz Enter Name of Commander : ";
			cin.ignore();
			getline(cin, name);
			cout << "Plz Enter Age of Commander : ";
			cin >> age;
			srand(time(0));
			leadership = rand() % 65 + 15;
			int army = rand() % 800 + 150;
			commander hello(name, age, leadership, army);
			cout << "1.4.1.1 -Command Army \n" << "1.4.1.2 -Display Details \n";
			int x;
			cout << "Enter Your Choice : ";
			cin >> x;
			if (x == 1) {
				hello.commandarmy();
			}
			else if (x == 2) {
				SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
				hello.displayrole();
			}
			else {
				cout << "Sorry You Have Entered wrong input \n";
				continue;
			}
		}
		else if (choice1 == 3) {
			int age, leadership;
			string name;
			cout << "Plz Enter Name of Merchant : ";
			cin.ignore();
			getline(cin, name);
			cout << "Plz Enter Age of Merchant : ";
			cin >> age;
			srand(time(0));
			leadership = rand() % 65 + 15;
			int stability = rand() % 60 + 15;
			merchant hello(name, age, leadership, stability);
			cout << "1.4.1.1 -Make Role \n" << "1.4.1.2 -Display Details \n";
			int x;
			cout << "Enter Your Choice : ";
			cin >> x;
			if (x == 1) {
				hello.managetrade();
			}
			else if (x == 2) {
				SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
				hello.displayrole();
			}
			else {
				cout << "Sorry You Have Entered wrong input \n";
				continue;
			}
		}
		else if (choice1 == 4) {
			cout << "Ok it's your own choice to Exit\n";
			break;
			return;
		}
		else {
			cout << "Sorry You have entered A wrong Innput \n";
			continue;
		}
	}
}

void managemarket(market &hello)
{
	while (1) {
		SetConsoleTextAttribute(hConsole, 7);
		cout << "1.5.1 -Update prices of Objects\n" << "1.5.2 -Make a trade\n";
		cout << "1.5.3 -Make A Trade Aggrement\n" << "1.5.4 -Break a trade aggrement\n";
		cout << "1.5.5 -Display Market Status\n" << "1.5.6 -Exit\n";
		int choice1;
		SetConsoleTextAttribute(hConsole, 8);
		cout << "Please Enter Your Choice : ";
		cin >> choice1;
		if (choice1 == 1) {
			hello.updateprices();
		}
		else if (choice1 == 2) {
			string name;
			float amount;
			cout << "Please Enter Name of Product Do you want to Trade :";
			cin.ignore();
			getline(cin, name);
			cout << "Please Enter Amount : ";
			cin >> amount;
			hello.trade(name, amount, true);
		}
		else if (choice1 == 3) {
			hello.formtradeagrement();
		}
		else if (choice1 == 4) {
			hello.breakaggrement();
		}
		else if (choice1 == 5) {
			SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			hello.showmarketstatus();
		}
		else if (choice1 == 6) {
			cout << "Ok It's your Own Choice to Exit\n";
			break;
			return;
		}
		else {
			cout << "Sorry You Have Enetered A Wrong input Try again\n";
			continue;
		}
	}
}
void managepopulation(population &amount)
{
	system("start \"\" \"C:\\Users\\pc\\Downloads\\Project_OOP\\population.jpeg\"");
	while (1) {
		SetConsoleTextAttribute(hConsole, 9);
		cout << "1.6.1 -Add Population Details \n" << "1.6.2 -Display Population details\n";
		cout << "1.6.3 -Exit\n";
		int choice1;
		SetConsoleTextAttribute(hConsole, 10);
		cout << "Please Enter Your Choice : ";
		cin >> choice1;
		if (choice1 == 1) {
			int size, peasents, merchants, nobility, military, job, health, food;
			float tax1, tax2, tax3, tax4;
			cout << "Plz enter Size of Population : ";
			cin >> size;
			cout << "Plz enter Population of peasents : ";
			cin >> peasents;
			cout << "Plz Enter Population Of Merchants : ";
			cin >> merchants;
			cout << "Plz Enter Population of Military : ";
			cin >> military;
			cout << "Plz enter Population of Nobility : ";
			cin >> nobility;
			srand(time(0));
			job = rand() % 35 + 15;
			health = rand() % 45 + 19;
			food = rand() % 65 + 19;
			tax1 = rand() % 7 + 2;
			tax2 = rand() % 10 + 3;
			tax3 = rand() % 5 + 3;
			tax4 = rand() % 11 + 4;
			amount.setint(size, nobility, peasents, merchants, military, job, food, health);
			amount.setother(tax1, tax3, tax4, tax2, false, false, false);
		}
		else if (choice1 == 2) {
			SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			amount.display();
		}
		else if (choice1 == 3) {
			cout << "Ok It's your own Choice To Exit\n";
			break;
			return;
		}
		else {
			cout << "Sorry you have entered Wrong input plz Try again\n";
			continue;
		}
	}
}

void manageresources(resources &resource)
{
	while (1) {
		SetConsoleTextAttribute(hConsole, 11);
		cout << "1.7.1 -Produce Resources\n" << "1.7.2 -Use Resources\n";
		cout << "1.7.3 -Apply Weather Effect\n" << "1.7.4 -Disrupt Route\n";
		cout << "1.7.5 -Repair Route\n" << "1.7.6 -Print Resource details\n";
		cout << "1.7.7 -Exit\n";
		int choice1;
		SetConsoleTextAttribute(hConsole, 12);
		cout << "Please Enter your Choice : ";
		cin >> choice1;
		if (choice1 == 1) {
			resource.produceresources();
		}
		else if (choice1 == 2) {
			int food, weapons;
			cout << "Enter Amount Of Food :";
			cin >> food;
			cout << "Enter Amount of Weapons :";
			cin >> weapons;
			resource.useresources(food, weapons);
		}
		else if (choice1 == 3) {
			resource.applyweathereffect();
		}
		else if (choice1 == 4) {
			resource.disruptroute();
		}
		else if (choice1 == 5) {
			resource.repairroute();
		}
		else if (choice1 == 6) {
			SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			resource.print();
		}
		else if (choice1 == 7) {
			cout << "Ok It's your own choice to Exit\n";
			break;
			return;
		}
		else {
			cout << "Wrong input Plz Try Again\n";
			continue;
		}

	}
}
void managearmy(army& Army) {
	SetConsoleTextAttribute(hConsole, 13);
	cout << "Step To Enter All Details About Army\n\n";
	int size, level, stock, capacity;
	float morale, corruption, warduration;
	string generalname;
	cout << "Please Enter Size of Army :";
	cin >> size;
	srand(time(0));
	level = rand() % 75 + 8;
	stock = rand() % 75 + 8;
	capacity = rand() % 65 + 8;
	morale = rand() % 85 + 8;
	corruption = rand() % 25 + 8;
	warduration = rand() % 2 + 1;
	cout << "Now Please Enter Name of General :";
	cin.ignore();
	getline(cin, generalname);
	Army.input(size, level, stock, capacity, morale, corruption, warduration, generalname, true);
	cout << "\n Complete Details Of Your Army\n\n";
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	Army.display();
	cout << "\n NOW THIS IS PICTURE OF YOUR ARMY ! \n\n";
	system("start \"\" \"C:\\Users\\pc\\Downloads\\Project_OOP\\pak army.jpg\"");
}
void managebank(bank& Bank) {
	SetConsoleTextAttribute(hConsole, 14);
	cout << "\n NOW YOU ARE GOING TO BANK 1\n\n";
	system("start \"\" \"C:\\Users\\pc\\Downloads\\Project_OOP\\bank.jpg\"");
	float balance, level;
	srand(time(0));
	cout << "Enter Amount to Deposit :";
	cin >> balance;
	level = rand() & 15 + 10;
	if (balance < 2000) {
		cout << "Sorry You have entered wrong Input \n\n";
		Bank.input(2000, level);
	}
	else {
		Bank.input(balance, level);
	}
	while (1) {
		SetConsoleTextAttribute(hConsole, 15);
		cout << "1.8.1 -Take A loan\n\n" << "1.8.2 -Repay Loan\n\n";
		cout << "1.8.3 -Apply Interest\n\n" << "1.8.4 -Perform Audit\n\n";
		cout << "1.8.5 -Manage Security\n\n" << "1.8.6 -Display Details\n\n";
		cout << "1.8.7 -Exit\n";
		SetConsoleTextAttribute(hConsole, 1);
		int choice1;
		cout << "Enter your Choice :";
		cin >> choice1;
		if (choice1 == 1) {
			srand(time(0));
			float amount;
			cout << "Enter How Much Do you want to take as Loan ;";
			cin >> amount;
			int a, b;
			a = rand() % 10 + 5;
			b = rand() % 5 + 5;
			if (amount < 0) {
				cout << "Sorry You Have Entered A wrong Input \n";
				continue;
			}
			else {
				Bank.loantaken(amount, b, a);
			}

		}
		else if (choice1 == 2) {
			float amount;
			cout << "Enter Amount : ";
			cin >> amount;
			if (amount < 0) {
				cout << "Wrong Input\n\n";
				continue;
			}
			else {
				Bank.repayloan(amount);
			}
		}
		else if (choice1 == 3) {
			int current,
			srand(time(0));
			current = rand() % 12 + 2;
			Bank.applyinterest(current, 4.5);
		}
		else if (choice1 == 4) {
			srand(time(0));
			float cost = rand() % 100 + 250;
			Bank.performaudit(cost);
		}
		else if (choice1 == 5) {
			srand(time(0));
			float amount = rand() % 150 + 450;
			Bank.managesecurity(amount);
		}
		else if (choice1 == 6) {
			SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			Bank.print();
		}
		else if (choice1 == 7) {
			cout << "Ok It's Your Own choice to Exit\n\n";
			break;
		}
		else {
			cout << "Wrong Input\n\n";
			continue;
		}
	}
}
void manageeconomy(Economy& economy) {
	while (1) {
		SetConsoleTextAttribute(hConsole, 4);
		cout << "1.10.1 -Collect Taxes\n" << "1.10.2 -Spend On services\n";
		cout << "1.10.3 -Apply Inflation\n" << "1.10.4 -Update Revolt Risk\n";
		cout << "1.10.5 -Show Economy Status\n" << "1.10.6 -Exit\n";
		int choice1;
		SetConsoleTextAttribute(hConsole, 5);
		cout << "PLease Enter Your Choice :";
		cin >> choice1;
		if (choice1 == 1) {
			int peasents, merchants, nobility;
			srand(time(0));
			peasents = rand() % 250 + 150;
			merchants = rand() % 200 + 150;
			nobility = rand() % 250 + 100;
			economy.collectTaxes(peasents, merchants, nobility);
		}
		else if (choice1 == 2) {
			float amount;
			cout << "Please Enter YOur Amount : ";
			cin >> amount;
			economy.spendOnServices(amount);
		}
		else if (choice1 == 3) {
			economy.applyInflation();
		}
		else if (choice1 == 4) {
			economy.updateRevoltRisk();
		}
		else if (choice1 == 5) {
			SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			economy.showEconomyStatus();
		}
		else if (choice1 == 6) {
			cout << "Ok It's your own Choice To Exit\n\n";
			break;
		}
		else {
			cout << "Wrong Input\n\n";
			continue;
		}
	}
}