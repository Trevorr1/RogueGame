#include "MenuInventory.h"
#include "MenuFactory.h"

MenuInventory::MenuInventory()
{
	updateOptions();
	printOptions();
}


MenuInventory::~MenuInventory()
{
}

void MenuInventory::handleInput(MenuFactory* context, string input)
{
	if (input.compare("use") == 0)
	{
		context->setMenu(context->getUseObjectMenu(context->getDungeon()->getPlayer()));
	}
	else if (input.compare("back") == 0)
	{
		context->setMenu(context->getRoomMenu(context->getDungeon()->getCurrentRoom()));
	}
}

void MenuInventory::updateOptions()
{
	m_Options.push_back("use");
	m_Options.push_back("back");
}
