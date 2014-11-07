#include "Player.h"
#include <iostream>


Player::Player()
{
	m_Name = "";
	m_Level = 1;
	m_Health = 50;
	m_CurrentHealth = m_Health;
	m_Exp = 0;
	m_Atk = 10;
	m_Def = 5;
	m_Awareness = 1;
}


Player::~Player()
{
}

void Player::lvlUp(int exp)
{
	int expCap = m_Level * 100;
	m_Exp += exp;
	if (m_Exp > expCap)
	{
		m_Exp %= expCap;
		m_Level++;
		cout << "Your level has increase!" << endl;
	}
}

void Player::pickUp(Item* item)
{
	m_Inventory->push_back(item);
}

string Player::printStats()
{
	// some fancy display for the stats
}

string Player::printInventory()
{
	string s = "";
	if (m_Inventory->size() > 0)
	{
		for (std::vector<Item*>::iterator it = m_Inventory->begin(); it != m_Inventory->end(); it++)
		{
			s += (*it)->getName() + "\n";
		}
	}
	return s + "\n";
}

void Player::rest()
{
	m_CurrentHealth += (int)((1.0 * m_Health) / 8);
	if (m_CurrentHealth > m_Health) m_CurrentHealth = m_Health;
}

void Player::heal(int health)
{
	m_CurrentHealth += health;
	if (m_CurrentHealth > m_Health) m_CurrentHealth = m_Health;
}

string Player::use(string item)
{
	string ret = "";
	int toremove = 0;
	bool done = false;
	for (std::vector<Item*>::size_type i = 0; i != m_Inventory->size(); i++) {
		if (m_Inventory->at(i)->getName().compare(item) == 0) 
		{
			toremove = i;
			done = true;
			heal(m_Inventory->at(i)->getHealth());
			ret += "You used " + item + " and healed " + to_string(m_Inventory->at(i)->getHealth()) + ".\n\n";
			break;
		}
	}
	if (done) m_Inventory->erase(m_Inventory->begin + toremove);
}
