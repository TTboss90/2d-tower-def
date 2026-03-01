
#pragma once
#include <memory>

class scene
{
public:
	scene() = default;
	virtual ~scene() = default;

	virtual void draw_scene() = 0;
	virtual void update() = 0;

protected:
	std::unique_ptr<scene> next_scene{ nullptr };

	bool exit = false;

private:
};