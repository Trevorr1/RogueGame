#include "MenuFactory.h"

// Allocating and initializing GlobalClass's
// static data member.  The pointer is being
// allocated - not the object inself.
MenuFactory * MenuFactory::_instance = 0;

MenuFactory* MenuFactory::getInstance()
{
	if (_instance == NULL){
		_instance = new MenuFactory;
	}
	return _instance;
}

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