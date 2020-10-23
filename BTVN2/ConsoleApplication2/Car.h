#pragma once
#include "DynamicObject.h"
class Car :
	public DynamicObject
{
public:
	Car(int id, char* name, std::vector<float> pos);
	~Car();
};

