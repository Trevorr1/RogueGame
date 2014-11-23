#pragma once
#include "Menu.h"

class MenuFight :
	public Menu
{
public:
	MenuFight();
	virtual ~MenuFight();

	void handleInput(MenuFactory* context, string input);
	void attack();
	void flee();
	void drink(MenuFactory* context);
	void useObject();
};

