#include "Loader.h"
//#include <string> 
//#include <iostream> 
//#include <sstream> 


Loader::Loader()
{
	// rooms trait init
	vectorRoomKinds.push_back("room_size");
	vectorRoomKinds.push_back("room_state");
	vectorRoomKinds.push_back("room_illumation");
	vectorRoomKinds.push_back("room_shape");
	vectorRoomKinds.push_back("room_content");
	vectorRoomKinds.push_back("room_special_trait");

	room_sizes = new vector<string>;
	room_states = new vector<string>;
	room_lightings = new vector<string>;
	room_shapes = new vector<string>;
	room_contents = new vector<string>;
	room_specialTraits = new vector<string>;

	loadRoomTraits();

	// traps kinds
	vectorTrapKinds.push_back("normal_trap");
	vectorTrapKinds.push_back("poison_trap");
	vectorTrapKinds.push_back("deadly_trap");
	vectorTrapKinds.push_back("booby_trap");
	vectorTrapKinds.push_back("leghold_trap");

	traps = new vector<Trap*>;

	opponents = new vector <Opponent*>;

	loadTraps();
	loadFileOpponents();

	item_list = new vector<Item*>;
	loadFileItems();
}

Loader::~Loader()
{
	//delete vectorRoomKinds;
	delete room_sizes;
	delete room_states;
	delete room_lightings;
	delete room_shapes;
	delete room_contents;
	delete room_specialTraits;

	//delete vectorTrapKinds;
	delete traps;
	delete trap_poison;

	delete opponents;

	//delete item_list;
}

void Loader::loadEnemyList()
{
	string textfile("EnemyList.txt");
	cout << "Loading Room Traits" << endl;
}

void Loader::loadItemList()
{
	string textfile("ItemList.txt");
	cout << "Loading Room Traits" << endl;
}

void Loader::loadRoomTraits(){
	string textFileClass = "Rooms.txt";

	// (2a) Tekst inlezen uit een file met de klasse std::ifstream (input file stream)
	ifstream input_file(textFileClass); // stack-based file object; deze constructie opent de file voor lezen
	string line;

	int i = 0;
	//srand(time(0));

	while (getline(input_file, line)) {

		//if line contains == true
		if (i < vectorRoomKinds.size() && line.find(vectorRoomKinds.at(i)) != std::string::npos){
			i++;
		}
		else {
			//cout << "kinds"<< endl;
			if (vectorRoomKinds.at(i-1) == "room_size"){
				room_sizes->push_back(line);
			}
			else if (vectorRoomKinds.at(i-1) == "room_state"){
				room_states->push_back(line);
			}
			else if (vectorRoomKinds.at(i-1) == "room_illumation")
			{
				room_lightings->push_back(line);
			}
			else if (vectorRoomKinds.at(i-1) == "room_shape")
			{
				room_shapes->push_back(line);
			}
			else if (vectorRoomKinds.at(i-1) == "room_content")
			{
				room_contents->push_back(line);
			}
			else if (vectorRoomKinds.at(i-1) == "room_special_trait")
			{
				room_specialTraits->push_back(line);
			}

		}
	}

}

void Loader::loadTraps(){
	string textFileClass = "Traps.txt";

	// (2a) Tekst inlezen uit een file met de klasse std::ifstream (input file stream)
	ifstream input_file(textFileClass); // stack-based file object; deze constructie opent de file voor lezen
	string line;

	string trapKind = "";
	int dmg = NULL;
	int i = 0;
	//srand(time(0));


	while (getline(input_file, line)) {
		bool isDmg = true;

		//if line contains == true
		for (int i = 0; i < vectorTrapKinds.size(); i++){
			if (line.find(vectorTrapKinds.at(i)) != std::string::npos){
				trapKind = line;
				
				isDmg = false;
				break;
			}
		}

		if (isDmg){
			dmg = std::stoi(line);
			//cout << dmg<< endl;

			if (trapKind.find("normal_trap") != std::string::npos){
				Trap* trap1 = new Trap("trap", dmg);
				traps->push_back(trap1);
			}
			else if (trapKind.find("poison_trap") != std::string::npos){
				/*trap_poison->push_back(new PoisonTrap());*/
				Trap* trap1 = new Trap("poison trap", dmg);
				traps->push_back(trap1);
			}
			else if (trapKind.find("deadly_trap") != std::string::npos){
				Trap* trap1 = new Trap("deadly trap", dmg);
				traps->push_back(trap1);
			}
			else if (trapKind.find("booby_trap") != std::string::npos){
				Trap* trap1 = new Trap("booby trap", dmg);
				traps->push_back(trap1);
			}
			else if (trapKind.find("leghold_trap") != std::string::npos){
				Trap* trap1 = new Trap("leg hold trap", dmg);
				traps->push_back(trap1);
			}
			trapKind.clear();
			dmg = NULL;
		}
	}
}

void Loader::loadFileOpponents(){
	string textFileClass = "Opponents.txt";

	// (2a) Tekst inlezen uit een file met de klasse std::ifstream (input file stream)
	ifstream input_file(textFileClass); // stack-based file object; deze constructie opent de file voor lezen
	string line;

	vector <string>* vectorLoaded = new vector<string>;
	Opponent* op = nullptr;

	int i = 1;

	while (getline(input_file, line)) { // getline() geeft false zodra end-of-file is bereikt
		string level = "level";
		level += to_string(i) + ":";
		//cout << line << '\n'; // getline() haalt de \n wel uit de stream, maar voegt die niet toe

		if (line.find("level") == std::string::npos){
			vectorLoaded->push_back(line);
		}
		else {
			//cout << "gevonden"<< endl;
			if (i != 1){
				op = new Opponent();
				op->setOpponent(vectorLoaded);
				opponents->push_back(op);
			}

			delete vectorLoaded;
			vectorLoaded = new vector<string>;
			i++;
		}

		if (input_file.eof()){
			op = new Opponent();
			op->setOpponent(vectorLoaded);
			opponents->push_back(op);
		}
	}

	delete vectorLoaded;
}

void Loader::loadFileItems(){
	string textFileClass = "Items.txt";

	// (2a) Tekst inlezen uit een file met de klasse std::ifstream (input file stream)
	ifstream input_file(textFileClass); // stack-based file object; deze constructie opent de file voor lezen
	string line;
	Item* item = nullptr;

	int i = 0;
	while (getline(input_file, line)) { // getline() geeft false zodra end-of-file is bereikt
		//if line contains == true
		if (line.find("potions:") != std::string::npos){
		}
		else if(i == 0){
			item = new Item();
			item->setName(line);
			i++;
		}
		else if (i == 1){
			//std::istringstream is(line);
			//int sToi;
			//is >> sToi;
			//item->setHealth(sToi);

			//item->setHealth(atoi(line.c_str()));
			item->setHealth(stoi(line));
			item_list->push_back(item);
			//cout << item->getHealth() << endl;

			i = 0;
		}
	}
}