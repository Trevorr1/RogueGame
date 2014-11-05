#include "Manager.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Manager::Manager()
{
	textfile = "data_save.txt";

	int rseed = 5;

	dungeon = new Dungeon(5);
	Room* room = new Room();
	addMapLevel(room);

	opponent = new Opponent();
	room->addOpponent(opponent);

	Loader* loader = new Loader();

	/*vector <string>* vectorTestOpponent = new vector<string>;
	vectorTestOpponent->push_back("1");
	vectorTestOpponent->push_back("1");
	vectorTestOpponent->push_back("5");
	vectorTestOpponent->push_back("1");
	vectorTestOpponent->push_back("10");
	vectorTestOpponent->push_back("Ratata");

	saveFile(vectorTestOpponent, "Opponent.txt");
	Opponent* opponentLoaded = new Opponent(); 
	opponentLoaded->setOpponent(loadFile("Opponent.txt"));*/


	//loadFileAllOpponents(room->getOpponents());	
	loadFileRandomRoom();
}


Manager::~Manager()
{
}

void Manager::addMapLevel(Room* room){
	mapLevels.push_back(room);
}

Menu* Manager::getState(){
	return state;
}

void Manager::setState(Menu* state){
	this->state = state;
}

void Manager::saveAll(){
	//save the dungeon:
	dungeon->save(vectorSave);

	ofstream output_file(textfile);
	for (auto it_string : *vectorSave){
		output_file << it_string  << "\n" << endl;
	}
}

void Manager::loadAll(){
	// (2a) Tekst inlezen uit een file met de klasse std::ifstream (input file stream)
	ifstream input_file(textfile); // stack-based file object; deze constructie opent de file voor lezen
	string line;

	// getline() leest een regel die eindigt in een \n
	// (je kunt ook een 3e param meegeven als je een ander 'regeleinde' wil gebruiken)
	while (getline(input_file, line)) { // getline() geeft false zodra end-of-file is bereikt
		cout << line << '\n'; // getline() haalt de \n wel uit de stream, maar voegt die niet toe
	}
	// zodra input_file weer uit scope raakt (aan het eind van dit block) wordt de file automatisch gesloten

}

// Save class: Opponent etc
void Manager::saveFile(vector <string>* vectorToSave, string textFileClass){
	ofstream output_file(textFileClass);
	for (string it_string : *vectorToSave){
		//output_file << it_string << "\n" << endl;
		output_file << it_string << endl;
	}
}

vector<string>* Manager::loadFile(string textFileClass){
	// (2a) Tekst inlezen uit een file met de klasse std::ifstream (input file stream)
	ifstream input_file(textFileClass); // stack-based file object; deze constructie opent de file voor lezen
	string line;

	vector <string>* vectorLoaded = new vector <string>;

	// getline() leest een regel die eindigt in een \n
	// (je kunt ook een 3e param meegeven als je een ander 'regeleinde' wil gebruiken)
	while (getline(input_file, line)) { // getline() geeft false zodra end-of-file is bereikt
		//cout << line << '\n'; // getline() haalt de \n wel uit de stream, maar voegt die niet toe
		vectorLoaded->push_back(line);
	}
	// zodra input_file weer uit scope raakt (aan het eind van dit block) wordt de file automatisch gesloten

	return vectorLoaded;

}

void Manager::loadFileAllOpponents(vector<Opponent*>* VectorOpponents){
	string textFileClass = "Opponents.txt";

	// (2a) Tekst inlezen uit een file met de klasse std::ifstream (input file stream)
	ifstream input_file(textFileClass); // stack-based file object; deze constructie opent de file voor lezen
	string line;

	vector <string>* vectorLoaded = new vector<string>;
	Opponent* op = nullptr;

	int i = 1;
	
	while (getline(input_file, line)) { // getline() geeft false zodra end-of-file is bereikt
		string level= "level";
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
				VectorOpponents->push_back(op);
			}

			delete vectorLoaded;
			vectorLoaded = new vector<string>;
			i++;
		}
	
		if (input_file.eof()){
			op = new Opponent();
			op->setOpponent(vectorLoaded);
			VectorOpponents->push_back(op);
		}
	}

	delete vectorLoaded;
}

Room* Manager::loadFileRandomRoom(){
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
		if (line.find(vectorRoomKinds->at(i)) != std::string::npos)
		{
			if (i != 0)
			{
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