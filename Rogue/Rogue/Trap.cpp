#include "Trap.h"


Trap::Trap()
{
	this->active = true;
	this->damage = 10;
}


Trap::~Trap()
{
}

void Trap::springTrap()
{
	this->active = false;
}

void Trap::deactivate()
{
	this->active = false;
}