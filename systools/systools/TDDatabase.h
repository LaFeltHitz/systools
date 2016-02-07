#pragma once

#include "stdafx.h"
using perm_t = unsigned long long;
using spool_t = unsigned long long;
using temp_t = unsigned long long;

class TDDatabase : public DBObject
{
private:
	 shared_ptr<TDDatabase> owner;
	 perm_t permspace;
	 spool_t spoolspace;
	 temp_t tempspace;

public:
	TDDatabase() = delete;
	TDDatabase(string name);
	TDDatabase( shared_ptr<TDDatabase> owner, string name);
	TDDatabase(shared_ptr<TDDatabase> owner, string name, perm_t perm);
	~TDDatabase();
	TDDatabase getOwner();
	void setOwner(shared_ptr<TDDatabase> owner);
	string getDDL() override;
	void print() override;
	perm_t getPerm();
	void setPerm(perm_t perm);
	spool_t getSpool();
	void setSpool(spool_t spool);
	temp_t getTemp();
	void setTemp(temp_t temp);
};