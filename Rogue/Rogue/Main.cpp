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

using namespace std;

int main(int argc, const char* argv[])
{
	/*printf("\nHello World\n\n"); */

	Loader* loader =  new Loader();
	LoaderManager::getInstance()->setLoader(loader);

	Manager*  manager = new Manager();
	MenuRoom* menuRoom = new MenuRoom();
	Player* player = new Player();
	
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
}

