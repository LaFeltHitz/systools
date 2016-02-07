#pragma once

#include "stdafx.h"

class TDUser : public TDDatabase
{
private:
	string password;
public:
	string getDDL() override;
	TDUser() = delete;
	TDUser(string name);
	TDUser(string name, string password);
	TDUser(shared_ptr<TDDatabase> owner, string name);
	TDUser(shared_ptr<TDDatabase> owner, string name, string password);
	string getPassword();
	void setPassword(string password);
	void print() override;
};