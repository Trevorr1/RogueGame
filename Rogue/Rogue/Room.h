#pragma once

#include "Opponent.h"
#include <iostream>
#include <vector>

using namespace std;

class Room
{
public:
	Room();
	~Room();

	vector<Opponent> opponents;

	vector<Opponent> getOpponents();
	void addOpponent(Opponent opponent);
};

