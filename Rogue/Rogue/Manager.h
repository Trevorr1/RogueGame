#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#include "Dungeon.h"
#include "Opponent.h"
#include "Room.h"
#include "Menu.h"

class Manager
{
public:
	Manager();
	~Manager();

	vector<Room*> mapLevels;

	void addMapLevel(Room* room);

	void setState(Menu* menu);
	Menu* getState();

	void save();
	void load();

private:
	Menu* state;
	Dungeon* dungeon;

	string textfile;
	vector <string*> vectorSave;
};

