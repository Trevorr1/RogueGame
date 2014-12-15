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
	m_Inventory = new vector<Item*>();
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
	return "";
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
	int toHeal = 0;
	if (m_CurrentHealth != m_Health){
		toHeal = (int)((1.0 * m_Health) / 8);
		if (m_CurrentHealth + toHeal > m_Health) 
		{
			cout << "You at full health!" << endl;
			m_CurrentHealth = m_Health;
		}
		else
		{
			m_CurrentHealth += toHeal;
			cout << "You healed " << toHeal << 
				" hitpoints, your current health is: " << m_CurrentHealth << endl << endl;
		}
	}
	else cout << "Your health is already full!" << endl << endl;
}

void Player::heal(int health)
{
	m_CurrentHealth += health;
	if (m_CurrentHealth > m_Health) m_CurrentHealth = m_Health;
}

void Player::use(string item)
{
	bool done = false;

	for (auto i : *m_Inventory)
	{
		string name = i->getName();
		if (name.compare(item) == 0)
		{
			i->use();
			heal(i->getHealth());
			cout << "You used " << item << " and healed " << to_string(i->getHealth()) << ".\n\n";
			break;
		}
	}
	discardUsedItems();
}

void Player::discardUsedItems()
{
	for (auto it = m_Inventory->cbegin(); it != m_Inventory->cend();)
	{
		if (!(*it)->isUsed())
		{
			it = m_Inventory->erase(it);
		}
		else
		{
			++it;
		}
	}
}
