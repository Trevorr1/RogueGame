#include "Opponent.h"
#include <iostream>
using namespace std;

Opponent::Opponent()
{
	m_Level = 1;
}


Opponent::~Opponent()
{
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

int Opponent::get_level(){
	return m_Level;
}