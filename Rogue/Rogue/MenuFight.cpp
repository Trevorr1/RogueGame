#include "MenuFight.h"
#include "MenuFactory.h"

using namespace std;

MenuFight::MenuFight()
{
	m_Options.push_back("attack");
	m_Options.push_back("run");
	m_Options.push_back("drink");
	m_Options.push_back("use");

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
		context->setMenu(context->getUseObjectMenu());
	}
	else if (input == "items")
	{
		context->setMenu(context->getInventoryMenu());
	}
	else{
		cout << "Choose another option please.\n\n" << endl;
	}
}


