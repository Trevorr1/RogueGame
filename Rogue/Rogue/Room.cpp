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

void Room::addOpponent(Opponent* opponent){
	opponents->push_back(opponent);
}

vector<Opponent*>* Room::getOpponents(){
	return opponents;
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
				if (loaderOpponents->at(i)->get_level() == leveldivided/2){
					randomOpponents->push_back(loaderOpponents->at(i));
				}
				/*find e.g opponents lv 4 in floor level 6*/
				if(loaderOpponents->at(i)->get_level() == leveldivided / 2+1){
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
			if (loaderOpponents->at(i)->get_level() == leveldivided / 2 + 1){
				randomOpponents->push_back(loaderOpponents->at(i));
			}
			/*find opponents lv 12*/
			if (loaderOpponents->at(i)->get_level() == leveldivided / 2 + 2){
				randomOpponents->push_back(loaderOpponents->at(i));
			}
			/*find opponents lv 13*/
			if (loaderOpponents->at(i)->get_level() == leveldivided / 2 + 3){
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
	traps == nullptr;
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

void Room::setRoom(vector <string>* vectorLoaded){
	m_Size = vectorLoaded->at(0);
	m_State = vectorLoaded->at(1);
	m_Illumation = vectorLoaded->at(2);
	m_Shape = vectorLoaded->at(3);
	m_Content = vectorLoaded->at(4);
	m_Special = vectorLoaded->at(5);
}