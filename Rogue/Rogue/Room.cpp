#include "Room.h"

Room::Room()
{
	opponents = new vector<Opponent*>;
}


Room::Room(int level, bool endBossRoom, int rseed)
{
	generateTraits();
	opponents = new vector<Opponent*>;

	if (!endBossRoom){
		generateOpponents(level);
	}
	else{
		generateEndOpponents(level, 2);
	}

	generateItem();
}


Room::~Room()
{
	delete opponents;
}

char* Room::printRoom()
{
	if (m_startPoint)
		return "S";
	if (m_Visited)
	{
		if (m_EndPoint)
			return "E";
		if (m_StairUp != nullptr)
			return "H";
		if (m_StairDown != nullptr)
			return "L";
		return "N";
	}
	else return "_";
}

string Room::printRoomText()
{
	string desc = "Description: You're in a ";
	desc += m_Traits.at(0) + " " + m_Traits.at(3);
	desc += "Room that is ";
	desc += m_Traits.at(2);
	desc += ". It's " + m_Traits.at(1) + " and" + m_Traits.at(5) + ".\n";
	desc += m_Traits.at(6) + "\n\n";

	// print room exits
	string exits = "Exits: " + printExits() + "\n\n";
	
	// print enemies
	string enemies = "Present: " + printOpponents() + "\n\n";

}

string Room::printOpponents()
{
	string s = "";

	for (std::vector<Opponent*>::size_type i = 0; i != m_Opponents->size(); i++) {
		if (i < m_Opponents->size())
			s += m_Opponents->at(i)->getName() + ", ";
		else
			s += " and " + m_Opponents->at(i)->getName() + ".";
	}
	return s;
}

string Room::printOpponentsFight()
{
	string s = "";

	for (std::vector<Opponent*>::size_type i = 0; i != m_Opponents->size(); i++) {
		s += m_Opponents->at(i)->getName() + " - " + to_string(i + 1) +": ";
		s += m_Opponents->at(i)->printStatus();
	}
	return s;
}

string Room::printExits()
{
	string s = "There is";
	if (m_North != nullptr)
		s += " a door to the north,";
	if (m_East != nullptr)
		s += " a door to the east,";
	if (m_West != nullptr)
		s += " a door to the west,";
	if (m_South != nullptr)
		s += " a door to the south,";
	if (m_StairDown != nullptr)
		s += " a stairway leading deeper down into the dungeon,";
	if (m_StairUp != nullptr)
		s += " a stairway leading to an upper floor.";

	string ret = s.substr(0, s.length() - 1);
	ret += ".";
	return ret;
}


void Room::addOpponent(Opponent* opponent){
	opponents->push_back(opponent);
}

vector<Opponent*>* Room::getOpponents(){
	return m_Opponents;
}

void Room::generateTraits(){
	Loader* loader = LoaderManager::getInstance()->getLoader();

	string size = loader->getRoom_sizes()->at(rand() % loader->getRoom_sizes()->size());
	string state = loader->getRoom_states()->at(rand() % loader->getRoom_states()->size());
	string illumation = loader->getRoom_lightings()->at(rand() % loader->getRoom_lightings()->size());
	string shape = loader->getRoom_shapes()->at(rand() % loader->getRoom_shapes()->size());
	string content = loader->getRoom_contents()->at(rand() % loader->getRoom_contents()->size());
	string special = loader->getRoom_specialTraits()->at(rand() % loader->getRoom_specialTraits()->size());

	addTrait(size);
	addTrait(state);
	addTrait(illumation);
	addTrait(shape);
	addTrait(content);
	addTrait(special);

	loader = nullptr;
}
void Room::generateOpponents(int level){
	vector<Opponent*>* loaderOpponents = LoaderManager::getInstance()->getLoader()->getOpponents();

	level++;
	int leveldivided = level; //based on 20 dungeon floors(levels)
		vector<Opponent*>* randomOpponents = new vector<Opponent*>;
		if (level <=2){
			for (int i = 0; i < 6; i++){
				randomOpponents->push_back(loaderOpponents->at(i));
			}
		}
		else{
			for (int i = 0; i < loaderOpponents->size(); i++){
				/*find e.g. opponents lv 3 in floor level 6*/
				if (loaderOpponents->at(i)->getLevel() == leveldivided/2){
					randomOpponents->push_back(loaderOpponents->at(i));
				}
				/*find e.g opponents lv 4 in floor level 6*/
				if(loaderOpponents->at(i)->getLevel() == leveldivided / 2+1){
					randomOpponents->push_back(loaderOpponents->at(i));
				}
				
			}
		}

		vector<int> chanceOpponents;
		chanceOpponents.push_back(0);
		chanceOpponents.push_back(0);
		chanceOpponents.push_back(1);
		chanceOpponents.push_back(2);
		chanceOpponents.push_back(3);

		int randomOpponentsAmount = chanceOpponents.at(rand() % chanceOpponents.size());

		/*add random opponents amount to opponents*/
		if (randomOpponents->size() >= randomOpponentsAmount){
			for (int i = 0; i < randomOpponentsAmount; i++){
				int random3 = rand() % randomOpponents->size();
				opponents->push_back(randomOpponents->at(random3));
			}
		}
		else{
			for (int i = 0; i < randomOpponents->size(); i++){
				opponents->push_back(randomOpponents->at(i));
			}
		}

	loaderOpponents = nullptr;
	delete randomOpponents;
}

