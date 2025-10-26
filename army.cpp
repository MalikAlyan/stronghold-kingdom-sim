#include "army.h"

army::army()
{
	armysize = 0;
	traininglevel = 0;
	weaponstock = 0;
	barackcapacity = 0;
	morale = 0;
	corruptionlevel = 0;
	warduration = 0;
	ispaid = false;
	generalname = "Unknown";
}

void army::input(int a, int b, int c, int d, float e, float f, float g, string h, bool i)
{
	armysize = a;
	traininglevel = b;
	weaponstock = c;
	barackcapacity = d;
	morale = e;
	corruptionlevel = f;
	warduration = g;
	ispaid = i;
	generalname = h;
}

void army::display() const
{
	cout << "Size of Army : " << armysize << endl;
	cout << "general of Army : " << generalname << endl;
	cout << "Training Level  of Army : " << traininglevel << endl;
	cout << "Weapon Capacity  of Army : " << weaponstock << endl;
	cout << "Barack capacity  of Army : " << barackcapacity << endl;
	cout << "Level of Corruption  in Army : " <<corruptionlevel << endl;
}

void army::savetofile()
{
	ofstream write("save.txt", ios::app);
	if (write.is_open()) {
		write << "\t\t\t - - - - DETAILS OF ARMY IN KINGDOM - - - -\n\n";
		write << "Size of Army : " << armysize << endl;
		write << "general of Army : " << generalname << endl;
		write << "Training Level  of Army : " << traininglevel << endl;
		write << "Weapon Capacity  of Army : " << weaponstock << endl;
		write << "Barack capacity  of Army : " << barackcapacity << endl;
		write << "Level of Corruption  in Army : " << corruptionlevel << endl;
		write.close();
	}
	else {
		cout << "File is not Found !\n\n";
	}
}
