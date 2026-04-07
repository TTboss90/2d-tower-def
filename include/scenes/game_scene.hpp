
#pragma once
#include "scenes/scenes.hpp"
#include <raylib.h>

//game state enum, can be expanded in the future to include more states like game over, victory, etc.
enum class game_state
{
	playing,
	paused,
};

//game scene class, inherits from the base scene class, handles the main game logic and rendering
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

	void game_menu();


	Camera2D m_camera{ 0 };

	Rectangle m_volume_slider{ 0 };

	float m_volume;

	game_state m_state = game_state::playing;

	bool m_exit = false;
};