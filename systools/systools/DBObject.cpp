#include "stdafx.h"

string DBObject::getName()
{
	return name;
}

void DBObject::setName(string nm)
{
	name = nm;
}

string User::getDDL()
{
	return string();
}

User::User(string nm) {
	setName(nm);
}