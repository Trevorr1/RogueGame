#pragma once
#include <string>

using namespace std;

class Trap
{
public:
	Trap();
	virtual ~Trap();
	virtual void springTrap();
	virtual void deactivate();

	Trap(string name, int damage){ this->name = name; this->damage = damage; };
protected:
	bool active;
	int damage;
	string name;

};

