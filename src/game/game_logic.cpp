#include "scenes/game_scene.hpp"
#include "scenes/menu_scene.hpp"
#include <raymath.h>
#include <raygui.h>

//handles the default state, just draws some text on the screen
void game_scene::Default()
{
	BeginMode2D(m_camera);

	DrawText("Game Scene", 10, 10, 40, RED);

	EndMode2D();
}