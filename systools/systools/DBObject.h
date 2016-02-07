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
	DBObject(string nm);
	virtual void print() =  0;
};


