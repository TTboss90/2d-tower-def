#include "scenes/game_scene.hpp"
#include "scenes/menu_scene.hpp"
#include <raymath.h>
#include <raygui.h>

//constructor, initializes the camera
game_scene::game_scene(int w, int h, const char* tile_map_file) :
	map_h{ h },
	map_w{ w }
{
	m_camera.target = { 0, 0 };
	m_camera.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	m_camera.rotation = 0.0f;
	m_camera.zoom = 1;

	m_volume = GetMasterVolume() * 100;

	m_volume_slider.width = 300;
	m_volume_slider.height = 50;
	m_volume_slider.x = ((int)GetRenderWidth() / 2) - ((int)m_volume_slider.width / 2);
	m_volume_slider.y = 150;

	m_map = std::make_unique<uint8_t[]>(w * h);

	tile_size = 32;

	uint8_t temp[] =
	{
		1,1,1,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,1,1,
	};

	std::copy(std::begin(temp), std::end(temp), m_map.get());

	m_tile_texture = LoadTexture(tile_map_file);
}

//handles the paused state, checks if the button is clicked
void game_scene::handle_paused() 
{
	BeginBlendMode(2); // 4 for inverse blending, 2 makes it darker
	
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), GRAY);

	EndBlendMode();

	game_menu();
}

//runs the game scene, checks the current game state and runs the corresponding functions, also checks if there is a next scene to switch to
void game_scene::run()
{
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawFPS(10, 10);

		float dt = GetFrameTime();

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

		if (m_exit) {
			break;
		}
	}
}

game_scene::~game_scene() 
{
	UnloadTexture(m_tile_texture);
}