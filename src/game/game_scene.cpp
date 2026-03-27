#include "scenes/game_scene.hpp"
#include "scenes/menu_scene.hpp"
#include <raymath.h>
#include <raygui.h>

//constructor, initializes the camera
game_scene::game_scene()
{
	m_camera.target = { 0, 0 };
	m_camera.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	m_camera.rotation = 0.0f;
	m_camera.zoom = 1;
}

//handles the default state, just draws some text on the screen
void game_scene::Default()
{
	BeginMode2D(m_camera);

	DrawText("Game Scene", 10, 10, 40, RED);

	EndMode2D();
}

//handles the paused state, checks if the button is clicked
void game_scene::handle_paused() 
{
	BeginBlendMode(2); // 4 for inverse blending, 2 makes it darker
	
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), GRAY);

	EndBlendMode();

	if (GuiButton(Rectangle{100,100,100,100},"hi")) {
	
	}
}

//handles the playing state, checks if the left mouse button is down and moves the camera target based on the mouse delta
void game_scene::handle_playing() 
{
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		Vector2 delta = GetMouseDelta();
		delta = Vector2Scale(delta, -1.0f / m_camera.zoom);
		m_camera.target = Vector2Add(m_camera.target, delta);
	}
}

//runs the game scene, checks the current game state and runs the corresponding functions, also checks if there is a next scene to switch to
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