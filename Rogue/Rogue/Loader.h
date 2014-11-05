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
	void loadEnemyList();
	void loadItemList();

	Room* loadFileRandomRoom();

private:
	vector <string> vectorRoomKinds;
	vector<string> room_sizes;
	vector<string> room_states;
	vector<string> room_shapes;
	vector<string> room_lightings;
	vector<string> room_contents;
	vector<string> room_specialTraits;

	vector<string> enemies;

	vector<string> item_list;
};

