#include "stdafx.h"

DBObject::DBObject(string nm) {
	this->name = nm;
}

string DBObject::getName()
{
	return name;
}

void DBObject::setName(string nm)
{
	this->name = nm;
}



