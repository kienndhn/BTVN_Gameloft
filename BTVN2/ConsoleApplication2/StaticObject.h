#pragma once
#include "BaseObject.h"
class StaticObject :
	public BaseObject
{
public:
	StaticObject(int id, char* name, std::vector<float> pos);
	~StaticObject();
};

