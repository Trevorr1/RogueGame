#include "Floor.h"
#include <stdlib.h>


Floor::Floor()
{
	for (int rows = 0; rows < SIZE; rows++)
	{
		for (int column = 0; column < SIZE; column++)
		{
			m_Rooms[rows][column] = new Room();
		}
	}
}


Floor::~Floor()
{
	delete[] m_Rooms;
}

void Floor::generateRooms(Room* roomAbove, bool last)
{
	for (int rows = 0; rows < SIZE; rows++)
	{
		for (int column = 0; column < SIZE; column++)
		{
			m_Rooms[rows][column] = new Room();
		}
	}

	bool above = false;
	bool below = false;

	for (int rows = 0; rows < SIZE; rows++)
	{
		for (int column = 0; column < SIZE; column++)
		{

			int randomNr = rand() % 101;

			if (!above && roomAbove != nullptr && randomNr > 45)
			{
				above = true;
				m_StairUp = roomAbove;
				m_Rooms[rows][column]->setStairUp(roomAbove);
				roomAbove->setStairDown(m_Rooms[rows][column]);
			}

			randomNr = rand() % 101;

			if (!below && randomNr > 45 && last)
			{
				below = true;
				m_StairDown = m_Rooms[rows][column];
			}

			bool northok = (rows != 0);
			bool eastok = (column != 0);
			bool westok = (column != SIZE - 1);
			bool southok = (rows != SIZE - 1);


			int north = rows - 1;
			int east = column - 1;
			int west = column + 1;
			int south = rows + 1;

			// setting the north room...if odds allow
			randomNr = rand() % 101;

			if (northok && randomNr > 30)
			{
				if (m_Rooms[rows][column]->getNorth() == nullptr)
				{
					m_Rooms[north][column]->setSouth(m_Rooms[rows][column]);
					m_Rooms[rows][column]->setNorth(m_Rooms[north][column]);
				}
			}
			// setting the east room...if odds allow
			randomNr = rand() % 101;

			if (eastok && randomNr > 30)
			{
				if (m_Rooms[rows][column]->getEast() == nullptr)
				{
					m_Rooms[rows][east]->setWest(m_Rooms[rows][column]);
					m_Rooms[rows][column]->setEast(m_Rooms[rows][east]);
				}
			}
			// setting the west room...if odds allow
			randomNr = rand() % 101;

			if (westok && randomNr > 30)
			{
				if (m_Rooms[rows][column]->getWest() == nullptr)
				{
					m_Rooms[rows][west]->setEast(m_Rooms[rows][column]);
					m_Rooms[rows][column]->setWest(m_Rooms[rows][west]);
				}
			}
			// setting the south room...if odds allow
			randomNr = rand() % 101;

			if (southok && randomNr > 30)
			{
				if (m_Rooms[rows][column]->getSouth() == nullptr)
				{
					m_Rooms[south][column]->setNorth(m_Rooms[rows][column]);
					m_Rooms[rows][column]->setSouth(m_Rooms[south][column]);
				}
			}
		}
	}
}

void Floor::updateMap()
{
	for (int rows = 0; rows < SIZE; rows++)
	{
		for (int column = 0; column < SIZE; column++)
		{
			m_Map[rows * 2][column * 2] = m_Rooms[rows][column]->printRoom;
			if (m_Rooms[rows][column]->getVisited())
			{
				if (m_Rooms[rows][column]->getNorth() != nullptr)
				{
					m_Map[rows - 1][column] = "|";
				}
				if (m_Rooms[rows][column]->getWest() != nullptr)
				{
					m_Map[rows][column + 1] = "-";
				}
				if (m_Rooms[rows][column]->getEast() != nullptr)
				{
					m_Map[rows][column - 1] = "-";
				}
				if (m_Rooms[rows][column]->getSouth() != nullptr)
				{
					m_Map[rows + 1][column] = "|";
				}
			}
		}
	}
}

void Floor::printFloor()
{
	for (int rows = 0; rows < (SIZE*2); rows++)
	{
		for (int column = 0; column < (SIZE*2); column++)
		{
			cout << m_Map[rows][column];
		}
		cout << "\n";
	}
}


Room* Floor::getStairUp()
{
	return m_StairUp;
}

Room* Floor::getStairDown()
{
	return m_StairDown;
}