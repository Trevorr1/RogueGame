#include "Loader.h"


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
	//trap_poison = new vector<PoisonTrap*>;

	loadTraps();
}


Loader::~Loader()
{
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