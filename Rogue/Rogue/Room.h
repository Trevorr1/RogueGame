#pragma once
#include "LoaderManager.h"
#include "Opponent.h"
#include "Trap.h"
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
	string printRoomText();
	string printOpponents();
	string printOpponentsFight();
	string printExits();

	string search();

	void addOpponent(Opponent* opponent);
	void addTrait(string trait);

	void generateTraits();
	void generateOpponents(int level);
	void generateEndOpponents(int level, int monsterSize);
	void generateItem();

	void setVisited() { m_Visited = true;  }
	void setStart() { m_startPoint = true; }
	void setEnd() { m_EndPoint = true; }

	void setNorth(Room* north) { m_North = north; }
	void setEast(Room* east) { m_East = east; }
	void setWest(Room* west) { m_West = west; }
	void setSouth(Room* south) { m_South = south; }

	void setStairUp(Room* up) { m_StairUp = up; }
	void setStairDown(Room* down) { m_StairDown = down; }

	Room* getNorth() { return m_North; }
	Room* getEast() { return m_East; }
	Room* getWest() { return m_West;  }
	Room* getSouth() { return m_South; }

	Room* getStairUp() { return m_StairUp; }
	Room* getStairDown() { return m_StairDown; }

	bool getVisited() { return m_Visited; }
	bool getSearched() { return m_Searched; }

	Trap* getTrap(){ return m_Trap; };
	void setTrap(int level);
	
	vector<Opponent*>* getOpponents();

private:
	vector<string> m_Traits;
	vector<Opponent*>* m_Opponents;
	vector<Opponent*>* opponents;

	Room *m_North, 
		*m_South, 
		*m_East, 
		*m_West;

	Room *m_StairUp,
		*m_StairDown;
	
	bool m_Visited,
		m_Searched,
		m_startPoint,
		m_EndPoint;

	string m_Size;
	string m_State;
	string m_Illumation;
	string m_Shape;
	string m_Content;
	string m_Special;

	Trap* m_Trap;
	Item* m_Item;
};

