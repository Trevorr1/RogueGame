#include "Item.h"


Item::Item()
{
	m_Used = false;
}


Item::~Item()
{
}

void Item::setName(string name)
{
	m_Name = name;
}

void Item::setHealth(int health)
{
	m_Health = health;
}