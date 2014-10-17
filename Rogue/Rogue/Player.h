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
	void pickUp(Item* item);
	void printStats();

private:
	string m_Name;
	int m_Level;
	int m_Hitpoints;
	int m_Exp;
	int m_Atk;
	int m_Def;
	int m_Awareness;
	vector<Item*> *m_Inventory;

};