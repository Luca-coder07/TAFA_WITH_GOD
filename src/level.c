#include "level.h"

void LoadLevel(t_level *level, SubGameScreen levelType)
{
    level->type = levelType;
    level->name = "Level";
}

void UpdateLevel(t_level *level, float dt)
{
    (void)level;
    (void)dt;
}

void DrawLevel(t_level *level)
{
    (void)level;
    DrawRectangle(0, screen_height * 0.9, screen_width, screen_height, GRAY);
    DrawLineEx((Vector2){0, screen_height * 0.9}, (Vector2){screen_width, screen_height * 0.9}, 4, BLACK);
}

void UnloadLevel(t_level *level)
{
    (void)level;
}
