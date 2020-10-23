#pragma once
#include "StaticObject.h"
class Tree :
	public StaticObject
{
public:
	Tree(int id, char *name, std::vector<float> pos);
	~Tree();
};