void Room::generateEndOpponents(int level, int monsterSize){
	vector<Opponent*>* loaderOpponents = LoaderManager::getInstance()->getLoader()->getOpponents();
	vector<Opponent*>* randomOpponents = new vector<Opponent*>;

	level++;
	int leveldivided = level;

	/*End bosses to randomOppenents*/
	if (level == 20){

		for (int i = 0; i < loaderOpponents->size(); i++){
			/*find opponents lv 11*/
			if (loaderOpponents->at(i)->getLevel() == leveldivided / 2 + 1){
				randomOpponents->push_back(loaderOpponents->at(i));
			}
			/*find opponents lv 12*/
			if (loaderOpponents->at(i)->getLevel() == leveldivided / 2 + 2){
				randomOpponents->push_back(loaderOpponents->at(i));
			}
			/*find opponents lv 13*/
			if (loaderOpponents->at(i)->getLevel() == leveldivided / 2 + 3){
				randomOpponents->push_back(loaderOpponents->at(i));
			}

		}
	}
	/*pick random end bosses based on monsterSize*/
	for (int i = 0; i < monsterSize; i++){
		int randomEndBoss = rand() % randomOpponents->size();
		opponents->push_back(randomOpponents->at(randomEndBoss));
	}
	
	delete randomOpponents;
}

void Room::setTrap(int level){
	vector<Trap*>* traps = LoaderManager::getInstance()->getLoader()->getTraps();

	if (level <= 7){
		int randomTrap = rand() % 2;
		m_Trap = traps->at(randomTrap);
	}
	else if (level <= 13){
		int randomTrap = rand() % 2+2;
		m_Trap = traps->at(randomTrap);
	}
	else if (level <= 20){
		int randomTrap = rand() % 2+4;
		m_Trap = traps->at(randomTrap);
	}
	traps = nullptr;
}

void Room::generateItem(){
	vector<Item*>* items = LoaderManager::getInstance()->getLoader()->getItems();
	
	m_Item = items->at(rand() % items->size());
}


void Room::addTrait(string trait)
{
	m_Traits.push_back(trait);
}


void Room::setVisited()
{
	m_Visited = true;
}

void Room::setStart()
{
	m_startPoint = true;
}

void Room::setEnd()
{
	m_EndPoint = true;
}

void Room::setNorth(Room* north)
{
	m_North = north;
}

void Room::setEast(Room* east)
{
	m_East = east;
}

void Room::setWest(Room* west)
{
	m_West = west;
}

void Room::setSouth(Room* south)
{
	m_South = south;
}

void Room::setStairUp(Room* up)
{
	m_StairUp = up;
}

void Room::setStairDown(Room* down)
{
	m_StairDown = down;
}

Room* Room::getNorth()
{
	return m_North;
}

Room* Room::getEast()
{
	return m_East;
}

Room* Room::getWest()
{
	return m_West;
}

Room* Room::getSouth()
{
	return m_South;
}

bool Room::getVisited()
{
	return m_Visited;
}
