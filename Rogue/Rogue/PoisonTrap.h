#pragma once
#include "Trap.h"
class PoisonTrap :
	public Trap
{
public:
	PoisonTrap();
	virtual ~PoisonTrap();
	virtual void springTrap();
	virtual void deactivate();
};

