#pragma once

#define DUNGEON_SIZE 1 //20

#include "Floor.h"
#include "Player.h"
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
	Player* getPlayer() { return m_Player; }

	vector<Floor*>* getFloors(){ return m_Floors; };


	string resolveDamageToPlayer();
	string resolveDamageToBaddies(string baddie);

	string attackPlayer(Opponent* baddie);
	string attackBaddie(Opponent* baddie);

	void save(vector <string *>* vectorSave);

private:
	vector<Floor*>* m_Floors;

	Floor* m_CurrentFloor;
	Room* m_CurrentRoom;
	
	Player* m_Player;
};

