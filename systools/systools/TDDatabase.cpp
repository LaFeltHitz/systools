#pragma once

#include "stdafx.h"

/* CONSTRUCTORS */
TDDatabase::TDDatabase(string name) : DBObject(name), owner{ nullptr }, permspace{ 0 }, spoolspace{ 0 }, tempspace{ 0 } {}

TDDatabase::TDDatabase(shared_ptr<TDDatabase> owner, string name) : DBObject(name), owner{ owner }, permspace{ 0 }, spoolspace{ owner->getSpool() }, tempspace{ owner->getTemp() } {}

TDDatabase::TDDatabase(shared_ptr<TDDatabase> owner, string name, perm_t perm) : DBObject(name), owner{ owner }, permspace(perm), spoolspace{ owner->getSpool() }, tempspace{ owner->getTemp() } {}

/* ACCESSORS */
void TDDatabase::setOwner( shared_ptr<TDDatabase> owner) {
	this->owner = owner;
}

TDDatabase TDDatabase::getOwner()
{
	if (owner == nullptr)
		return *(this);
	else
		return *(owner.get());
}

string TDDatabase::getDDL() {
	string fmt_ddl = "CREATE DATABASE %s FROM %s AS PERM = %d BYTES, SPOOL = %d BYTES, TEMPORARY = %d BYTES;";
	char buffer[1024];
	sprintf_s(buffer, fmt_ddl.c_str(), getName().c_str(), getOwner().getName().c_str(), getPerm(), getSpool(), getTemp());
	return buffer;
}

void TDDatabase::print()
{
	printf("Name: %s, Owner: %s\n", getName().c_str(), getOwner().getName().c_str());
}

TDDatabase::~TDDatabase() {
	printf("DTOR: %s\n", getName().c_str());
}

perm_t TDDatabase::getPerm()
{
	return permspace;
}

void TDDatabase::setPerm(perm_t perm) {
	this->permspace = perm;
}

spool_t TDDatabase::getSpool()
{
	return spoolspace;
}

void TDDatabase::setSpool(spool_t spool) {
	this->spoolspace = spool;
}

temp_t TDDatabase::getTemp()
{
	return tempspace;
}

void TDDatabase::setTemp(temp_t temp)
{
	this->tempspace = temp;
}