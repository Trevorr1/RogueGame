#pragma once
#include "Menu.h"
#include "MenuAttack.h"
#include "MenuFight.h"
#include "MenuFlight.h"
#include "MenuRoom.h"
#include "MenuInventory.h"
#include "Dungeon.h"

class MenuFactory
{
public:
	MenuFactory();
	virtual ~MenuFactory();

	void handleInput(string input);

	Menu* getMenu() { return m_Current; }
	void setMenu(Menu* next) { m_Current = next; }

	MenuAttack* getAttackMenu() { return new MenuAttack(); }
	MenuFlight* getFlightMenu() { return new MenuFlight(); }
	MenuFight* getFightMenu() { return new MenuFight(); }
	MenuRoom* getRoomMenu() { return new MenuRoom(); }
	MenuInventory* getInventoryMenu() { return new MenuInventory(); }

	Dungeon* getDungeon() { return m_Dungeon; }


private:
	Menu* m_Current;
	Dungeon* m_Dungeon;
};

