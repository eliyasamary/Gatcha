#include "Player.h"
const int START_MONEY = 200;
/*-------------------------------------------------------------------------------*/
Player::Player(std::string name)
	:
	m_name(name),
	m_invested_money(0),
	m_money(START_MONEY) {}
/*-------------------------------------------------------------------------------*/
void Player::PlayMachine(GatchaMachine machine)
{
	// Checks that the player can play the machine
	int cost = machine.GetPrice();
	if (m_money > cost)	// player can play
	{ 
		m_money -= cost;
		m_invested_money+= cost;
	}
	else // player can't play
	{
		std::cout << "Player dont have enough money to play this machine" << std::endl;
		return;
	}
	
	// Checks that there are enough capsules in the machine to play
	int num_of_capsules = machine.GetNumOfCapsules();
	if (num_of_capsules > 0)
	{
		srand(time(nullptr));
		// Generate a random number in the range 0 to the number of capsules in the machine
		int randNum = rand() % num_of_capsules;
		Capsule* win_capsul = machine.RollForCapsule(randNum);
		m_capsules_won.push_back(win_capsul);
		int won_price = win_capsul->GetWorth();
		std:: cout << "The value of the prize you won is "<< won_price <<std::endl;
		m_won_money+= won_price;
	}
	else
	{
		std::cout << "Machine is empty!" << std::endl;
		return;
	}
	std::cout << "Capsule purchased succesfully" << std::endl;
}
/*-------------------------------------------------------------------------------*/
void Player::PrintWonCap()
{
	string theme_name_array[8] = /*An array that will help print the theme as a string*/
	{
		"None",
		"Dragon Ball Z",
		"Naruto",
		"Pokemon",
		"Attack On Titan",
		"Bleach",
		"Spy X Family",
		"Full Metal Alchemist"
	};

	std::cout << "Capsules I won:"<< std::endl<< std::endl;;

	for (int i = 0; i < m_capsules_won.size(); i++)
	{
		std::cout << i+1 << ") "<< "name: " << m_capsules_won[i]->GetName() << std::endl;
		if (m_capsules_won[i]->GetType() == _Toy)
		{
			std::cout << "Theme: " << theme_name_array[static_cast<Toy*>(m_capsules_won[i])->GetCategory()] << std::endl;
		}
		else if (m_capsules_won[i]->GetType() == _Candy)
		{
			string flavor = static_cast<Candy*>(m_capsules_won[i])->GetFlavor();
			std::cout << "Flavor: " << flavor << std::endl;
		}
		std::cout << std::endl;
	}
	
}

/*-------------------------------------------------------------------------------*/
void Player::CalculateEarnings()
{
	PrintWonCap();
	if (m_won_money > m_invested_money)
	{
		cout <<  GetPlayerName() << " earned " << m_won_money - m_invested_money << endl;
	}
	else if (m_won_money <= m_invested_money)
	{
		cout <<  GetPlayerName() << " lost " << START_MONEY - m_invested_money << endl;
	}
}
/*-------------------------------------------------------------------------------*/