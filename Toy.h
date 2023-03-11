#pragma once
#include "Capsule.h"

class Toy :
    public Figure,
    public Capsule
{
public:
    Toy();
    Toy(std::string name, Rarity rarity, CapType type, std::string color, Series theme);
    ~Toy() {}
private:
};

