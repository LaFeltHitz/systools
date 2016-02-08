#include "stdafx.h"

using namespace std;

void test()
{
	auto dbc = new TDUser{ "DBC", "DBC" };
	auto derel = new TDUser{ "Derel" };
	auto tisha = new TDDatabase{ derel, "Tisha", (perm_t)pow(1024, 3) };
	derel->setPassword("DH9514");
	derel->setOwner(dbc);
	derel->print();
	tisha->print();
	dbc->print();
	cout << derel->getDDL() << endl;
	cout << tisha->getDDL() << endl;
	delete dbc;
	delete derel;
	delete tisha;
}

int main()
{
	test();
	getchar();
	return 0;
}
