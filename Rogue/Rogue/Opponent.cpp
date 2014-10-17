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

int Opponent::get_level(){
	return m_Level;
}