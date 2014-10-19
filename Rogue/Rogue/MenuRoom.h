#pragma once
#include "Menu.h"

class MenuRoom :
	public Menu
{
public:
	MenuRoom();
	virtual ~MenuRoom();

	void handleInput(string input);
	void fight();
	void flee();
	void search();
	void rest();
	void inventory();
	void map();
	void characterInfo();
	//Optional:
	//void save();
	//void load();

};

