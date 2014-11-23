#pragma once
#include "Menu.h"
class MenuUseObject :
	public Menu
{
public:
	MenuUseObject();
	virtual ~MenuUseObject();

	void handleInput(MenuFactory* context, string input);
};

