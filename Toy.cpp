#include "Toy.h"

/*-------------------------------------------------------------------------------*/
Toy::Toy()
    :
    Capsule(),
    Figure()
    {}
/*-------------------------------------------------------------------------------*/
Toy::Toy(std::string name, Rarity rarity, CapType type, std::string color, Series theme)
    :
    Capsule(name, rarity, type, color),
    Figure(theme)
    {}
/*-------------------------------------------------------------------------------*/
