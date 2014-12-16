#include "Floor.h"
#include <stdlib.h>


Floor::Floor()
{
	//for (int rows = 0; rows < SIZE; rows++)
	//{
	//	for (int column = 0; column < SIZE; column++)
	//	{
	//		//m_Rooms[rows][column] = new Room();
	//	}
	//}

	//for (int rows = 0; rows < (SIZE * 2); rows++)
	//{
	//	for (int column = 0; column < (SIZE * 2); column++)
	//	{
	//		m_Map[rows][column] = " ";
	//	}
	//}

}

Floor::Floor(int level, int rseed)
{
	//Update: Loader is 1x aangemaakt, loader wordt nu via singleton LoaderManager opgehaald.
	loader = LoaderManager::getInstance()->getLoader();

	for (int rows = 0; rows < SIZE; rows++)
	{
		int randomColumn = rand() % 10; // level begint bij 0, dus niet 10+1

		for (int column = 0; column < SIZE; column++)
		{
			if (level == 19 && randomColumn == column){
				m_Rooms[rows][column] = new Room(level, true, rseed);
			}
			else{
				m_Rooms[rows][column] = new Room(level, false, rseed);
			}
		}

		//Trap added to random room (10 total)
		//int randomColumn = rand() % 10; // level begint bij 0, dus niet 10+1
		m_Rooms[rows][randomColumn]->setTrap(level);
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
	//delete[] *m_Rooms;
	//better deleting
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
				delete m_Rooms[i][j];
				m_Rooms[i][j] = nullptr;
		}
	}

	m_StartingRoom = NULL;
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

			if (!above && roomAbove != nullptr && randomNr < 5)
			{
				above = true;
				m_StairUp = roomAbove;
				m_Rooms[rows][column]->setStairUp(roomAbove);
				roomAbove->setStairDown(m_Rooms[rows][column]);
			}

			randomNr = rand() % 101;

			if (!below && randomNr == 11 && !last)
			{
				below = true;
				m_StairDown = m_Rooms[rows][column];
			}

			randomNr = rand() % 101;

			if (!start && !last && roomAbove == nullptr && randomNr > 90 && randomNr < 95)
			{
				start = true;
				m_Rooms[rows][column]->setStart();
				m_StartingRoom = m_Rooms[rows][column];
			}

			randomNr = rand() % 101;

			if (!end && last && randomNr > 45)
			{
				end = true;
				m_Rooms[rows][column]->setEnd();
			}

			bool northok = (rows > 0);
			bool eastok = (column < SIZE - 1);
			bool westok = (column > 0);
			bool southok = (rows < SIZE - 1);


			int north = rows - 1;
			int east = column + 1;
			int west = column - 1;
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
	// if the floor has no stairs at all
	int randomRow = rand() % SIZE;
	int randomColumn = rand() % SIZE;

	if (!above && roomAbove != nullptr)
	{
		above = true;
		m_StairUp = roomAbove;
		m_Rooms[randomRow][randomColumn]->setStairUp(roomAbove);
		roomAbove->setStairDown(m_Rooms[randomRow][randomColumn]);
	}

	randomRow = rand() % SIZE;
	randomColumn = rand() % SIZE;

	if (!below && !last)
	{
		below = true;
		m_StairDown = m_Rooms[randomRow][randomColumn];
	}
}

void Floor::updateMap(Room* currentRoom)
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
			//check for CurrentRoom
			if (m_Rooms[rows][column] == currentRoom && m_Map[rows * 2][column * 2] != "S"){
				m_Map[rows * 2][column * 2] = "C";
			}
		}
	}
}
void Floor::updateMapCheat(Room* currentRoom)
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
			//check for CurrentRoom
			if (m_Rooms[rows][column] == currentRoom && m_Map[rows * 2][column * 2] != "S"){
				m_Map[rows * 2][column * 2] = "C";

				//check for StairDown && StairUp
				if (m_Rooms[rows][column]->getStairDown() != nullptr && m_Rooms[rows][column]->getStairUp() != nullptr){
					m_Map[rows * 2][column * 2] = "CSDSU";
				}
				//check for StairDown
				else if (m_Rooms[rows][column]->getStairDown() != nullptr){
					m_Map[rows * 2][column * 2] = "CSD";
				}
				//check for StairUp
				else if (m_Rooms[rows][column]->getStairUp() != nullptr){
					m_Map[rows * 2][column * 2] = "CSU";
				}
			}
			//check for StairDown && StairUp
			else if (m_Rooms[rows][column]->getStairDown() != nullptr && m_Rooms[rows][column]->getStairUp() != nullptr){
				m_Map[rows * 2][column * 2] = "SDSU";
			}
			//check for StairDown
			else if (m_Rooms[rows][column]->getStairDown() != nullptr){
				m_Map[rows * 2][column * 2] = "SD";
			}
			//check for StairUp
			else if (m_Rooms[rows][column]->getStairUp() != nullptr){
				m_Map[rows * 2][column * 2] = "SU";
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