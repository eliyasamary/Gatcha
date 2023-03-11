#pragma once
#include <iostream>

class Edible
{
public:
	Edible();
	Edible(std::string flavor);
	virtual ~Edible() = 0 {}
	virtual std::string GetFlavor() { return m_flavor;}
	
private:
	std::string m_flavor;
};

