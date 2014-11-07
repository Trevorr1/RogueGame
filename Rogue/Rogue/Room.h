#pragma once
#include "LoaderManager.h"
#include "Opponent.h"
#include "Trap.h"
#include "PoisonTrap.h"
#include <iostream>
#include <vector>



using namespace std;

class Room
{
public:
	Room();
	Room(int level, bool endBossRoom, int rseed);
	~Room();

	char* printRoom();

	void addOpponent(Opponent* opponent);
	void addTrait(string trait);

	void generateOpponents(int level);
	void generateEndOpponents(int level, int monsterSize);

	void setVisited();
	void setStart();
	void setEnd();

	void setNorth(Room* north);
	void setEast(Room* east);
	void setWest(Room* west);
	void setSouth(Room* south);

	void setStairUp(Room* up);
	void setStairDown(Room* down);

	Room* getNorth();
	Room* getEast();
	Room* getWest();
	Room* getSouth();

	bool getVisited();

	Trap* getTrap(){ return m_Trap; };
	void setTrap(int level);

	void setRoom(vector <string>* vectorLoaded);

	vector<Opponent*>* getOpponents();

private:
	vector<string> m_Traits;
	vector<Opponent*>* opponents;

	Room *m_North, 
		*m_South, 
		*m_East, 
		*m_West;

	Room *m_StairUp,
		*m_StairDown;
	
	bool m_Visited,
		m_startPoint,
		m_EndPoint;

	string m_Size;
	string m_State;
	string m_Illumation;
	string m_Shape;
	string m_Content;
	string m_Special;

	Trap* m_Trap;
};

