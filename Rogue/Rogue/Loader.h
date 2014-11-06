#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Room.h"

using namespace std;

class Loader
{
public:
	Loader();
	virtual ~Loader();

	void loadRoomTraits();
	void loadTraps();
	void loadEnemyList();
	void loadItemList();
	void loadFileOpponents();

	vector<string>* getRoom_sizes(){ return room_sizes; };
	vector<string>* getRoom_states(){ return room_states; };
	vector<string>* getRoom_lightings(){ return room_lightings; };
	vector<string>* getRoom_shapes(){ return room_shapes; };
	vector<string>* getRoom_contents(){ return room_contents; };
	vector<string>* getRoom_specialTraits(){ return room_specialTraits; };

private:
	vector <string> vectorRoomKinds;
	vector<string>* room_sizes;
	vector<string>* room_states;
	vector<string>* room_lightings;
	vector<string>* room_shapes;
	vector<string>* room_contents;
	vector<string>* room_specialTraits;

	vector <string> vectorTrapKinds;
	vector<Trap*>* traps;
	vector<PoisonTrap*>* trap_poison;

	vector<Opponent*>* opponents;

	vector<string> item_list;
};

