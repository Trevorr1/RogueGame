#pragma once
#include <string>
#include <vector>

namespace std{
	class Opponent
	{
	public:
		Opponent();
		virtual~Opponent();
		Opponent(const Opponent &obj);
		Opponent(const Opponent *obj);


		int getLevel() { return m_Level; }
		int getDmg() { return m_Atk; }
		int getDef() { return m_Def; }

		bool isAlive() { return m_Alive; }

		string getName(){ return m_Name; }

		string printStatus();
		void setOpponent(vector <string>* vectorLoaded);

		void damage(int dmg);

	private:
		int m_Level, m_Atk, m_Health, m_CurrentHealth, m_Def, m_Gains;
		bool m_Alive;
		string m_Name;
	};
}