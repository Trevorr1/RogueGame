#include "Loader.h"


Loader::Loader()
{
	// rooms trait init
	loadRoomTraits();
	vectorRoomKinds.push_back("room_size");
	vectorRoomKinds.push_back("room_state");
	vectorRoomKinds.push_back("room_illumation");
	vectorRoomKinds.push_back("room_shape");
	vectorRoomKinds.push_back("room_content");
	vectorRoomKinds.push_back("room_special_trait");

}


Loader::~Loader()
{
}

void Loader::loadRoomTraits()
{
	string textFile("Rooms.txt");

	// (2a) Tekst inlezen uit een file met de klasse std::ifstream (input file stream)
	ifstream input_file(textFile); // stack-based file object; deze constructie opent de file voor lezen
	string line;
/*
	vector <string>* vectorLoaded = new vector < string > ;
	vector <string>* vectorRandomized = new vector < string > ;
	Room* room = new Room();
	int i = 0;*/
	//srand(time(0));

	int i = 0;


	while (getline(input_file, line)) 
	{
		if (line.find("room_size") == std::string::npos)
		{
			room_sizes.push_back(line);
		}
		else if (line.find("room_state") == std::string::npos)
		{
			room_states.push_back(line);
		}
		else if (line.find("room_illumation") == std::string::npos)
		{
			room_shapes.push_back(line);
		}
		else if (line.find("room_shape") == std::string::npos)
		{
			room_lightings.push_back(line);
		}
		else if (line.find("room_content") == std::string::npos)
		{
			room_contents.push_back(line);
		}
		else if (line.find("room_special_trait") == std::string::npos)
		{
			room_specialTraits.push_back(line);
		}

		//	//if line contains == true
		//	if (line.find(vectorRoomKinds.at(i)) != std::string::npos){
		//		if (i != 0){
		//			int randItem = rand() % vectorLoaded->size();
		//			vectorRandomized->push_back(vectorLoaded->at(randItem));

		//			delete vectorLoaded;
		//			vectorLoaded = new vector<string>;
		//		}
		//		if (i < vectorRoomKinds.size() - 1){
		//			i++;
		//		}
		//	}
		//	else {
		//		vectorLoaded->push_back(line);
		//	}

		//	if (input_file.eof()){
		//		int randItem = rand() % vectorLoaded->size();
		//		vectorRandomized->push_back(vectorLoaded->at(randItem));
		//	}
		//}

		cout << "Loading Room Traits" << endl;

	}
	int foo = 0;
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

Room* Loader::loadFileRandomRoom(){
	string textFileClass = "Rooms.txt";

	// (2a) Tekst inlezen uit een file met de klasse std::ifstream (input file stream)
	ifstream input_file(textFileClass); // stack-based file object; deze constructie opent de file voor lezen
	string line;

	vector <string>* vectorRoomKinds = new vector<string>;
	vectorRoomKinds->push_back("room_size");
	vectorRoomKinds->push_back("room_state");
	vectorRoomKinds->push_back("room_illumation");
	vectorRoomKinds->push_back("room_shape");
	vectorRoomKinds->push_back("room_content");
	vectorRoomKinds->push_back("room_special_trait");

	vector <string>* vectorLoaded = new vector<string>;
	vector <string>* vectorRandomized = new vector<string>;
	Room* room = new Room();
	int i = 0;
	//srand(time(0));

	while (getline(input_file, line)) { // getline() geeft false zodra end-of-file is bereikt
		//cout << line << '\n'; // getline() haalt de \n wel uit de stream, maar voegt die niet toe

		//if line contains == true
		if (line.find(vectorRoomKinds->at(i)) != std::string::npos){
			if (i != 0){
				int randItem = rand() % vectorLoaded->size();
				vectorRandomized->push_back(vectorLoaded->at(randItem));

				delete vectorLoaded;
				vectorLoaded = new vector<string>;
			}
			if (i < vectorRoomKinds->size() - 1){
				i++;
			}
		}
		else {
			//cout << "kinds"<< endl;
			vectorLoaded->push_back(line);
		}

		if (input_file.eof()){
			int randItem = rand() % vectorLoaded->size();
			vectorRandomized->push_back(vectorLoaded->at(randItem));
		}
	}

	room->setRoom(vectorRandomized);

	delete vectorRoomKinds;
	delete vectorLoaded;
	return room;

}