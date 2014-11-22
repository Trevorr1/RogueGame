#pragma once
#include "Menu.h"
class MenuInventory :
	public Menu
{
public:
	MenuInventory();
	virtual ~MenuInventory();

	void handleInput(MenuFactory* context, string input);
	void printOptions(){}
};

