#pragma once
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Player
{
public:
	Player();
	virtual ~Player();

	void lvlUp(int exp);
	void rest();
	void heal(int health);

	string use(string item);

	void pickUp(Item* item);
	string printStats();
	string printInventory();

	bool isAlive() { return m_Alive; }
	bool isItems() { return (m_Inventory->size() > 0); }
	void kill() { m_Alive = false; }

	void damage(int dmg) { m_CurrentHealth -= dmg; }

	int getAtk() { return m_Atk; }
	int getDef() { return m_Def; }
	int getCurrentHealth() { return m_CurrentHealth; }
	int getHealth() { return m_Health; }

private:
	string m_Name;
	int m_Level;
	int m_Health;
	int m_CurrentHealth;
	int m_Exp;
	int m_Atk;
	int m_Def;
	int m_Awareness;

	bool m_Alive;
	vector<Item*> *m_Inventory;

};