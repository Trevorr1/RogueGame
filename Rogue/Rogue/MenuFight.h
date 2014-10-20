#pragma once
#include "Menu.h"

class MenuFight :
	public Menu
{
public:
	MenuFight();
	virtual ~MenuFight();

	void handleInput(string input);
	void attack();
	void flee();
	void drink();
	void useObject();
};

