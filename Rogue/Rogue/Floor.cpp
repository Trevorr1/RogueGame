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

	for (int rows = 0; rows < (SIZE * 2); rows++)
	{
		for (int column = 0; column < (SIZE * 2); column++)
		{
			m_Map[rows][column] = " ";
		}
	}

}

Floor::Floor(int rseed)
{
	//Dit wordt 10x aangeroepen adhv size in Dungeon. Liever 1x aanroepen of 1x meegeven in Floor(Loader loader, int rseed)
	loader = new Loader();
	//loader->loadRoomTraits(); //wordt al in Loader aangeroepen

	for (int rows = 0; rows < SIZE; rows++)
	{
		for (int column = 0; column < SIZE; column++)
		{
			//m_Rooms[rows][column] = new Room(rseed);
			m_Rooms[rows][column] = generateRoom(rseed);
		}
	}

	for (int rows = 0; rows < (SIZE * 2); rows++)
	{
		for (int column = 0; column < (SIZE * 2); column++)
		{
			m_Map[rows][column] = " ";
		}
	}
}


Floor::~Floor()
{
	delete[] m_Rooms;
}

Room* Floor::generateRoom(int rseed){
	//srand(rseed); //rseed is handig wanneer je 1 random object wil. Maar deze methode wordt 100x per floor aangeroepen.
	Room* room = new Room();

	string size = loader->getRoom_sizes()->at(rand() % loader->getRoom_sizes()->size());
	string state = loader->getRoom_states()->at(rand() % loader->getRoom_states()->size());
	string illumation = loader->getRoom_lightings()->at(rand() % loader->getRoom_lightings()->size());
	string shape = loader->getRoom_shapes()->at(rand() % loader->getRoom_shapes()->size());
	string content = loader->getRoom_contents()->at(rand() % loader->getRoom_contents()->size());
	string special = loader->getRoom_specialTraits()->at(rand() % loader->getRoom_specialTraits()->size());

	room->addTrait(size);
	room->addTrait(state);
	room->addTrait(illumation);
	room->addTrait(shape);
	room->addTrait(content);
	room->addTrait(special);

	return room;
}

