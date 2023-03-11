#pragma once
#include "GatchaMachine.h"
#include "Toy.h"
#include "Candy.h"

class Player
{
public:
	Player(std::string name);
	~Player() {}
	void PlayMachine(GatchaMachine machine);
	void CalculateEarnings();
	int GetMoney() { return m_money; }
	string GetPlayerName() {return m_name;}
	void PrintWonCap();
private:
	std::string				m_name;
	int						m_money;
	int						m_invested_money;
	int 					m_won_money;
	std::vector<Capsule*>	m_capsules_won;
};

