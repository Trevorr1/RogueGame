#pragma once
class Trap
{
public:
	Trap();
	virtual ~Trap();
	virtual void springTrap();
	virtual void deactivate();
protected:
	bool active;
	int damage;
};

