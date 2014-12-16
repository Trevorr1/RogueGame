#include "MenuFight.h"
#include "MenuFactory.h"

using namespace std;

MenuFight::MenuFight()
{
	m_Options.push_back("attack");
	m_Options.push_back("run");
	m_Options.push_back("drink");
	m_Options.push_back("use");
	m_Options.push_back("back");

	printOptions();
}


MenuFight::~MenuFight()
{
}

void MenuFight::handleInput(MenuFactory* context, string input) 
{	
	if (input == "attack")
	{
		context->setMenu(context->getAttackMenu());
	}
	else if (input == "run")
	{
		context->setMenu(context->getFlightMenu(context->getDungeon()->getCurrentRoom()));
	}
	else if (input == "drink")
	{
		context->setMenu(context->getDrinkMenu());
	}
	else if (input == "use")
	{
		context->setMenu(context->getUseObjectMenu(context->getDungeon()->getPlayer()));
	}
	else if (input == "items")
	{
		context->setMenu(context->getInventoryMenu());
	}
	else if (input.compare("back") == 0)
	{
		context->setMenu(context->getRoomMenu(context->getDungeon()->getCurrentRoom()));
	}
	else{
		cout << "Choose another option please.\n\n" << endl;
	}
}


