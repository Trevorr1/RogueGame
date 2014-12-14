#include "Dungeon.h"


Dungeon::Dungeon()
{
	m_Player = new Player();
	for (int f = 0; f < DUNGEON_SIZE; f++)
	{
		if (m_Floors->empty())
		{
			Floor* tempFloor = new Floor();
			tempFloor->generateRooms(nullptr, false);
			m_Floors->push_back(new Floor());
		}
		else if (f == DUNGEON_SIZE - 1)
		{
			Floor* tempFloor = new Floor();
			tempFloor->generateRooms(m_Floors->at(f - 1)->getStairDown(), true);
			m_Floors->push_back(tempFloor);
		}
		else
		{
			Floor* tempFloor = new Floor();
			tempFloor->generateRooms(m_Floors->at(f - 1)->getStairDown(), false);
			m_Floors->push_back(tempFloor);
		}
	}
}

Dungeon::Dungeon(int rseed)
{
	m_Player = new Player();
	m_Floors = new vector<Floor*>;

	for (int f = 0; f < DUNGEON_SIZE; f++)
	{
		if (m_Floors->empty())
		{
			Floor* tempFloor = new Floor(f, rseed);
			tempFloor->generateRooms(nullptr, false);
			m_Floors->push_back(tempFloor);
		}
		else if (f == DUNGEON_SIZE - 1)
		{
			Floor* tempFloor = new Floor(f, rseed);
			tempFloor->generateRooms(m_Floors->at(f - 1)->getStairDown(), true);
			m_Floors->push_back(tempFloor);
		}
		else
		{
			Floor* tempFloor = new Floor(f, rseed);
			tempFloor->generateRooms(m_Floors->at(f - 1)->getStairDown(), false);
			m_Floors->push_back(tempFloor);
		}
	}
}

Dungeon::~Dungeon()
{
	delete m_Player;
	/*for (vector<Floor*>::iterator it = m_Floors->begin(); it != m_Floors->end(); it++)
		delete (*it);*/

	for (auto floor : *m_Floors){
		delete floor;
	}	

	delete m_Floors;
}

void Dungeon::setCurrentFloor(Floor* current)
{
	m_CurrentFloor = current;
}

void Dungeon::setCurrentRoom(Room* current)
{
	m_CurrentRoom = current;
}

Floor* Dungeon::getCurrentFloor()
{
	return m_CurrentFloor;
}

Room* Dungeon::getCurrentRoom()
{
	return m_CurrentRoom;
}


void Dungeon::resolveDamageToPlayer()
{
	string s = "";
	vector<Opponent*>* v = m_CurrentRoom->getOpponents();
	for (auto baddie : *v)
	{
		attackPlayer(baddie);
	}
	/*for (std::vector<Opponent*>::size_type i = 0; i != v->size(); i++) {
		s += v->at(i)->getName() + " " + to_string(i + 1) +" ";
		attackPlayer(v->at(i));
	}*/

	if (m_Player->getCurrentHealth() > 0)
	{
		cout << "\nYou still have " << to_string(m_Player->getCurrentHealth()) + " out of " + to_string(m_Player->getHealth()) << " hitpoints left.\n\n";
	}
	else
	{
		cout << "\nYour hitpoints have reached zero, you have died.\n\n";
		m_Player->kill();
	}
}

void Dungeon::resolveDamageToBaddies(string baddie)
{
	string ret = "";
	int toremove = 0;
	bool done = false;

	for (auto opponent : *m_CurrentRoom->getOpponents())
	{
		string name = opponent->getName();
		if (name.compare(baddie) == 0)
		{
			attackBaddie(opponent);
			break;
		}
	}

	m_CurrentRoom->clearCorpses();
}

void Dungeon::attackPlayer(Opponent* baddie)
{
	int dmg = baddie->getDmg() - m_Player->getDef();
	string s = "";
	if (dmg < 0)
		cout << baddie->getName() << " attacks but misses.\n\n";
	else
	{

		cout << baddie->getName() << "attacks and deals " << to_string(dmg) << " damage to you.\n\n";
		m_Player->damage(dmg);
	}
}

void Dungeon::attackBaddie(Opponent* baddie)
{
	int dmg = m_Player->getAtk() - baddie->getDef();
	string s = "";
	if (dmg < 0)
		cout << "Your attack missed.\n";
	else
	{
		cout << "Hit! You deal "<< to_string(dmg) << " damage to" << baddie->getName() <<".\n\n";
		baddie->damage(dmg);
	}
}

void Dungeon::save(vector <string*>* vectorSave){
	//pusback the members to the vectorSave

	//save the floors
	for (auto id : *m_Floors){
		id->save(vectorSave);
	}
}
