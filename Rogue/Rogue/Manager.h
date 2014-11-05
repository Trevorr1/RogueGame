#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#include "Dungeon.h"
#include "Opponent.h"
#include "Room.h"
#include "Menu.h"
#include "Loader.h"

class Manager
{
public:
	Manager();
	~Manager();

	vector<Room*> mapLevels;

	void addMapLevel(Room* room);

	void setState(Menu* menu);
	Menu* getState();

	void saveAll();
	void loadAll();

	void saveFile(vector <string>* vectorToSave, string textFileClass);
	vector <string>* loadFile(string textFileClass);
	void loadFileAllOpponents(vector <Opponent*>* vectorOpponents);
	Room* loadFileRandomRoom();

private:
	Menu* state;
	Dungeon* dungeon;
	//test Opponent
	Opponent* opponent;

	string textfile;
	vector <string*>* vectorSave;
};

