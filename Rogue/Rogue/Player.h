#pragma once
#include <string>

using namespace std;
class Player
{
public:
	Player();
	virtual ~Player();

private:
	string m_Name;
	int m_Level;
	int m_Hitpoints;
	int m_Exp;
	int m_Atk;
	int m_Def;

};