#pragma once
#include "Menu.h"
class Player;
class MenuUseObject :
	public Menu
{
public:
	MenuUseObject(Player* player);
	virtual ~MenuUseObject();

	void handleInput(MenuFactory* context, string input);
	void updateOptions(Player* player);
	void printOptions(); 
};

