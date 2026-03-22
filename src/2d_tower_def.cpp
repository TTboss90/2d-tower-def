
#include "2d_tower_def.hpp"
#include "scenes/menu_scene.hpp"

//constructor, initializes the window and audio device, and sets the game to fullscreen
tower_def::tower_def()
{
	constexpr int DESIGN_WIDTH = 1920;
	constexpr int DESIGN_HEIGHT = 1080;

	SetConfigFlags(FLAG_VSYNC_HINT);

	InitWindow(DESIGN_WIDTH, DESIGN_HEIGHT, "2D Tower Defense Game");

	InitAudioDevice();

	//SetExitKey(KEY_NULL);

	ToggleFullscreen();
}

//main game loop, runs the current scene and checks if there is a next scene to switch to
void tower_def::run()
{
	m_scene = std::make_unique<main_menu>();

	while (!WindowShouldClose())
	{
		m_scene->run();

		if (m_scene->next_scene) {
			m_scene = std::move(m_scene->next_scene);
		}
		else{
			break;
		}
	}
}

//destructor, closes the window
tower_def::~tower_def()
{
	CloseWindow();
}

//just makes the game class and runs it
int main() {
	tower_def tower_def_game;
	tower_def_game.run();

	return 0;
}