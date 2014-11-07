#include "Dungeon.h"


Dungeon::Dungeon()
{
	m_Player = new Player();
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

Dungeon::Dungeon(int rseed)
{
	for (int f = 0; f < DUNGEON_SIZE; f++)
	{
		if (m_Floors.empty())
		{
			Floor* tempFloor = new Floor(rseed);
			tempFloor->generateRooms(nullptr, false);
			m_Floors.push_back(new Floor());
		}
		else if (f == DUNGEON_SIZE - 1)
		{
			Floor* tempFloor = new Floor(rseed);
			tempFloor->generateRooms(m_Floors.at(f - 1)->getStairDown(), true);
			m_Floors.push_back(tempFloor);
		}
		else
		{
			Floor* tempFloor = new Floor(rseed);
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


string Dungeon::resolveDamageToPlayer()
{
	string s = "";
	vector<Opponent*>* v = m_CurrentRoom->getOpponents();

	for (std::vector<Opponent*>::size_type i = 0; i != v->size(); i++) {
		s += v->at(i)->getName() + " " + to_string(i + 1) +" ";
		s+= attackPlayer(v->at(i));
	}

	if (m_Player->getCurrentHealth() > 0)
	{
		s += "\nYou still have " + to_string(m_Player->getCurrentHealth()) + " out of " + to_string(m_Player->getHealth()) + " hitpoints over.\n\n";
	}
	else
	{
		s += "\nYour hitpoints have reached zero, you have died.\n";
		m_Player->kill();
	}
	return s;
}

string Dungeon::resolveDamageToBaddies(string baddie)
{
	string ret = "";
	int toremove = 0;
	bool done = false;

	for (std::vector<Item*>::size_type i = 0; i != m_CurrentRoom->getOpponents()->size(); i++)
	{
		if (m_CurrentRoom->getOpponents()->at(i)->getName().compare(baddie) == 0)
		{
			ret += attackBaddie(m_CurrentRoom->getOpponents()->at(i));
		}
	}

	for (std::vector<Item*>::size_type i = 0; i != m_CurrentRoom->getOpponents()->size(); i++)
	{
		if (!m_CurrentRoom->getOpponents()->at(i)->isAlive())
		{
			toremove = i;
			done = true;
			break;
		}
	}
	if (done)
	{
		ret += "You have slain " + m_CurrentRoom->getOpponents()->at(toremove)->getName() + ".\n";
		m_CurrentRoom->getOpponents()->erase(m_CurrentRoom->getOpponents()->begin + toremove);
	}
	return ret + "\n\n";
}

string Dungeon::attackPlayer(Opponent* baddie)
{
	int dmg = baddie->getDmg() - m_Player->getDef();
	string s = "";
	if (dmg < 0)
		s += "attacks but misses.\n";
	else
	{

		s += "attacks and deals " + to_string(dmg) +" damage.\n";
		m_Player->damage(dmg);
	}
	return s;
}

string Dungeon::attackBaddie(Opponent* baddie)
{
	int dmg = m_Player->getAtk() - baddie->getDef();
	string s = "";
	if (dmg < 0)
		s += "Your attack but missed.\n";
	else
	{
		s += "Hit! You deal " + to_string(dmg) + " damage to" + baddie->getName() +".\n";
		baddie->damage(dmg);
	}
	return s;
}

void Dungeon::save(vector <string*>* vectorSave){
	//pusback the members to the vectorSave

	//save the floors
	for (auto id : m_Floors){
		id->save(vectorSave);
	}
}
