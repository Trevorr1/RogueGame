#pragma once

#define DUNGEON_SIZE 10

#include "Floor.h"
#include <vector>

class Dungeon
{
public:
	Dungeon();
	virtual ~Dungeon();

	void setCurrentFloor(Floor* current);
	void setCurrentRoom(Room* current);

	Floor* getCurrentFloor();
	Room* getCurrentRoom();

private:
	vector<Floor*> m_Floors;

	Floor* m_CurrentFloor;
	Room* m_CurrentRoom;
};

