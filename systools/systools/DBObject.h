#pragma once

#include "stdafx.h"

class DBObject
{
private:
	string name;

public:	
	virtual string getDDL() = 0;
	string getName();		
	void setName(string nm);
};

class User : public DBObject
{

public:
	string getDDL();
	User(string nm);
};


