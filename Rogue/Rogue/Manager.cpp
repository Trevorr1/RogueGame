#include "Manager.h"

using namespace std;

Manager::Manager()
{
	textfile = "data_save.txt";


	dungeon = new Dungeon();
	Room* room = new Room();
	addMapLevel(room);

	Opponent* opponent = new Opponent();
	room->addOpponent(opponent);

	//printf("\nHello World\n\n");
	int foo = room->getOpponents().at(0)->get_level();
	
	cout << foo;

	
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

void Manager::save(){
	//save the dungeon:
	dungeon->save(vectorSave);

	ofstream output_file(textfile);
	for (auto it_string : vectorSave){
		output_file << it_string  << "\n" << endl;
	}
}

void Manager::load(){
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