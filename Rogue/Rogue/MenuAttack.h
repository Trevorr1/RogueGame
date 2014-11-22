#pragma once
#include "Menu.h"
class MenuAttack :
	public Menu
{
public:
	MenuAttack();
	virtual ~MenuAttack();
	
	void handleInput(MenuFactory* context, string input);
	void printOptions(){}
};

