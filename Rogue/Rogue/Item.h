#pragma once
#include <string>

using namespace std;

class Item
{
public:
	Item();
	virtual ~Item();

	void setDescription(string desc);

protected:
	string m_Name;
	string m_Description;
};

