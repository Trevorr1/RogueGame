#include "Manager.h"

using namespace std;

Manager::Manager()
{
	textfile = "data_save.txt";

	dungeon = new Dungeon();
	Room* room = new Room();
	addMapLevel(room);

	opponent = new Opponent();
	room->addOpponent(opponent);

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


	loadFileAllOpponents(room->getOpponents());
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
		cout << line << '\n'; // getline() haalt de \n wel uit de stream, maar voegt die niet toe
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
			cout << line << '\n'; // getline() haalt de \n wel uit de stream, maar voegt die niet toe

		if (line != level){
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