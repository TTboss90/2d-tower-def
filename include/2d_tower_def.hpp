
#pragma once
#include "scenes/scenes.hpp"
#include <memory>

class tower_def
{
public:
	tower_def();
	~tower_def();
	void run();

private:

	std::unique_ptr<scene> m_scene{ nullptr };
};