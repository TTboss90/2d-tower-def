#include "scenes/game_scene.hpp"
#include "scenes/menu_scene.hpp"
#include <raymath.h>
#include <raygui.h>

constexpr float zoom_speed = 0.1f;

// Handles the default state, draws the tile map to the screen
void game_scene::Default()
{
    BeginMode2D(m_camera);

    for (int y = 0; y < map_h; y++)
    {
        for (int x = 0; x < map_w; x++)
        {
            int tilesPerRow = m_tile_texture.width / tile_size;
            int tilesPerColumn = m_tile_texture.height / tile_size;

            int tileID = m_map[y * map_w + x]; 

            if (tileID < 0 || tileID >= tilesPerRow * tilesPerColumn) {
                continue; 
            }

            int srcX = (tileID % tilesPerRow) * tile_size;
            int srcY = (tileID / tilesPerRow) * tile_size;

            Rectangle source = { srcX, srcY, tile_size, tile_size };

            Rectangle dest = { x * tile_size, y * tile_size, tile_size, tile_size };

            DrawTexturePro(m_tile_texture, source, dest, Vector2{ 0, 0 }, 0.0f, WHITE);
        }
    }

    EndMode2D();
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

    float wheel = GetMouseWheelMove();
    if (wheel != 0)
    {
        Vector2 mouseWorldBefore = GetScreenToWorld2D(GetMousePosition(), m_camera);

        m_camera.zoom *= (1.0f + wheel * zoom_speed);

        if (m_camera.zoom < 0.1f) m_camera.zoom = 0.1f;
        if (m_camera.zoom > 5.0f) m_camera.zoom = 5.0f;

        Vector2 mouseWorldAfter = GetScreenToWorld2D(GetMousePosition(), m_camera);

        Vector2 delta = Vector2Subtract(mouseWorldBefore, mouseWorldAfter);
        m_camera.target = Vector2Add(m_camera.target, delta);
    }
}