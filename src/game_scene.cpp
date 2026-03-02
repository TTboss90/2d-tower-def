#include "game_scene.hpp"
#include "menu_scene.hpp"
#include <raymath.h>

game_scene::game_scene()
{
	m_camera.target = { 0, 0 };
	m_camera.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	m_camera.rotation = 0.0f;
	m_camera.zoom = 1;
}

void game_scene::update()
{
	float dt = GetFrameTime();

	if (IsKeyPressed(KEY_K))
		next_scene = std::make_unique<main_menu>();

	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		Vector2 delta = GetMouseDelta();
		delta = Vector2Scale(delta, -1.0f / m_camera.zoom);
		m_camera.target = Vector2Add(m_camera.target, delta);
	}
}

void game_scene::draw_scene()
{
	DrawFPS(10, 10);

	BeginMode2D(m_camera);

	DrawText("Game Scene", 10, 10, 40, RED);

	EndMode2D();
}

game_scene::~game_scene() {}