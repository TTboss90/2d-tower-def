
#pragma once
#include "scenes/scenes.hpp"
#include <raylib.h>

enum class game_state
{
	playing,
	paused,
};

class game_scene : public scene
{
public:
	game_scene();
	~game_scene() override;
	void run() override;

private:
	void Default();

	void handle_paused();

	void handle_playing();


	Camera2D m_camera{ 0 };


	game_state m_state = game_state::playing;

	bool m_exit = false;
};