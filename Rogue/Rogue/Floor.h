#pragma once

#define SIZE 10

#include "Room.h"
#include "Loader.h"
#include <vector>

using namespace std;

class Floor
{
public:
	Floor();
	Floor(int rseed);
	virtual ~Floor();

	Room* generateRoom(int rseed);
	void generateRooms(Room* roomAbove, bool last);
	void updateMap();
	void printFloor();

	void setStairUp(Room* up);
	void setStairDown(Room* down);

	Room* getStairUp();
	Room* getStairDown();

	void save(vector <string*>* vectorSave);


private:
	Loader* loader;

	Room* m_Rooms[SIZE][SIZE];
	Room* m_StairDown;
	Room* m_StairUp;

	char* m_Map[(SIZE * 2)][(SIZE * 2)];


};

