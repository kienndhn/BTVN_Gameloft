// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include "vld.h"


enum actionEnum {
	unlock,
	open,
	close,
	lock
};

int m_nCurrentState;



class StateBase
{
public:
	virtual StateBase* GetNextState(actionEnum action) = 0;
	virtual    char* ToString() = 0;
};

// State Opened
class Opened : public StateBase
{
public:
	virtual StateBase* GetNextState(actionEnum action);
	virtual    char* ToString() {
		return "is Opened";
	}
};

// State Closed
class Closed : public StateBase
{
public:
	virtual StateBase* GetNextState(actionEnum action);
	virtual    char* ToString() {
		return "is Closed";
	}
};

// State Blocked
class Blocked : public StateBase
{
public:
	virtual StateBase* GetNextState(actionEnum action);
	virtual    char* ToString() {
		return "is Blocked";
	}
};


StateBase* Opened::GetNextState(actionEnum action) {
	if (action == close) {
		printf("\nClose the door\n");
		return new Closed();
	}
	else {
		printf("\nAction is not allowed\n");
		return new Opened(*this);
	}
}

StateBase* Closed::GetNextState(actionEnum action) {
	if (action == open) {
		printf("\nOpen the door\n");
		return new Opened();
	}

	if (action == lock) {
		printf("\nLock the door\n");
		return new Blocked();
	}
	else {
		printf("\nAction is not allowed\n");
		return new Closed(*this);
	}
}

StateBase* Blocked::GetNextState(actionEnum action) {
	if (action == unlock) {
		printf("\nUnlock the door\n");
		return new Closed();
	}
	else {
		printf("\nAction is not allowed\n");
		return new Blocked(*this);
	}
	
}



class Door
{
private:
	StateBase* m_pState;

public:
	Door() {}
	Door(StateBase *pContext) {
		m_pState = pContext;
	}
	~Door() {
		delete m_pState;
	}

	void StateChanged(actionEnum action) {
		if (m_pState) {
			StateBase *pState = m_pState->GetNextState(action);
			delete m_pState;
			m_pState = pState;

		}
	}
	char* GetNameState() {
		return m_pState->ToString();
	}
};

void main()
{

	Door *door = new Door(new Opened());
	printf("\nDoor %s\n", door->GetNameState());

	//dong cua
	door->StateChanged(close);
	printf("\nDoor %s\n", door->GetNameState());

	//khoa cua
	door->StateChanged(lock);
	printf("\nDoor %s\n", door->GetNameState());

	//thuc hiện mo khi dang block
	door->StateChanged(open);
	printf("\nDoor %s\n", door->GetNameState());
	
	//mo khoa
	door->StateChanged(unlock);
	printf("\nDoor %s\n", door->GetNameState());

	//mo cua
	door->StateChanged(open);
	printf("\nDoor %s\n", door->GetNameState());

	delete door;
	system("pause");
}
