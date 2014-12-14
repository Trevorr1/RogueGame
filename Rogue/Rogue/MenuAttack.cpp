#include "MenuAttack.h"
#include "MenuFactory.h"


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
	vector<Opponent*>* v = context->getDungeon()->getCurrentRoom()->getOpponents();
	if (!v->empty())
	{
		if (std::find(m_Options.begin(), m_Options.end(), input) != m_Options.end())
		{
			cout << "You have attacked: " << input << "\n\n";
			context->getDungeon()->resolveDamageToBaddies(input);
			if (v->empty())
			{
				cout << "There are no enemies left in this room.\n\n";
				context->setMenu(context->getRoomMenu(context->getDungeon()->getCurrentRoom()));
			}
			else
			{
				context->getDungeon()->resolveDamageToPlayer();
				updateOptions(context->getDungeon()->getCurrentRoom());
				printOptions();
			}
		}
		else
		{
			cout << "Choose another option please.\n\n";
			printOptions();
		}
	}
	else // no opponents in this room
	{
		cout << "There are no enemies in this room.\n\n";
		context->getRoomMenu(context->getDungeon()->getCurrentRoom());
	}
}

void MenuAttack::updateOptions(Room* room)
{
	m_Options.clear();

	vector<Opponent*> v = *room->getOpponents();
	for (auto opponent : v)
	{
		m_Options.push_back(opponent->getName());
	}
}

void MenuAttack::printOptions()
{
	if (!m_Options.empty())
	{
		string s = "";
		for (vector<string>::iterator it = m_Options.begin(); it != m_Options.end(); it++) {
			s += *it + "|";
		}
		string ret = s.substr(0, ret.size() - 1);


		cout << "Your opponents are:\n\n";
		cout << ret << "\n\n";
	}
	else
	{
		cout << "There are no enemies to fight here.\n\n";
	}
}