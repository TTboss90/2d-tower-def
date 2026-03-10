
#pragma once
#include <raylib.h>


struct button
{
	Rectangle rect{ 0 };
	std::function<void()> on_click;
	std::string label;
};