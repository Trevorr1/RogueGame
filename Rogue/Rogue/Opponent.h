#pragma once

#include <string>

class Opponent
{
public:
	Opponent();
	virtual~Opponent();

	int get_level();

private:
	int m_Level, m_Atk, m_Health, m_Def, m_Gains;
	string m_Name;

};

