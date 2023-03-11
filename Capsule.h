#pragma once
#include <iostream>
#include "Figure.h"
#include "Edible.h"
#include "ShellColor.h"

class Capsule :
    public ShellColor
{
public:
    Capsule();
    Capsule(std::string name, Rarity rarity, CapType type, std::string color);
    virtual ~Capsule() = 0 {} // abstract

    virtual void CalculateWorth(int machine_cost);
    virtual float GetWorth() { return m_worth; }
    CapType GetType() { return m_type; }
    std::string GetName() { return m_name; }
    Rarity GetRarity() { return m_rarity; }

private:
    std::string     m_name;
    Rarity          m_rarity;
    float           m_worth;
    CapType         m_type;
};

