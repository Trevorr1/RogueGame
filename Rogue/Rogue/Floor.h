#pragma once

#define SIZE 10

#include "Room.h"
#include "LoaderManager.h"
#include <vector>

using namespace std;

class Floor
{
public:
	Floor();
	Floor(int level, int rseed);
	virtual ~Floor();

	void generateRooms(Room* roomAbove, bool last);
	void updateMap();
	void printFloor();

	void setStairUp(Room* up);
	void setStairDown(Room* down);

	Room* getStairUp();
	Room* getStairDown();
	Room* getStartingRoom(){ return m_StartingRoom; };
	void save(vector <string*>* vectorSave);


private:
	Loader* loader;

	Room* m_Rooms[SIZE][SIZE];
	Room* m_StairDown;
	Room* m_StairUp;

	Room* m_StartingRoom;

	char* m_Map[(SIZE * 2)][(SIZE * 2)];


};

