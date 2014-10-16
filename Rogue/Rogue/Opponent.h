#pragma once
class Opponent
{
public:
	Opponent();// (int a);
	virtual~Opponent();

	virtual int get_level();

protected:
	int level;
};

