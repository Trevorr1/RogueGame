#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Menu
{
public:
	Menu();
	virtual ~Menu();

	//void doAction(Context* context);
	virtual void handleInput(string input);
	//virtual void addOptions(string option);
	//virtual void clearOptions();
	
	string printOptions();


protected:
	string m_Text;
	vector<string> m_Options;
};

