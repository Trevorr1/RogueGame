#include <stdio.h>
#include "Manager.h"
#include <chrono>
#include <thread>
#include "Player.h"
#include "MenuFight.h"
#include "Menu.h"
#include "MenuRoom.h"

using namespace std;


int main(int argc, const char* argv[])
{
	printf("\nHello World\n\n");

	Manager*  manager = new Manager();
	MenuRoom* menuRoom = new MenuRoom();
	Player* player = new Player();
	manager->setState(menuRoom);
	
	manager->load();


	while (true){
		chrono::milliseconds dura(2000);
		this_thread::sleep_for(dura);
		printf("Thread sleep 2 sec \n\n");

		string input;
		cout << "Please enter an string value: ";
		cin >> input;
		cout << "The value you entered is " << input << endl;
		manager->getState()->handleInput(input);

	}


}

