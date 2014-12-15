#include "MenuUseObject.h"
#include "Player.h"
#include "MenuFactory.h"


MenuUseObject::MenuUseObject(Player* player)
{
	updateOptions(player);
	printOptions();
}


MenuUseObject::~MenuUseObject()
{
}

void MenuUseObject::handleInput(MenuFactory* context, string input)
{
	auto v = context->getDungeon()->getPlayer()->getInventory();
	if (!v->empty())
	{
		if (std::find(m_Options.begin(), m_Options.end(), input) != m_Options.end())
		{
			if (input.compare("back") == 0)
			{
				context->setMenu(context->getRoomMenu(context->getDungeon()->getCurrentRoom()));
			}
			else //player chose to use an item
			{
				cout << "You used: " << input << "\n\n";
				context->getDungeon()->getPlayer()->use(input);
				if (v->empty())
				{
					cout << "You have no items left.\n\n";
					context->setMenu(context->getRoomMenu(context->getDungeon()->getCurrentRoom()));
				}
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
		cout << "Your inventory is empty. You have no items to use.\n\n";
		context->getRoomMenu(context->getDungeon()->getCurrentRoom());
	}
}

void MenuUseObject::updateOptions(Player* player)
{
	m_Options.clear();

	auto v = player->getInventory();
	if (!v->empty())
	{
		for (auto item : *v)
		{
			m_Options.push_back(item->getName());
		}
	}
	m_Options.push_back("back");
}

void MenuUseObject::printOptions()
{
	if (!m_Options.empty())
	{
		string s = "";
		for (vector<string>::iterator it = m_Options.begin(); it != m_Options.end(); it++) {
			s += *it + "|";
		}
		string ret = s.substr(0, ret.size() - 1);


		cout << "You are carrying:\n\n";
		cout << ret << "\n\n";
	}
	else
	{
		cout << "You have no items to use.\n\n";
	}
}