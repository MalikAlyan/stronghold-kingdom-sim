#include "leader.h"

leader::leader(string a, int b, int c)
{
	name = a;
	age = b;
	leadershipscore = c;
}

void leader::showstats()
{
	cout << "Leader Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Leadership Score: " << leadershipscore << endl;
}

king::king(string a, int b, int c, int d):leader(a,b,c)
{
	kingstability = d;
}

void king::displayrole()
{
	cout << "\n👑 Role: King of the Realm\n";
}

void king::rulekingdom()
{
	cout << name << " is ruling the kingdom with stability level " << kingstability << ".\n";
}

commander::commander(string a, int b, int c, int d):leader(a,b,c)
{
	armysize = d;
}

void commander::displayrole()
{
	cout << "\n🛡️ Role: Army Commander\n";
}

void commander::commandarmy()
{
	cout << name << " commands an army of " << armysize << " soldiers.\n";
}

merchant::merchant(string a, int b, int c, int d):leader(a,b,c)
{
	marketinfluence = d;
}

void merchant::displayrole()
{
	cout << "\n💰 Role: Merchant Guild Leader\n";
}

void merchant::managetrade()
{
	cout << name << " manages the market with influence level " << marketinfluence << ".\n";
}
