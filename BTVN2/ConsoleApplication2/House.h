#pragma once
#include "StaticObject.h"
class House :
	public StaticObject
{
public:
	House(int id, char* name, std::vector<float> pos);
	~House();
};

