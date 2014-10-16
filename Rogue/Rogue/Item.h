#pragma once
#include <string>

using namespace std;

class Item
{
public:
	Item();
	virtual ~Item();

protected:
	string m_Name;
};

