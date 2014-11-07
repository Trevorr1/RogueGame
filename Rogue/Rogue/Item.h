#pragma once
#include <string>

using namespace std;

class Item
{
public:
	Item();
	virtual ~Item();

	void setDescription(string desc) { m_Description = desc; }

	string getName() { return m_Name; }

protected:
	string m_Name;
	string m_Description;
};

