#include <stdio.h>
#include "LoaderManager.h"
#include "Manager.h"
#include <chrono>
#include <thread>
#include "Player.h"
#include "MenuFight.h"
#include "Menu.h"
#include "MenuRoom.h"
#include "Floor.h"
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

using namespace std;

int main(int argc, const char* argv[])
{
	/*printf("\nHello World\n\n"); */
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Loader* loader = new Loader();
	LoaderManager::getInstance()->setLoader(loader);

	Manager*  manager = new Manager();
	MenuRoom* menuRoom = new MenuRoom();
	Player* player = new Player();
<<<<<<< HEAD
	
	manager->loadAll();
=======
	manager->setState(menuRoom);
>>>>>>> origin/master

	manager->loadAll();

	while (true){
		chrono::milliseconds dura(2000);
		this_thread::sleep_for(dura);
		printf("Thread sleep 2 sec \n\n");

		string input;
		cout << "Please enter an string value: ";
		cin >> input;
		cout << "The value you entered is " << input << endl;

	}

	Floor* floor = new Floor;
	floor->generateRooms(nullptr, false);
	floor->updateMap();
	floor->printFloor();
	string input;
	cout << "press enter to exit...";
	cin >> input;

	_CrtDumpMemoryLeaks();
}

