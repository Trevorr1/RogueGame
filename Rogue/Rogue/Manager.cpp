#include "Manager.h"

using namespace std;

Manager::Manager()
{

	Room* room = new Room();
	addMapLevel(room);

	Opponent* opponent = new Opponent();
	room->addOpponent(opponent);

	//printf("\nHello World\n\n");
	int foo = room->getOpponents().at(0)->get_level();
	
	cout << foo;

	
}


Manager::~Manager()
{
}

void Manager::addMapLevel(Room* room){
	mapLevels.push_back(room);
}