
#include "2d_tower_def.hpp"
#include <iostream>

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

main_menu::main_menu()
{
	int i = 0;
	for (button& the_button : m_buttons) {
		i++;
		the_button.rect.width = 200;
		the_button.rect.height = 100;
		the_button.rect.x = ((int)GetRenderWidth() / 2) - ((int)the_button.rect.width / 2);
		the_button.rect.y = i * 150;

		the_button.label = "Button  " + std::to_string(i);

		switch (i)
		{
		case 1:
			the_button.label = "Play";
			the_button.on_click = [this, i]() {
				std::cout << "Play" << std::endl;
				m_buttons[i - 1].label = "Playing...";
				};
			break;
		case 2:
			the_button.on_click = [this, i]() {
				std::cout << "Button 2 Clicked!" << std::endl;
				m_click_count++;
				m_buttons[i-1].label = "clickt " + std::to_string(m_click_count) + " times";
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
				next_scene = std::make_unique<game_scene>();
				};
			break;
		case 5:
			the_button.label = "Exit";
			the_button.on_click = [this]() {
				std::cout << "Button 5 Clicked!" << std::endl;
				exit = true;
				};
			break;
		default:
			break;
		}
	}
}

void main_menu::update()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		Vector2 mouse_pos = GetMousePosition();
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

	for (button& the_button : m_buttons)
	{
		DrawRectangleRec(the_button.rect, BLUE);
		int fontSize = 30;
		int textWidth = MeasureText(the_button.label.c_str(), fontSize);

		float textX = the_button.rect.x + (the_button.rect.width - textWidth) / 2.0f;
		float textY = the_button.rect.y + (the_button.rect.height - fontSize) / 2.0f;

		DrawText(the_button.label.c_str(), textX, textY, fontSize, BLACK);

	}
}

main_menu::~main_menu() {}

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

int main() {
	tower_def tower_def_game;
	tower_def_game.run();

	return 0;
}