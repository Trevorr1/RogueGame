#include "MenuAttack.h"


MenuAttack::MenuAttack()
{
}

MenuAttack::MenuAttack(Room* room)
{
	updateOptions(room);
	printOptions();
}

MenuAttack::~MenuAttack()
{
}

void MenuAttack::handleInput(MenuFactory* context, string input)
{
}

void MenuAttack::updateOptions(Room* room)
{
	string s = "[";
	vector<Opponent*> v = *room->getOpponents();

	for (std::vector<Opponent*>::size_type i = 0; i != v.size(); i++) {
		/* std::cout << someVector[i]; ... */
		s += v[i]->getName() + "|";
	}
	string ret = s.substr(0, s.length() - 1);

}