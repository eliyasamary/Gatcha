#include "Candy.h"

/*-------------------------------------------------------------------------------*/
Candy::Candy(std::string name, Rarity rarity, CapType type, std::string color, std::string flavor)
    :
    Capsule(name, rarity, type, color),
    Edible(flavor)
    {}
