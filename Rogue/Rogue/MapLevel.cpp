#include "MapLevel.h"

//Maplevel heeft ruimtes(rooms), 10x10x10x20
MapLevel::MapLevel()
{
}


MapLevel::~MapLevel()
{
}

vector<Opponent> MapLevel::getOpponents(){
	return opponents;
}

void MapLevel::addOpponent(Opponent opponent){
	opponents.push_back(opponent);
}
