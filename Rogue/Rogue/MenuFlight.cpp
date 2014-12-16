#include "MenuFlight.h"
#include "MenuFactory.h"


MenuFlight::MenuFlight()
{
}

MenuFlight::MenuFlight(Room* room)
{
	updateOptions(room);

	// flavour text to ask the player where he wants to go
	printOptions();
}

MenuFlight::~MenuFlight()
{
}

void MenuFlight::handleInput(MenuFactory* context, string input)
{
	if (std::find(m_Options.begin(), m_Options.end(), input) != m_Options.end()) 
	{
		Room* nextMove = nullptr;
		if (input == "north")
		{
			nextMove = context->getDungeon()->getCurrentRoom()->getNorth();
		}
		else if (input == "east")
		{
			nextMove = context->getDungeon()->getCurrentRoom()->getEast();
		}
		else if (input == "west")
		{
			nextMove = context->getDungeon()->getCurrentRoom()->getWest();
		}
		else if (input == "south")
		{
			nextMove = context->getDungeon()->getCurrentRoom()->getSouth();
		}
		else if (input == "up")
		{
			nextMove = context->getDungeon()->getCurrentRoom()->getStairUp();
			
			//search floor and set current floor-1
			for (int i = 0; i < context->getDungeon()->getFloors()->size(); i++){
				if (context->getDungeon()->getCurrentFloor() == context->getDungeon()->getFloors()->at(i)){
					context->getDungeon()->setCurrentFloor(context->getDungeon()->getFloors()->at(i-1));
				}
			}
		}
		else if (input == "down")
		{
			nextMove = context->getDungeon()->getCurrentRoom()->getStairDown();

			//search floor and set current floor+1
			for (int i = 0; i < context->getDungeon()->getFloors()->size(); i++){
				if (context->getDungeon()->getCurrentFloor() == context->getDungeon()->getFloors()->at(i)){
					context->getDungeon()->setCurrentFloor(context->getDungeon()->getFloors()->at(i+1));
					break;
				}
			}
		}
		//set Room
		context->getDungeon()->getCurrentRoom()->setVisited();
		context->getDungeon()->setCurrentRoom(nextMove);

		context->setMenu(context->getRoomMenu(nextMove));
	}
	else {
		cout << "Choose another option please." << endl << endl;
		printOptions();
	}
}

void MenuFlight::updateOptions(Room* room)
{
	if (room->getNorth() != nullptr)
	{
		m_Options.push_back("north");
	}
	if (room->getEast() != nullptr)
	{
		m_Options.push_back("east");
	}
	if (room->getWest() != nullptr)
	{
		m_Options.push_back("west");
	}
	if (room->getSouth() != nullptr)
	{
		m_Options.push_back("south");
	}
	if (room->getStairUp() != nullptr)
	{
		m_Options.push_back("up");
	}
	if (room->getStairDown() != nullptr)
	{
		m_Options.push_back("down");
	}

}