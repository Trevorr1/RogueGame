#pragma once
#include <iostream>;
#include <vector>
#include "Opponent.h"

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

