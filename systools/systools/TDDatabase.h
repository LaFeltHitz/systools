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
	 vector<unique_ptr<TDDatabase>> children;

public:
	TDDatabase() = delete;
	TDDatabase(string name);
	TDDatabase(TDDatabase * owner, string name);
	TDDatabase(TDDatabase * owner, string name, perm_t perm);
	~TDDatabase();
	TDDatabase getOwner();
	void setOwner(TDDatabase * owner);
	string getDDL() override;
	void print() override;
	
	/* PERM SPACE ACCESSORS */
	perm_t getPerm();
	void setPerm(perm_t perm);
	
	/* SPOOL SPACE ACCESSORS */
	spool_t getSpool();
	void setSpool(spool_t spool);
	
	/* TEMP SPACE ACCESSORS */
	temp_t getTemp();
	void setTemp(temp_t temp);
};