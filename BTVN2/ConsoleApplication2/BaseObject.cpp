#include "stdafx.h"
#include "BaseObject.h"
#include <string.h>

BaseObject::BaseObject(int id, char* name, std::vector<float> pos)
{
	this->id = id;
	int n = strlen(name);
	this->name = new char[n + 1];
	strcpy_s(this->name,n + 1, name);
	this->pos.push_back(pos[0]);
	this->pos.push_back(pos[1]);
}


BaseObject::~BaseObject()
{
	delete[] this->name;
}


void BaseObject::move()
{
}


void BaseObject::printPosition() {
	std::vector<float> t = this->getPosition();
	printf("%s(x, y) = (%f, %f)\n", this->getName(),t[0], t[1]);
}

char* BaseObject::getName(){
	return this->name;
}