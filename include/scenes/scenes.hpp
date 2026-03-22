
#pragma once
#include <memory>

//base scene class
class scene
{
public:
	scene() = default;
	virtual ~scene() = default;

	virtual void run() = 0;

	std::unique_ptr<scene> next_scene{ nullptr };

private:
};