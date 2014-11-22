#pragma once
#include "Menu.h"
#include "Room.h"
class MenuRoom :
	public Menu
{
public:
	MenuRoom();
	MenuRoom(Room* room);
	virtual ~MenuRoom();

	void handleInput(MenuFactory* context, string input);
	void fight();
	void flee();
	void search(MenuFactory* context);
	void rest();
	void inventory();
	void map(MenuFactory* context);
	void characterInfo();

	void printOptions();


	//Optional:
	//void save();
	//void load();

};

