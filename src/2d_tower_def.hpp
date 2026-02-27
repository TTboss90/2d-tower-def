
#pragma once
#include "scenes.hpp"
#include <raylib.h>
#include <array>
#include <functional>
#include <string>
#include <memory>

struct button
{
	Rectangle rect{ 0 };
	std::function<void()> on_click;
	std::string label;
};

class tower_def
{
public:
	tower_def();
	~tower_def();
	void run();

private:

	std::unique_ptr<scene> m_scene{ nullptr };
};