#pragma once
#include <stdio.h>
#include <iostream>
#include "Opponent.h"
#include "MapLevel.h"

class Manager
{
public:
	Manager();
	~Manager();

	vector<MapLevel> mapLevels;

	void addMapLevel(MapLevel mapLevel);
};

