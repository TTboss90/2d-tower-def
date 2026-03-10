
#pragma once
#include <raylib.h>
#include <functional>
#include <string>

struct button
{
	Rectangle rect{ 0 };
	std::function<void()> on_click;
	std::string label;
};