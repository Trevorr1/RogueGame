#pragma once
#include "Menu.h"
class Room;
class MenuRoom :
	public Menu
{
public:
	MenuRoom();
	MenuRoom(Room* room);
	virtual ~MenuRoom();

	void handleInput(MenuFactory* context, string input);
	void search(MenuFactory* context);
	void map(MenuFactory* context);


	//Optional:
	//void save();
	//void load();

};

