#pragma once
#include<vector>
class BaseObject
{
protected:
	int id;
	char* name;
	std::vector<float> pos;
public:	
	BaseObject(int id, char* name, std::vector<float> pos);
	~BaseObject();

	int getID() {
		return this->id;
	};

	char* getName();

	std::vector<float> getPosition() {
		return this->pos;
	}

	virtual void move();

	void printPosition();
};

