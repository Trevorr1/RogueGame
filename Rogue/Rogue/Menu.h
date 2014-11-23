#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class MenuFactory;
class Menu
{
public:
	Menu();
	virtual ~Menu();

	virtual void handleInput(MenuFactory* context, string input) = 0;
	
	void printOptions();

protected:
	vector<string> m_Options;
};

