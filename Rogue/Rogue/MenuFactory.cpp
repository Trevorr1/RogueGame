#include "MenuFactory.h"


MenuFactory::MenuFactory()
{
}


MenuFactory::~MenuFactory()
{
}

void MenuFactory::handleInput(string input)
{
	m_Current->handleInput(this, input);
}