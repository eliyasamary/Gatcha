#pragma once
#include "Capsule.h"
class Candy :
    public Edible,
    public Capsule
{
public:
    Candy() {}
    Candy(std::string name, Rarity rarity, CapType type, std::string color, std::string flavor);
    ~Candy() {}

private:
};

