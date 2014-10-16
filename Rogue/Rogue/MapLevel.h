#pragma once
#include <iostream>;
#include <vector>
#include "Opponent.h"

using namespace std;

class MapLevel
{
public:
	MapLevel();
	~MapLevel();

	vector<Opponent> opponents;

	vector<Opponent> getOpponents();
	void addOpponent(Opponent opponent);
};

