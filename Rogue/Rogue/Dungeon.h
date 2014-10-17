#pragma once
#include "Floor.h"
#include <vector>

class Dungeon
{
public:
	Dungeon();
	virtual ~Dungeon();

private:
	vector<Floor*> *m_Floors;
};

