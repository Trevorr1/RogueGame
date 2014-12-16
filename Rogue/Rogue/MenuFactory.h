#pragma once
#include "Menu.h"
#include "MenuAttack.h"
#include "MenuFight.h"
#include "MenuFlight.h"
#include "MenuRoom.h"
#include "MenuInventory.h"
#include "MenuUseObject.h"
#include "MenuDrink.h"
#include "Dungeon.h"

class MenuFactory
{
public:
	static MenuFactory * getInstance(); //use: MenuFactory::getInstance()
	virtual ~MenuFactory();

	void handleInput(string input);

	Menu* getMenu() { return m_Current; }
	void setMenu(Menu* next);

	MenuAttack* getAttackMenu() { return new MenuAttack(m_Dungeon->getCurrentRoom()); }
	//MenuFlight* getFlightMenu() { return new MenuFlight(); }
	MenuFlight* getFlightMenu(Room* room) { return new MenuFlight(room); }
	MenuFight* getFightMenu() { return new MenuFight(); }
	MenuRoom* getRoomMenu(Room* room) { return new MenuRoom(room); }
	MenuInventory* getInventoryMenu() { return new MenuInventory(); }
	MenuUseObject* getUseObjectMenu(Player* player) { return new MenuUseObject(player); }
	MenuDrink* getDrinkMenu() { return new MenuDrink(); }

	Dungeon* getDungeon() { return m_Dungeon; }
	void setDungeon(Dungeon* dungeon){ m_Dungeon = dungeon; }

private:
	static MenuFactory * _instance;
	MenuFactory();
	Menu* m_Current;
	Dungeon* m_Dungeon;
};

