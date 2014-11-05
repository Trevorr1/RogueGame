#include "Menu.h"

Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::handleInput(string input){
}

string Menu::printOptions()
{
	string s = "";
	for (vector<string>::iterator it = m_Options.begin(); it != m_Options.end(); ++it) {
		s += *it + "|";
	}
	string ret = s.substr(0, ret.size() - 1);
	return ret;
}