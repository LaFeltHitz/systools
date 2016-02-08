#pragma once

#include "stdafx.h"

class TDUser : public TDDatabase
{
private:
	string password;
public:
	string getDDL() override;
	/* NO DEFAULT CONSTRUCTOR */
	TDUser() = delete;
	/* CTORS */
	TDUser(string name);
	TDUser(string name, string password);
	TDUser(TDDatabase * owner, string name);
	TDUser(TDDatabase * owner, string name, string password);

	/* PASSWORD ACCESSORS */
	string getPassword();
	void setPassword(string password);
	
	void print() override;
};