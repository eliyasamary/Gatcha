#include "Player.h"
const int MAX_MACHINES = 10;
const int MAX_CAPSULES = 50;

void SortCapsulesToMachines(GatchaMachine* machines, Capsule** capsules)
{
	for (int i = 0; i < MAX_MACHINES; i++)
	{
		Series current_machine_theme = machines[i].GetTheme();
		std::string current_machine_color = machines[i].GetColor();
		int num_of_epics = 0, num_of_legend = 0;
		for (int j = 0; j < MAX_CAPSULES; j++)
		{
			CapType curr_capsule_type = capsules[j]->GetType();
			Rarity curr_capsule_rarity = capsules[j]->GetRarity();
			if (curr_capsule_type == _Candy)
			{
				if (current_machine_color == capsules[j]->GetColor())
				{
					if (machines[i].InsertCapsule(capsules[j]))
					{
						if (curr_capsule_rarity == Legendary)
						{
							num_of_legend++;
						}
						else if (curr_capsule_rarity == Epic)
						{
							num_of_epics++;
						}
					}
				}
			}
			if (curr_capsule_type == _Toy)
			{
				if (current_machine_theme == static_cast<Toy*>(capsules[j])->GetCategory())
				{
					if (machines[i].InsertCapsule(capsules[j]))
					{
						if (curr_capsule_rarity == Legendary)
						{
							num_of_legend++;
						}
						else if (curr_capsule_rarity == Epic)
						{
							num_of_epics++;
						}
					}
				}
			}
		}
		if (num_of_epics < 2)
		{
			machines[i].AddEpicsFromExtra(num_of_epics);
		}
		if (num_of_legend < 1)
		{
			machines[i].AddLegendarysFromExtra();
		}
		machines[i].DeleteExtras();
	}
}

int FindCheapestMachineCost(GatchaMachine* machines)
{
	int min = machines[0].GetPrice();
	for (int i = 1; i < MAX_MACHINES; i++)
	{
		if (machines[i].GetTheme() != None)
		{
			if (machines[i].GetPrice() < min) min = machines[i].GetPrice();
		}
	}
	return min;
}

bool CheckIfGameContinues(int players_money, int cheapest_machine_cost)
{
	if (players_money < cheapest_machine_cost) return false;
	else return true;
}

