#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#include "Dungeon.h"
#include "Opponent.h"
#include "Room.h"
#include "Loader.h"

class Manager
{
public:
	Manager();
	~Manager();

	void init();

	void saveAll();
	void loadAll();

	string handleInput(string input);
	string handleRoomInput(string input);
	string handleFightInput(string input);
	string handleFleeInput(string input);
	string handleInventoryInput(string input);
	string handleAttackInput(string input);

	void fight() { m_Menu = FightMenu; }
	void flee() { m_Menu = FleeMenu; }
	void inventory() { m_Menu = InventoryMenu; }
	void map() { m_Menu = MapMenu; }
	void attack() { m_Menu = AttackMenu; }
	void explore() { m_Menu = RoomMenu; }

	void saveFile(vector <string>* vectorToSave, string textFileClass);
	vector <string>* loadFile(string textFileClass);
	void loadFileAllOpponents(vector <Opponent*>* vectorOpponents);
	Room* loadFileRandomRoom();

	string printText();
	string printOptions();

	string updateFleeOptions();
	string updateAttackOptions();


private:
	enum Menus{ RoomMenu, FightMenu, AttackMenu, FleeMenu, InventoryMenu, MapMenu};

	Menus m_Menu;

	Dungeon* dungeon;

	//test Opponent
	Opponent* opponent;

	string textfile;
	vector <string*>* vectorSave;
};

