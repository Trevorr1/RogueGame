#pragma once
#include "Menu.h"
#include "Room.h"
class MenuFlight :
	public Menu
{
public:
	MenuFlight();
	MenuFlight(Room* room);
	virtual ~MenuFlight();


	void handleInput(MenuFactory* context, string input);
	void updateOptions(Room* room);
};

