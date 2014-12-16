#include "MenuRoom.h"
#include "MenuFactory.h"
#include "Room.h"

using namespace std;

MenuRoom::MenuRoom(Room* room)
{
	m_Options.push_back("fight");
	m_Options.push_back("run");
	m_Options.push_back("search");
	m_Options.push_back("rest");
	m_Options.push_back("items");
	m_Options.push_back("map");
	
	room->printRoomText();
	printOptions();
}


MenuRoom::~MenuRoom()
{
}

void MenuRoom::handleInput(MenuFactory* context, string input)
{
	if (input == "fight")
	{
		context->setMenu(context->getAttackMenu());
	}
	else if (input == "run")
	{
		context->setMenu(context->getFlightMenu(context->getDungeon()->getCurrentRoom()));
	}
	else if (input == "search")
	{
		search(context);
	}
	else if (input == "rest")
	{
		context->getDungeon()->getPlayer()->rest();
		printOptions();
	}
	else if (input == "items")
	{
		context->setMenu(context->getInventoryMenu());
	}
	else if (input == "map"){
		map(context);
	}
	else if (input == "mapcheat"){
		context->getDungeon()->getCurrentFloor()->updateMapCheat(context->getDungeon()->getCurrentRoom());
		context->getDungeon()->getCurrentFloor()->printFloor();
		printOptions();
	}
	else{
		cout << "Choose another option please.\n\n" << endl;
	}
}

void MenuRoom::search(MenuFactory* context)
{
	context->getDungeon()->getCurrentRoom()->search();
	printOptions();
}

void MenuRoom::map(MenuFactory* context)
{
	context->getDungeon()->getCurrentFloor()->updateMap(context->getDungeon()->getCurrentRoom());
	context->getDungeon()->getCurrentFloor()->printFloor();
	printOptions();
}