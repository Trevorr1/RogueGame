#include <stdio.h>
#include "LoaderManager.h"
#include "Manager.h"
#include <chrono>
#include <thread>
#include "Player.h"
#include "MenuFight.h"
#include "Floor.h"
#include "MenuFactory.h"
//#ifdef _DEBUG
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
//#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
//#define new DEBUG_NEW
//#endif

//#include <vld.h>

using namespace std;

int main(int argc, const char* argv[])
{
	/*printf("\nHello World\n\n"); */
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Loader* loader = nullptr;
	Manager* manager = nullptr;

	bool running = false;

	cout << "The Rogue Game by Trevorr Marshall & Huan Nguyen" << endl;
	cout << "Enter <play> to play or enter <exit> at anytime to exit the game." << endl;

	string input;
	cin >> input;
	if (input == "play"){
		loader = new Loader();
		
		LoaderManager::getInstance()->setLoader(loader);
		MenuFactory::getInstance();	//create MenuFactory
		manager = new Manager();
		running = true;
	}

	while (running){
		string input;
		cout << "Please enter an string value: ";

		//cin >> input;

		std::getline(std::cin, input);
		if (input != "exit"){
			//cout << "The value you entered is " << input << endl;
			manager->handleInput(input);
		}
		else{
			cout << "Exiting the game " << endl;
			chrono::milliseconds dura(1000);
			this_thread::sleep_for(dura);
			
			running = false; //stop the game loop

			//Destruction
			delete LoaderManager::getInstance();
			delete loader;
			delete MenuFactory::getInstance();

			delete manager;
		}
	}

	//_CrtDumpMemoryLeaks();
}

