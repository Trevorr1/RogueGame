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

void Room::addOpponent(Opponent* opponent){
	//opponents.push_back(opponent);
}

vector<Opponent*>* Room::getOpponents(){
	return opponents;
}

void Room::addTrait(string trait)
{
	m_Traits.push_back(&trait);
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