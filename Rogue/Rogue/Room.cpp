#include "Room.h"

Room::Room()
{
	opponents = new vector<Opponent*>;
}

Room::Room(int rseed)
{

}


Room::~Room()
{
}

char* Room::printRoom()
{
	if (m_startPoint)
		return "S";
	if (m_Visited)
	{
		if (m_EndPoint)
			return "E";
		if (m_StairUp != nullptr)
			return "H";
		if (m_StairDown != nullptr)
			return "L";
		return "N";
	}
	else return "_";
}

string Room::printRoomText()
{
	string desc = "Description: You're in a ";
	desc += m_Traits.at(0) + " " + m_Traits.at(3);
	desc += "Room that is ";
	desc += m_Traits.at(2);
	desc += ". It's " + m_Traits.at(1) + " and" + m_Traits.at(5) + ".\n";
	desc += m_Traits.at(6) + "\n\n";

	// print room exits
	string exits = "Exits: " + printExits() + "\n\n";
	
	// print enemies
	string enemies = "Present: " + printOpponents() + "\n\n";

}

string Room::printOpponents()
{
	string s = "";

	for (std::vector<Opponent*>::size_type i = 0; i != m_Opponents->size(); i++) {
		if (i < m_Opponents->size())
			s += m_Opponents->at(i)->getName() + ", ";
		else
			s += " and " + m_Opponents->at(i)->getName() + ".";
	}
	return s;
}

string Room::printOpponentsFight()
{
	string s = "";

	for (std::vector<Opponent*>::size_type i = 0; i != m_Opponents->size(); i++) {
		s += m_Opponents->at(i)->getName() + " - " + to_string(i + 1) +": ";
		s += m_Opponents->at(i)->printStatus();
	}
	return s;
}

string Room::printExits()
{
	string s = "There is";
	if (m_North != nullptr)
		s += " a door to the north,";
	if (m_East != nullptr)
		s += " a door to the east,";
	if (m_West != nullptr)
		s += " a door to the west,";
	if (m_South != nullptr)
		s += " a door to the south,";
	if (m_StairDown != nullptr)
		s += " a stairway leading deeper down into the dungeon,";
	if (m_StairUp != nullptr)
		s += " a stairway leading to an upper floor.";

	string ret = s.substr(0, s.length() - 1);
	ret += ".";
	return ret;
}


void Room::addOpponent(Opponent* opponent){
	//opponents.push_back(opponent);
}

vector<Opponent*>* Room::getOpponents(){
	return m_Opponents;
}

void Room::addTrait(string trait)
{
	m_Traits.push_back(trait);
}


void Room::setVisited()
{
	m_Visited = true;
}

void Room::setStart()
{
	m_startPoint = true;
}

void Room::setEnd()
{
	m_EndPoint = true;
}

void Room::setNorth(Room* north)
{
	m_North = north;
}

void Room::setEast(Room* east)
{
	m_East = east;
}

void Room::setWest(Room* west)
{
	m_West = west;
}

void Room::setSouth(Room* south)
{
	m_South = south;
}

void Room::setStairUp(Room* up)
{
	m_StairUp = up;
}

void Room::setStairDown(Room* down)
{
	m_StairDown = down;
}

Room* Room::getNorth()
{
	return m_North;
}

Room* Room::getEast()
{
	return m_East;
}

Room* Room::getWest()
{
	return m_West;
}

Room* Room::getSouth()
{
	return m_South;
}

bool Room::getVisited()
{
	return m_Visited;
}

void Room::setRoom(vector <string>* vectorLoaded){
	m_Size = vectorLoaded->at(0);
	m_State = vectorLoaded->at(1);
	m_Illumation = vectorLoaded->at(2);
	m_Shape = vectorLoaded->at(3);
	m_Content = vectorLoaded->at(4);
	m_Special = vectorLoaded->at(5);
}