#pragma once
#include <iostream>
#include "Enums.h"

class ShellColor
{
public:
	ShellColor();
	ShellColor(std::string color);
	virtual ~ShellColor() = 0 {}	// abstract
	std::string GetColor() const { return m_color; }
	void SetColor(std::string color) { m_color = color; }
private:
	std::string m_color;
};

