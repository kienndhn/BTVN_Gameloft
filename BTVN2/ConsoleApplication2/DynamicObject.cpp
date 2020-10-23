#include "stdafx.h"
#include "DynamicObject.h"


DynamicObject::DynamicObject(int id, char* name, std::vector<float> pos):BaseObject(id, name, pos)
{
}


DynamicObject::~DynamicObject()
{
}

void DynamicObject::move() {
	this->pos[0] += 1;
	this->pos[1] += 1;
}