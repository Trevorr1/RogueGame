#pragma once
#include "Menu.h"
class MenuDrink :
	public Menu
{
public:
	MenuDrink();
	virtual ~MenuDrink();

	void handleInput(MenuFactory* context, string input);
};

