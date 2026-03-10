
#include "2d_tower_def.hpp"
#include "scenes/menu_scene.hpp"

tower_def::tower_def()
{
	constexpr int DESIGN_WIDTH = 1920;
	constexpr int DESIGN_HEIGHT = 1080;

	SetConfigFlags(FLAG_VSYNC_HINT);

	InitWindow(DESIGN_WIDTH, DESIGN_HEIGHT, "2D Tower Defense Game");

	//SetExitKey(KEY_NULL);

	ToggleFullscreen();
}

void tower_def::run()
{
	m_scene = std::make_unique<main_menu>();

	while (!WindowShouldClose() && !m_scene->exit)
	{
		m_scene->update();

		if (m_scene->next_scene) {
			m_scene = std::move(m_scene->next_scene);
		}

		BeginDrawing();
		ClearBackground(RAYWHITE);

		m_scene->draw_scene();

		EndDrawing();
	}
}

tower_def::~tower_def()
{
	CloseWindow();
}

int main() {
	tower_def tower_def_game;
	tower_def_game.run();

	return 0;
}