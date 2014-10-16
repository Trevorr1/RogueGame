#include "PoisonTrap.h"


PoisonTrap::PoisonTrap()
{
	this->active = true;
	this->damage = 25;
}


PoisonTrap::~PoisonTrap()
{
}

void PoisonTrap::springTrap()
{
	this->active = false;
}

void PoisonTrap::deactivate()
{
	this->active = false;
}