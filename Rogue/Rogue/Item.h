#pragma once
#include <string>

using namespace std;

class Item
{
public:
	Item();
	virtual ~Item();

	void setName(string name);
	void setHealth(int health);

	string getName(){ return m_Name; };
	int getHealth(){ return m_Health; };

protected:
	string m_Name;
	int m_Health;
};

