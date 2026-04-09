#include "scenes/game_scene.hpp"
#include "scenes/menu_scene.hpp"
#include <raymath.h>
#include <raygui.h>

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