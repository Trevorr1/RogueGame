#include "Opponent.h"
#include <iostream>
using namespace std;

Opponent::Opponent()
{
	//m_Level = 1;
}


Opponent::~Opponent()
{
}

Opponent::Opponent(const Opponent &obj)
{
	//cout << "Copy constructor allocating ptr." << endl;
	//ptr = new int;
	m_Level = obj.m_Level;
	m_Atk = obj.m_Atk;
	m_Health = obj.m_Health;
	m_Def = obj.m_Def;
	m_Gains = obj.m_Gains;
	m_Name = obj.m_Name;
	//*ptr = *obj.ptr; // copy the value
}

Opponent::Opponent(const Opponent *obj)
{
	//cout << "Copy constructor allocating ptr." << endl;
	//ptr = new int;
	m_Level = obj->m_Level;
	m_Atk = obj->m_Atk;
	m_Health = obj->m_Health;
	m_Def = obj->m_Def;
	m_Gains = obj->m_Gains;
	m_Name = obj->m_Name;
	//*ptr = *obj.ptr; // copy the value
}


void Opponent::setOpponent(vector <string>* vectorLoaded)
{
	m_Level = stoi(vectorLoaded->at(0));
	m_Atk = stoi(vectorLoaded->at(1));
	m_Health = stoi(vectorLoaded->at(2));
	m_Def = stoi(vectorLoaded->at(3));
	m_Gains = stoi(vectorLoaded->at(4));
	m_Name = vectorLoaded->at(5);
}

string Opponent::printStatus()
{
	string s = "";
	float value = ((1.0f * m_CurrentHealth) / m_Health) * 100;

	if (value <= 20)
		s += "On it's last leg.\n";
	else if (value > 20 && value < 100)
		s += "Has some damage.\n";
	else if (value == 100)
		s += "Unharmed.\n";

	return s;
}

void Opponent::damage(int dmg)
{
	m_CurrentHealth -= dmg;
	if (m_CurrentHealth < 0) m_Alive = false;
}