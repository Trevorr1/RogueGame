#pragma once
#include "Menu.h"
class MenuFlight :
	public Menu
{
public:
	MenuFlight();
	virtual ~MenuFlight();


	void handleInput(MenuFactory* context, string input);
	void printOptions();
};

