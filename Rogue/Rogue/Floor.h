#pragma once

#define SIZE 10

#include "Room.h"
#include <vector>

using namespace std;

class Floor
{
public:
	Floor();
	virtual ~Floor();

private:
	Room* rooms[SIZE][SIZE];
};

