#pragma once

#define DUNGEON_SIZE 20 //20

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


	void resolveDamageToPlayer();
	void resolveDamageToBaddies(string baddie);

	void attackPlayer(Opponent* baddie);
	void attackBaddie(Opponent* baddie);

	void save(vector <string *>* vectorSave);

private:
	vector<Floor*>* m_Floors;

	Floor* m_CurrentFloor;
	Room* m_CurrentRoom;
	
	Player* m_Player;
};

