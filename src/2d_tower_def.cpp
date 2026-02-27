
#include "2d_tower_def.hpp"
#include <iostream>

main_menu::main_menu()
{
	m_camera.target = { 0, 0 };
	m_camera.offset = { 0, 0 };
	m_camera.rotation = 0.0f;
	m_camera.zoom = 1;

	int i = 0;
	for (button& the_button : m_buttons) {
		i++;
		the_button.rect.width = 200;
		the_button.rect.height = 100;
		the_button.rect.x = ((int)GetRenderWidth() / 2) - ((int)the_button.rect.width / 2);
		the_button.rect.y = i * 150;

		the_button.label = "Button  " + std::to_string(i);

		static int click_count = 0;

		switch (i)
		{
		case 1:
			the_button.label = "Play";
			the_button.on_click = [this, &the_button]() {
				std::cout << "Play" << std::endl;
				the_button.label = "Playing...";


				};
			break;
		case 2:
			the_button.on_click = [this, &the_button]() {
				std::cout << "Button 2 Clicked!" << std::endl;
				click_count++;
				the_button.label = "clickt " + std::to_string(click_count) + " times";
				};
			break;
		case 3:
			the_button.on_click = [this]() {
				std::cout << "Button 3 Clicked!" << std::endl;
				};
			break;
		case 4:
			the_button.on_click = [this]() {
				std::cout << "Button 4 Clicked!" << std::endl;
				};
			break;
		case 5:
			the_button.label = "Exit";
			the_button.on_click = [this]() {
				std::cout << "Button 5 Clicked!" << std::endl;
				CloseWindow();
				};
			break;
		default:
			break;
		}
	}
}

void main_menu::update()
{
	m_dt = GetFrameTime();
	const float camera_speed = 50.0f;
	if (IsKeyDown(KEY_W)) {
		m_camera.target.y -= camera_speed * m_dt;
	}
	if (IsKeyDown(KEY_S)) {
		m_camera.target.y += camera_speed * m_dt;
	}
	if (IsKeyDown(KEY_A)) {
		m_camera.target.x -= camera_speed * m_dt;
	}
	if (IsKeyDown(KEY_D)) {
		m_camera.target.x += camera_speed * m_dt;
	}
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		Vector2 mouse_pos = GetScreenToWorld2D(GetMousePosition(), m_camera);
		for (button& the_button : m_buttons) {
			if (CheckCollisionPointRec(mouse_pos, the_button.rect)) {
				the_button.on_click();
			}
		}
	}
}

void main_menu::draw_scene()
{
	DrawFPS(10, 10);

	BeginMode2D(m_camera);

	for (button& the_button : m_buttons) 
	{
		DrawRectangleRec(the_button.rect, BLUE);
		int fontSize = 30;
		int textWidth = MeasureText(the_button.label.c_str(), fontSize);

		float textX = the_button.rect.x + (the_button.rect.width - textWidth) / 2.0f;
		float textY = the_button.rect.y + (the_button.rect.height - fontSize) / 2.0f;

		DrawText(the_button.label.c_str(), textX, textY, fontSize, BLACK);

	}

	EndMode2D();
}

tower_def::tower_def()
{
	constexpr int DESIGN_WIDTH = 1920;
	constexpr int DESIGN_HEIGHT = 1080;

	SetConfigFlags(FLAG_VSYNC_HINT);

	InitWindow(DESIGN_WIDTH, DESIGN_HEIGHT, "2D Tower Defense Game");

	TraceLog(LOG_INFO, "Raylib version: %s", RAYLIB_VERSION);


	//SetExitKey(KEY_NULL);

	ToggleFullscreen();
}

void tower_def::run()
{
	m_scene = std::make_unique<main_menu>();

	while (true)
	{
		m_scene->update();
		if (WindowShouldClose())
			break;

		BeginDrawing();
			ClearBackground(RAYWHITE);

			m_scene->draw_scene();

		EndDrawing();
	}
}

tower_def::~tower_def() {}

int main() {
	tower_def tower_def_game;
	tower_def_game.run();

	return 0;
}