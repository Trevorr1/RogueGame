#include "Room.h"

//Maplevel heeft ruimtes(rooms), 10x10x10x20
Room::Room()
{
}


Room::~Room()
{
}

vector<Opponent*> Room::getOpponents(){
	return opponents;
}

void Room::addOpponent(Opponent* opponent){
	opponents.push_back(opponent);
}
