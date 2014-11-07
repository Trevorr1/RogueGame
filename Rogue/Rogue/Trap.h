#pragma once
#include <string>

using namespace std;

class Trap
{
public:
	Trap();
	virtual ~Trap();
	Trap(string name, int damage){ this->name = name; this->damage = damage; };

	void springTrap();
	void deactivate();

	string getName() { return name; }

protected:
	bool active;
	int damage;
	string name;

};

