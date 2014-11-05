#pragma once

#define DUNGEON_SIZE 20

#include "Floor.h"
#include <vector>

class Dungeon
{
public:
	Dungeon();
	Dungeon(int rseed);
	virtual ~Dungeon();

	void setCurrentFloor(Floor* current);
	void setCurrentRoom(Room* current);

	Floor* getCurrentFloor();
	Room* getCurrentRoom();

	void save(vector <string *>* vectorSave);

private:
	vector<Floor*> m_Floors;

	Floor* m_CurrentFloor;
	Room* m_CurrentRoom;
};