void Floor::generateRooms(Room* roomAbove, bool last)
{
	bool above = false;
	bool below = false;
	bool start = false;
	bool end = false;

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

			if (!below && randomNr > 45 && !last)
			{
				below = true;
				m_StairDown = m_Rooms[rows][column];
			}

			randomNr = rand() % 101;

			if (!start && !last && roomAbove == nullptr && randomNr > 90 && randomNr < 95)
			{
				start = true;
				m_Rooms[rows][column]->setStart();
			}

			randomNr = rand() % 101;

			if (!end && last && randomNr > 45)
			{
				end = true;
				m_Rooms[rows][column]->setEnd();
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

			if (northok && randomNr > 60)
			{
				if (m_Rooms[rows][column]->getNorth() == nullptr)
				{
					m_Rooms[north][column]->setSouth(m_Rooms[rows][column]);
					m_Rooms[rows][column]->setNorth(m_Rooms[north][column]);
				}
			}
			// setting the east room...if odds allow
			randomNr = rand() % 101;

			if (eastok && randomNr > 60)
			{
				if (m_Rooms[rows][column]->getEast() == nullptr)
				{
					m_Rooms[rows][east]->setWest(m_Rooms[rows][column]);
					m_Rooms[rows][column]->setEast(m_Rooms[rows][east]);
				}
			}
			// setting the west room...if odds allow
			randomNr = rand() % 101;

			if (westok && randomNr > 60)
			{
				if (m_Rooms[rows][column]->getWest() == nullptr)
				{
					m_Rooms[rows][west]->setEast(m_Rooms[rows][column]);
					m_Rooms[rows][column]->setWest(m_Rooms[rows][west]);
				}
			}
			// setting the south room...if odds allow
			randomNr = rand() % 101;

			if (southok && randomNr > 60)
			{
				if (m_Rooms[rows][column]->getSouth() == nullptr)
				{
					m_Rooms[south][column]->setNorth(m_Rooms[rows][column]);
					m_Rooms[rows][column]->setSouth(m_Rooms[south][column]);
				}
			}

			if (m_Rooms[rows][column]->getNorth() == nullptr && m_Rooms[rows][column]->getEast() == nullptr &&
				m_Rooms[rows][column]->getWest() == nullptr&& m_Rooms[rows][column]->getSouth() == nullptr)
			{
				randomNr = rand() % 4;
				switch (randomNr)
				{
				case 0:
					if (northok)
					{
						m_Rooms[north][column]->setSouth(m_Rooms[rows][column]);
						m_Rooms[rows][column]->setNorth(m_Rooms[north][column]);
					}
					else if (eastok)
					{
						m_Rooms[rows][east]->setWest(m_Rooms[rows][column]);
						m_Rooms[rows][column]->setEast(m_Rooms[rows][east]);
					}
					else if (westok)
					{
						m_Rooms[rows][west]->setEast(m_Rooms[rows][column]);
						m_Rooms[rows][column]->setWest(m_Rooms[rows][west]);
					}
					else if (southok)
					{
						m_Rooms[south][column]->setNorth(m_Rooms[rows][column]);
						m_Rooms[rows][column]->setSouth(m_Rooms[south][column]);
					}
					break;
				case 1:
					if (westok)
					{
						m_Rooms[rows][west]->setEast(m_Rooms[rows][column]);
						m_Rooms[rows][column]->setWest(m_Rooms[rows][west]);
					}
					else if (eastok)
					{
						m_Rooms[rows][east]->setWest(m_Rooms[rows][column]);
						m_Rooms[rows][column]->setEast(m_Rooms[rows][east]);
					}
					else if (northok)
					{
						m_Rooms[north][column]->setSouth(m_Rooms[rows][column]);
						m_Rooms[rows][column]->setNorth(m_Rooms[north][column]);
					}
					else if (southok)
					{
						m_Rooms[south][column]->setNorth(m_Rooms[rows][column]);
						m_Rooms[rows][column]->setSouth(m_Rooms[south][column]);
					}
					break;
				case 2:
					if (eastok)
					{
						m_Rooms[rows][east]->setWest(m_Rooms[rows][column]);
						m_Rooms[rows][column]->setEast(m_Rooms[rows][east]);
					}
					else if (westok)
					{
						m_Rooms[rows][west]->setEast(m_Rooms[rows][column]);
						m_Rooms[rows][column]->setWest(m_Rooms[rows][west]);
					}
					else if (northok)
					{
						m_Rooms[north][column]->setSouth(m_Rooms[rows][column]);
						m_Rooms[rows][column]->setNorth(m_Rooms[north][column]);
					}
					else if (southok)
					{
						m_Rooms[south][column]->setNorth(m_Rooms[rows][column]);
						m_Rooms[rows][column]->setSouth(m_Rooms[south][column]);
					}
					break;
				case 3:
					if (southok)
					{
						m_Rooms[south][column]->setNorth(m_Rooms[rows][column]);
						m_Rooms[rows][column]->setSouth(m_Rooms[south][column]);
					}
					else if (eastok)
					{
						m_Rooms[rows][east]->setWest(m_Rooms[rows][column]);
						m_Rooms[rows][column]->setEast(m_Rooms[rows][east]);
					}
					else if (westok)
					{
						m_Rooms[rows][west]->setEast(m_Rooms[rows][column]);
						m_Rooms[rows][column]->setWest(m_Rooms[rows][west]);
					}
					else if (northok)
					{
						m_Rooms[north][column]->setSouth(m_Rooms[rows][column]);
						m_Rooms[rows][column]->setNorth(m_Rooms[north][column]);
					}
					break;
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
			m_Map[rows * 2][column * 2] = m_Rooms[rows][column]->printRoom();
			if (m_Rooms[rows][column]->getVisited())
			{
				if (m_Rooms[rows][column]->getNorth() != nullptr)
				{
					m_Map[(rows * 2) - 1][column * 2] = "|";
				}
				if (m_Rooms[rows][column]->getWest() != nullptr)
				{
					m_Map[rows * 2][(column * 2) + 1] = "-";
				}
				if (m_Rooms[rows][column]->getEast() != nullptr)
				{
					m_Map[rows * 2][(column * 2) - 1] = "-";
				}
				if (m_Rooms[rows][column]->getSouth() != nullptr)
				{
					m_Map[(rows * 2) + 1][column * 2] = "|";
				}

			}
		}
	}
	int foo = 0;
}

void Floor::printFloor()
{
	for (int rows = 0; rows < (SIZE * 2); rows++)
	{
		for (int column = 0; column < (SIZE * 2); column++)
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

void Floor::save(vector <string *>* vectorSave){
	//pusback the members to the vectorSave
}