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

void MenuFactory::setMenu(Menu* next)
{
	if (m_Current != nullptr)
	{
		delete m_Current;
	}
	m_Current = next;
}