#pragma once
#include <stdio.h>
#include <iostream>
#include "Opponent.h"
#include "Room.h"

class Manager
{
public:
	Manager();
	~Manager();

	vector<Room*> mapLevels;

	void addMapLevel(Room* room);
};

