#include "stdafx.h"

using namespace std;

int main()
{
	auto dbc = make_shared<TDUser>(TDUser{ "DBC", "DBC" });
	TDUser derel{ "Derel" };
	derel.setPassword("DH9514");
	TDDatabase tisha{ make_shared<TDUser>(derel), "Tisha", (perm_t)pow(1024,3) };
	derel.setOwner(dbc);
	cout << "Use Count: " << dbc.use_count() << endl;
	derel.print();
	tisha.print();
	dbc.get()->print();
	cout << derel.getDDL() << endl;
	cout << tisha.getDDL() << endl;
	getchar();
	return 0;
}
