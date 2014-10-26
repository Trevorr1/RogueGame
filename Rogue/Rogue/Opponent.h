#pragma once
#include <string>
#include <vector>

namespace std{
	class Opponent
	{
	public:
		Opponent();
		virtual~Opponent();

		int get_level();
		void setOpponent(vector <string>* vectorLoaded);

	private:
		int m_Level, m_Atk, m_Health, m_Def, m_Gains;
		string m_Name;
	};
}