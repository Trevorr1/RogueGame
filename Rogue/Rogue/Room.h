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

	void addOpponent(Opponent* opponent);
	vector<Opponent*> getOpponents();

private:
	vector<Opponent*> opponents;

	Room *m_North, 
		*m_South, 
		*m_East, 
		*m_West;

};

