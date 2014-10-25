#include "Dungeon.h"


Dungeon::Dungeon()
{
	for (int f = 0; f < DUNGEON_SIZE; f++)
	{
		if (m_Floors.empty())
		{
			Floor* tempFloor = new Floor();
			tempFloor->generateRooms(nullptr, false);
			m_Floors.push_back(new Floor());
		}
		else if (f == DUNGEON_SIZE - 1)
		{
			Floor* tempFloor = new Floor();
			tempFloor->generateRooms(m_Floors.at(f - 1)->getStairDown(), true);
			m_Floors.push_back(tempFloor);
		}
		else
		{
			Floor* tempFloor = new Floor();
			tempFloor->generateRooms(m_Floors.at(f - 1)->getStairDown(), false);
			m_Floors.push_back(tempFloor);
		}
	}
}


Dungeon::~Dungeon()
{
	for (vector<Floor*>::iterator it = m_Floors.begin(); it != m_Floors.end(); it++)
		delete (*it);
}