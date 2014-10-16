#include "Manager.h"

using namespace std;

Manager::Manager()
{

	MapLevel* mapLevel1 = new MapLevel();
	addMapLevel(*mapLevel1);

	Opponent* opponent = new Opponent();
	mapLevel1->addOpponent(*opponent);

	//printf("\nHello World\n\n");
	
	cout << mapLevel1->getOpponents().at(0).get_level();

	
}


Manager::~Manager()
{
}

void Manager::addMapLevel(MapLevel mapLevel){
	mapLevels.push_back(mapLevel);
}