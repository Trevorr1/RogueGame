#include "Player.h"
#include <iostream>


Player::Player()
{
	m_Name = "";
	m_Level = 1;
	m_Hitpoints = 50;
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

void Player::printStats()
{
	// some fancy display for the stats
}

void Player::setState(Menu* state){
	this->state = state;
}

Menu* Player::getState(){
	return state;
}