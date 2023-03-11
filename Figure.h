#pragma once
#include <iostream>
#include "Enums.h"

class Figure
{
public:
	Figure();
	Figure(Series theme);
	virtual ~Figure() = 0 {}
	virtual Series GetCategory() {return m_theme;}
private:
	Series m_theme;
};

