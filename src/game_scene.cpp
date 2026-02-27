#include "game_scene.hpp"
#include "menu_scene.hpp"

game_scene::game_scene()
{
	m_camera.target = { 0, 0 };
	m_camera.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	m_camera.rotation = 0.0f;
	m_camera.zoom = 1;
}

void game_scene::update()
{
	if (IsKeyPressed(KEY_K))
		next_scene = std::make_unique<main_menu>();

	float dt = GetFrameTime();
	const float camera_speed = 50.0f;
	if (IsKeyDown(KEY_W)) {
		m_camera.target.y -= camera_speed * dt;
	}
	if (IsKeyDown(KEY_S)) {
		m_camera.target.y += camera_speed * dt;
	}
	if (IsKeyDown(KEY_A)) {
		m_camera.target.x -= camera_speed * dt;
	}
	if (IsKeyDown(KEY_D)) {
		m_camera.target.x += camera_speed * dt;
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