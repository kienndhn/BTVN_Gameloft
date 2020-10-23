#pragma once
#include "DynamicObject.h"
class Motorbike :
	public DynamicObject
{
public:
	Motorbike(int id, char* name, std::vector<float> pos);
	~Motorbike();
};

