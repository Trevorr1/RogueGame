#pragma once
#include <iostream>
#include <vector>
//#include "MenuFactory.h"
using namespace std;
class MenuFactory;
class Menu
{
public:
	Menu();
	virtual ~Menu();

	virtual void handleInput(MenuFactory* context, string input) = 0;
	
	virtual void printOptions() = 0;

protected:
	vector<string> m_Options;
};

