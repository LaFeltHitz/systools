#pragma once
#include "stdafx.h"

TDUser::TDUser(string name) : TDDatabase(name) {}

TDUser::TDUser( TDDatabase * owner, string name) : TDDatabase(owner, name) {}

TDUser::TDUser( TDDatabase * owner, string name, string password) : TDDatabase(owner, name), password{ password } {}

TDUser::TDUser(string name, string password) : TDDatabase(name), password{ password } {}

void TDUser::setPassword(string passwword)
{
	this->password = passwword;
}

string TDUser::getPassword() {
	return password;
}

string TDUser::getDDL()
{
	string fmt_ddl = "CREATE USER %s FROM %s AS PERM = %d BYTES, PASSWORD = '%s', SPOOL = %d BYTES, TEMPORARY = %d BYTES;";
	char buffer[1024];
	sprintf_s(buffer, fmt_ddl.c_str(), getName().c_str(), getOwner().getName().c_str(), getPerm(), getPassword().c_str(), getSpool(), getTemp());
	return buffer;
}

void TDUser::print() {
	printf("Name: %s, Owner: %s, Password: %s\n", getName().c_str(), getOwner().getName().c_str(), getPassword().c_str());
}