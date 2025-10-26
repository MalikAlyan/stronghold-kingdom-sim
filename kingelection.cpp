#include "kingelection.h"

kingelection::kingelection()
{
	kingname = "Unknown";
	faction[0] = faction[1] = faction[2] = 0;
	style = "unknown";
	stability = 0;
	corruptionlevel = 0;
	electionheld = false;
	assasinationrisk = false;
	popularity = 0;
}

void kingelection::setvalues(int a, int b, int c,  int d, float f, float g, string h, string i, bool j, bool k)
{
	kingname = h;
	faction[nobility] = a;
	faction[peasents] = b;
	faction[merchants] = c;
	style = i;
	stability = d;
	corruptionlevel = f;
	electionheld = j;
	assasinationrisk = k;
	popularity = g;
}
void kingelection::print() const
{
	cout << "Name of King of country : " << kingname << endl;
	cout << "Faction of Nobility voters  : " << faction[nobility] << endl;
	cout << "faction of Peasent voters  : " << faction[peasents] << endl;
	cout << "Faction of merchant voters : " << faction[merchants] << endl;
	cout << "Style  of King of country : " << style << endl;
	cout << "Corruption Level  of King of country : " << corruptionlevel << endl;
	cout << "Popularity  of King of country : " << popularity << endl;
}