int main()
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

	// PLAYER
	Player player("Eliya");

	// MACHINES
	GatchaMachine machine_array[MAX_MACHINES];
	machine_array[0] = GatchaMachine(DragonBallZ, 15, "Yellow");
	machine_array[1] = GatchaMachine(Naruto, 20, "Red");
	machine_array[2] = GatchaMachine(FullMetalAlchemist, 12, "Black");
	machine_array[3] = GatchaMachine(AttackOnTitan, 17, "Blue");
	machine_array[4] = GatchaMachine(Bleach, 10, "Orange");

	// CAPSULES
	Capsule* capsule_array[MAX_CAPSULES];

	// toys
	Toy toy0("Chiaotzu", Common, _Toy, "Orange", DragonBallZ);
	Toy toy1("Son Goku", Legendary, _Toy, "Yellow", DragonBallZ);
	Toy toy2("Bulma", Legendary, _Toy, "Blue", DragonBallZ);
	Toy toy3("Krillin", Epic, _Toy, "Orange", DragonBallZ);
	Toy toy4("Piccolo", Epic, _Toy, "Green", DragonBallZ);
	Toy toy5("Naruto", Legendary, _Toy, "Yellow", Naruto);
	Toy toy6("Uzumaki", Legendary, _Toy, "Orange", Naruto);
	Toy toy7("Uchiha", Legendary, _Toy, "Blue", Naruto);
	Toy toy8("Haruno", Legendary, _Toy, "Black", Naruto);
	Toy toy9("Sakura", Epic, _Toy, "Red", Naruto);
	Toy toy10("Pikachu", Legendary, _Toy, "Orange", Pokemon);
	Toy toy11("Cosmog", Legendary, _Toy, "Yellow", Pokemon);
	Toy toy12("Swablu", Epic, _Toy, "Black", Pokemon);
	Toy toy13("Jigglypuff", Epic, _Toy, "Green", Pokemon);
	Toy toy14("Charmander", Rare, _Toy, "Blue", Pokemon);
	Toy toy15("Eren Jaeger", Legendary, _Toy, "Orange", AttackOnTitan);
	Toy toy16("Mikasa Ackerman", Epic, _Toy, "Black", AttackOnTitan);
	Toy toy17("Armin Arlert", Epic, _Toy, "Yellow", AttackOnTitan);
	Toy toy18("Sasha Brausr", Rare, _Toy, "Blue", AttackOnTitan);
	Toy toy19("Erwin Smith", Rare, _Toy, "Red", AttackOnTitan);
	Toy toy20("Kurosaki", Legendary, _Toy, "Orange", Bleach);
	Toy toy21("Kuchiki", Epic, _Toy, "Blue", Bleach);
	Toy toy22("Inoue", Rare, _Toy, "Red", Bleach);
	Toy toy23("Abarai", Common, _Toy, "Black", Bleach);
	Toy toy24("Ishida", Common, _Toy, "Green", Bleach);
	Toy toy25("Becky", Legendary, _Toy, "Green", SpyXFamily);
	Toy toy26("Yuri", Rare, _Toy, "Blue", SpyXFamily);
	Toy toy27("Damian", Rare, _Toy, "Black", SpyXFamily);
	Toy toy28("Franky", Common, _Toy, "Green", SpyXFamily);
	Toy toy29("Henry", Common, _Toy, "Orange", SpyXFamily);
	Toy toy30("Alphonse", Epic, _Toy, "Black", FullMetalAlchemist);
	Toy toy31("Mustang", Epic, _Toy, "Blue", FullMetalAlchemist);
	Toy toy32("Rockbell", Rare, _Toy, "Orange", FullMetalAlchemist);
	Toy toy33("Scar", Common, _Toy, "Red", FullMetalAlchemist);
	Toy toy34("Chang", Common, _Toy, "Orange", FullMetalAlchemist);

	//candies
	Candy candy1("Air Heads", Rare, _Candy, "Yellow", "peach");
	Candy candy2("Bubble", Epic, _Candy, "Yellow", "Strawberry");
	Candy candy3("Jelly", Common, _Candy, "Red", "Grape");
	Candy candy4("Kit Kat", Legendary, _Candy, "Red", "Chocolate");
	Candy candy5("Skittles", Common, _Candy, "Red", "Sour");
	Candy candy6("M&M's", Common, _Candy, "Black", "Butter");
	Candy candy7("Starburst", Rare, _Candy, "Black", "Grape");
	Candy candy8("Snickers", Common, _Candy, "Black", "Chocolate");
	Candy candy9("Hershey", Epic, _Candy, "Blue", "Chocolate");
	Candy candy10("Candy corn", Common, _Candy, "Blue", "Corn");
	Candy candy11("Bazooka", Rare, _Candy, "Blue", "Strawberry");
	Candy candy12("Caramel", Common, _Candy, "Blue", "Caramel");
	Candy candy13("Chocolate", Epic, _Candy, "Orange", "Chocolate");
	Candy candy14("Loly Pop", Common, _Candy, "Orange", "Lemon");
	Candy candy15("Oreo", Legendary, _Candy, "Orange", "Chocolate");
	
	capsule_array[0] = &toy0;
	capsule_array[1] = &toy1;
	capsule_array[2] = &toy2;
	capsule_array[3] = &toy3;
	capsule_array[4] = &toy4;
	capsule_array[5] = &toy5;
	capsule_array[6] = &toy6;
	capsule_array[7] = &toy7;
	capsule_array[8] = &toy8;
	capsule_array[9] = &toy9;
	capsule_array[10] = &toy10;
	capsule_array[11] = &toy11;
	capsule_array[12] = &toy12;
	capsule_array[13] = &toy13;
	capsule_array[14] = &toy14;
	capsule_array[15] = &toy15;
	capsule_array[16] = &toy16;
	capsule_array[17] = &toy17;
	capsule_array[18] = &toy18;
	capsule_array[19] = &toy19;
	capsule_array[20] = &toy20;
	capsule_array[21] = &toy21;
	capsule_array[22] = &toy22;
	capsule_array[23] = &toy23;
	capsule_array[24] = &toy24;
	capsule_array[25] = &toy25;
	capsule_array[26] = &toy26;
	capsule_array[27] = &toy27;
	capsule_array[28] = &toy28;
	capsule_array[29] = &toy29;
	capsule_array[30] = &toy30;
	capsule_array[31] = &toy31;
	capsule_array[32] = &toy32;
	capsule_array[33] = &toy33;
	capsule_array[34] = &toy34;
	capsule_array[35] = &candy1;
	capsule_array[36] = &candy2;
	capsule_array[37] = &candy3;
	capsule_array[38] = &candy4;
	capsule_array[39] = &candy5;
	capsule_array[40] = &candy6;
	capsule_array[41] = &candy7;
	capsule_array[42] = &candy8;
	capsule_array[43] = &candy9;
	capsule_array[44] = &candy10;
	capsule_array[45] = &candy11;
	capsule_array[46] = &candy12;
	capsule_array[47] = &candy13;
	capsule_array[48] = &candy14;
	capsule_array[49] = &candy15;

	SortCapsulesToMachines(machine_array, capsule_array);

	int choose = 0;
	int player_money = player.GetMoney();
	int cheapest = FindCheapestMachineCost(machine_array);
	while (CheckIfGameContinues(player_money, cheapest))
	{
		std::cout << "\n-----------MENU:-----------\n"
			<< "1-Exit\n";
		int counter = 2;
		for (GatchaMachine machine : machine_array)
		{
			if (machine.GetTheme() != None)
			{
				std::cout << counter << "-" << theme_name_array[machine.GetTheme()] << " Price:" << machine.GetPrice() << std::endl;
				counter++;
			}
		}
		std::cout << ">";
		std::cin >> choose;
		if (choose == 1) return 0;
		else if (choose < counter && choose > 0)
		{
			player.PlayMachine(machine_array[choose - 2]);
			player_money = player.GetMoney();
		}
		else std::cout << "Invalid input. Please try again" << std::endl;
	}
	player.CalculateEarnings();
	return 0;
}