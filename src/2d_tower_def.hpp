
#pragma once
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

class scene
{
public:
	scene() = default;
	virtual ~scene() = default;
	
	virtual void draw_scene() = 0;
	virtual void update() = 0;

	std::unique_ptr<scene> next_scene{ nullptr };

	bool exit = false;

private:
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