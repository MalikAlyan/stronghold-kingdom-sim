#include "resources.h"
# include<fstream>
resources::resources()
{
	wood = 195;
	iron = 545;
	stone = 345;
	gold = 850;
	food = 1000;
	storagecapacity = 1200;
	weapons = 450;
	iswinter = false;
	saferoute = true;
}

void resources::produceresources()
{
	if (!saferoute) {
		cout << "Route is disrupted so production is low \n";
		wood += 50;
		iron += 45;
		stone += 40;
		gold += 50;
		if (iswinter) {
			food += 50;
			cout << "Winter Low ffod production \n";
		}
		else {
			food += 150;
		}
	}
	else {
		cout << "Route is best so production is high \n";
		wood += 100;
		iron += 75;
		stone += 80;
		gold += 90;
		if (iswinter) {
			food += 80;
			cout << "Winter Low ffod production \n";
		}
		else {
			food += 190;
		}
	}
	if (wood > storagecapacity) wood = storagecapacity;
	if (iron > storagecapacity) iron = storagecapacity;
	if (stone > storagecapacity) stone = storagecapacity;
	if (weapons > storagecapacity) weapons = storagecapacity;
	if (food > storagecapacity) food = storagecapacity;
}

void resources::useresources(int a, int b)
{
	if (a <= food) {
		food -= a;
		cout << a << " : food resources has been used \n";
	}
	else {
		cout << "Not enough food resources \n";
	}
	if (b <= weapons) {
		weapons -= b;
		cout << b << " : Weapons resources has been used \n";
	}
	else {
		cout << "Not enough weapons resources \n";
	}
	if (food < 0) food = 0;
	if (weapons < 0) weapons = 0;
}

void resources::applyweathereffect()
{
	iswinter = !iswinter;
	cout << "Weather is Changed .Winter is Now : " << (iswinter ? "Active . \n" : "Over . \n");
}

void resources::disruptroute()
{
	saferoute = false;
	cout << "Routes Have been Disrupted By enemies \n";
}

void resources::repairroute()
{
	saferoute = true;
	cout << "Now all routes have been repaired All is Right now \n";
}

void resources::print()
{
	cout << "\n--- Resource Status ---\n";
	cout << "Wood: " << wood << endl;
	cout << "Stone: " << stone << endl;
	cout << "Iron: " << iron << endl;
	cout << "Gold: " << gold << endl;
	cout << "Food: " << food << endl;
	cout << "Weapons: " << weapons << endl;
	cout << "Storage Capacity: " << storagecapacity << endl;
	cout << "Supply Routes: " << (saferoute ? "✅ Secure" : "❌ Disrupted") << endl;
	cout << "Season: " << (iswinter ? "Winter" : "Normal") << endl;
}

void resources::save()
{
	ofstream write("save.txt", ios::app);
	if (write.is_open()) {
		write << "\n--- Resource Status ---\n";
		write << "Wood: " << wood << endl;
		write << "Stone: " << stone << endl;
		write << "Iron: " << iron << endl;
		write << "Gold: " << gold << endl;
		write << "Food: " << food << endl;
		write << "Weapons: " << weapons << endl;
		write << "Storage Capacity: " << storagecapacity << endl;
		write << "Supply Routes: " << (saferoute ? "✅ Secure" : "❌ Disrupted") << endl;
		write << "Season: " << (iswinter ? "Winter" : "Normal") << endl;
		write.close();
	}
	else {
		cout << "SORRY WE HAVE FOUND NO SUCH FILE ! \n\n";
	}
}

