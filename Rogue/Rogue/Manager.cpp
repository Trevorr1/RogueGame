#include "Manager.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Manager::Manager()
{
	textfile = "data_save.txt";
	//LoaderManager::getInstance();

	init();
}


Manager::~Manager()
{
	delete dungeon;
}

void Manager::init(){
	//create Dungeon and start at lv 1 (according to the code lv 0)
	int rseed = 5;
	dungeon = new Dungeon(5);
	dungeon->getFloors()->at(0)->updateMap();
	dungeon->getFloors()->at(0)->printFloor();

	dungeon->setCurrentFloor(dungeon->getFloors()->at(0));
	m_Menu = RoomMenu;
}


string Manager::handleInput(string input)
{
	string ret = "";
	switch (m_Menu)
	{
	case RoomMenu:
		ret += handleRoomInput(input);
		break;
	case FightMenu:
		ret += handleFightInput(input);
		break;
	case FleeMenu:
		ret += handleFleeInput(input);
		break;
	case InventoryMenu:
		ret += handleInventoryInput(input);
		break;
	case MapMenu:
		dungeon->getCurrentFloor()->printFloor();
		explore();
		break;
	case AttackMenu:
		ret += handleAttackInput(input);
		break;
	}
	return ret + "\n\n";
}

string Manager::handleRoomInput(string input)
{
	string ret = "";
	if (input == "fight"){
		fight();
	}
	else if (input == "flee"){
		flee();
	}
	else if (input == "search"){
		if (!dungeon->getCurrentRoom()->getSearched())
		{
			ret += dungeon->getCurrentRoom()->search();
			dungeon->getPlayer()->pickUp(dungeon->getCurrentRoom()->getItem());
			dungeon->getCurrentRoom()->takeItem();
		}
		else
		{
			ret += "This room has already been searched.\n\n";
		}
	}
	else if (input == "rest")
	{
		dungeon->getPlayer()->rest();
		ret += "You have rested. Your health is now " + to_string(dungeon->getPlayer()->getCurrentHealth()) + " of " +
			to_string(dungeon->getPlayer()->getHealth()) + ".\n\n";
	}
	else if (input == "inventory"){
		inventory();
	}
	else if (input == "map"){
		map();
	}
	else{
		ret += "Choose another option please.\n\n";
	}

	return ret;
}

string Manager::handleFightInput(string input)
{
	string ret = "";
	if (input.compare("attack") == 0)
	{
		attack();
	}
	else if (input.compare("flee") == 0)
	{
		flee();
	}
	else if (input.compare("drink") == 0)
	{
		inventory(); // needs to be specific to potions
	}
	else if (input.compare("use") == 0)
	{
		inventory();// needs to be changed to use an item or some shizz
	}
	else
	{
		ret += "Choose another option please.\n\n";
	}
	return ret;
}

string Manager::handleFleeInput(string input)
{
	string s = updateFleeOptions();
	size_t check = s.find(input);
	string ret = "";

	if (check == string::npos)
	{
		ret += "Choose another option please.\n\n";
	}
	else
	{
		Room* nextMove;
		if (input == "north")
		{
			nextMove = dungeon->getCurrentRoom()->getNorth();
		}
		else if (input == "east")
		{
			nextMove = dungeon->getCurrentRoom()->getEast();
		}
		else if (input == "west")
		{
			nextMove = dungeon->getCurrentRoom()->getWest();
		}
		else if (input == "south")
		{
			nextMove = dungeon->getCurrentRoom()->getSouth();
		}
		else if (input == "up")
		{
			nextMove = dungeon->getCurrentRoom()->getStairUp();
		}
		else if (input == "down")
		{
			nextMove = dungeon->getCurrentRoom()->getStairDown();
		}
		explore();
		dungeon->setCurrentRoom(dungeon->getCurrentRoom());
	}
	return ret + "\n\n";
}

string Manager::handleInventoryInput(string input)
{
	string s = dungeon->getPlayer()->printInventory();
	size_t check = s.find(input);
	string ret = "";

	if (check == string::npos)
	{
		ret += "Choose another option please.\n\n";
	}
	else
	{
		ret += dungeon->getPlayer()->use(input);
		explore();
	}

	return ret;
}

string Manager::handleAttackInput(string input)
{
	string s = updateAttackOptions();
	size_t check = s.find(input);
	string ret = "";

	if (check == string::npos)
	{
		ret += "Choose another option please.\n\n";
	}
	else
	{
		ret += "You have attacked: "+input+ "\n\n";
		ret += dungeon->resolveDamageToBaddies(input);
	}

	return ret;
}

string Manager::printText()
{
	string ret = "";
	switch (m_Menu)
	{
	case RoomMenu:
		ret += dungeon->getCurrentRoom()->printRoomText() + "What do you do?\n\n";
		ret += printOptions();
		break;
	case FightMenu:
		ret += "You're in a fight with:\n";
		ret += dungeon->getCurrentRoom()->printOpponentsFight() + "\n";
		ret += "Actions of opponents:\n";
		ret += dungeon->resolveDamageToPlayer() + "\n";
		if (dungeon->getPlayer()->isAlive())
		{
			ret += "What do you want to do?\n";
			printOptions();
		}
		break;
	case FleeMenu:
		ret += "\nWhich direction?\n";
		ret += "\n" + printOptions();
		break;
	case InventoryMenu:
		ret += "You have:\n";
		ret += printOptions();
		if (dungeon->getPlayer()->isItems())
		{
			ret += "What will you use?\n\n";
		}
		else
		{
			ret += "You have no items.\n\n";
			explore();
		}
		break;
	case MapMenu:
		ret += printOptions();
		break;
	case AttackMenu:
		ret += "Who should you attack?\n\n";
		ret += printOptions() +"\n\n";
		break;
	}
	return ret + "\n\n";
}

string Manager::printOptions()
{
	switch (m_Menu)
	{
	case RoomMenu:
		return "[fight|flee|search|rest|inventory|map]\n";
		break;
	case FightMenu:
		return "[attack|flee|drink|use]\n";
		break;
	case FleeMenu:
		return updateFleeOptions();
		break;
	case InventoryMenu:
		if (dungeon->getPlayer()->isItems())
			return dungeon->getPlayer()->printInventory();
		else return "";
		break;
	case MapMenu:
		return "[press return key]\n";
		break;
	case AttackMenu:
		return updateAttackOptions();
		break;
	}
	return "";
}

string Manager::updateAttackOptions()
{
	string s = "[";
	Room* croom = dungeon->getCurrentRoom();
	vector<Opponent*> v = *croom->getOpponents();

	for (std::vector<Opponent*>::size_type i = 0; i != v.size(); i++) {
		/* std::cout << someVector[i]; ... */
		s += v[i]->getName() + "|";
	}
	string ret = s.substr(0, s.length() - 1);
	return ret + "]\n";

}

string Manager::updateFleeOptions()
{
	string s = "[";
	Room* croom = dungeon->getCurrentRoom();
	if (croom->getNorth() != nullptr)
	{
		s += "north|";
	}
	if (croom->getEast() != nullptr)
	{
		s += "east|";
	}
	if (croom->getWest() != nullptr)
	{
		s += "west|";
	}
	if (croom->getSouth() != nullptr)
	{
		s += "south|";
	}
	if (croom->getStairUp() != nullptr)
	{
		s += "up|";
	}
	if (croom->getStairDown() != nullptr)
	{
		s += "down|";
	}
	string ret = s.substr(0, s.length() - 1);
	return ret + "]\n";
}
