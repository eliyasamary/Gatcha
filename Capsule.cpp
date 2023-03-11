#include "Capsule.h"
/*-------------------------------------------------------------------------------*/
Capsule::Capsule()
    :
    m_name(""),
    m_rarity(Common),
    m_type(),
    m_worth(0)
    {}
/*-------------------------------------------------------------------------------*/
Capsule::Capsule(std::string name, Rarity rarity, CapType type, std::string color)
    :
    m_name(name),
    m_rarity(rarity),
    m_type(type),
    ShellColor(color) // color
    {}

/*-------------------------------------------------------------------------------*/
void Capsule::CalculateWorth(int machine_cost)
{
    switch (m_rarity)
    {
    case Common:
        m_worth = machine_cost * 0.25;
        break;
    case Rare:
        m_worth = machine_cost * 0.5;
        break;
    case Epic:
        m_worth = machine_cost;
        break;
    case Legendary:
        m_worth = machine_cost * 1.5;
        break;
    }
}
/*-------------------------------------------------------------------------------*/
