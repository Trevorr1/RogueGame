#pragma once
#include "Menu.h"
#include "Room.h"
class MenuAttack :
	public Menu
{
public:
	MenuAttack();
	MenuAttack(Room* room);
	virtual ~MenuAttack();
	
	void handleInput(MenuFactory* context, string input);
	void printOptions();
	void updateOptions(Room* room);
};

