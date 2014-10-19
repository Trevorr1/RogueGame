#pragma once
#include <iostream>
using namespace std;

class Menu
{
public:
	Menu();
	virtual ~Menu();

	//void doAction(Context* context);
	virtual void handleInput(string input);
};

