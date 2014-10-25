#pragma once

#define DUNGEON_SIZE 10

#include "Floor.h"
#include <vector>

class Dungeon
{
public:
	Dungeon();
	virtual ~Dungeon();

	void buildFloors();

private:
	vector<Floor*> m_Floors;
};

