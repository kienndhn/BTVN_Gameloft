#pragma once
#include "BaseObject.h"
class DynamicObject :
	public BaseObject
{
public:

	DynamicObject(int id, char* name, std::vector<float> pos);
	~DynamicObject();

	void move();
};

