#include "scenes/game_scene.hpp"
#include "scenes/menu_scene.hpp"
#include <raymath.h>
#include <raygui.h>

game_scene::game_scene()
{
	m_camera.target = { 0, 0 };
	m_camera.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	m_camera.rotation = 0.0f;
	m_camera.zoom = 1;
}

void game_scene::Default()
{
	BeginMode2D(m_camera);

	DrawText("Game Scene", 10, 10, 40, RED);

	EndMode2D();
}

void game_scene::handle_paused() 
{
	if (GuiButton(Rectangle{100,100,100,100},"hi")) {
	
	}
}

void game_scene::handle_playing() 
{
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		Vector2 delta = GetMouseDelta();
		delta = Vector2Scale(delta, -1.0f / m_camera.zoom);
		m_camera.target = Vector2Add(m_camera.target, delta);
	}
}

void game_scene::run()
{
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawFPS(10, 10);

		float dt = GetFrameTime();

		if (IsKeyPressed(KEY_K)) {
			next_scene = std::make_unique<main_menu>();
			break;
		}

		if (IsKeyPressed(KEY_E)) {
			if (m_state == game_state::playing) {
				m_state = game_state::paused;
			}
			else if (m_state == game_state::paused) {
				m_state = game_state::playing;
			}
		}

		game_scene::Default();

		if (m_state == game_state::playing) {
			game_scene::handle_playing();
		}
		else if (m_state == game_state::paused) {
			game_scene::handle_paused();
		}

		EndDrawing();

		if (next_scene) {
			break;
		}
	}
}

game_scene::~game_scene() {}