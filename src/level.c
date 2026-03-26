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
}

void UnloadLevel(t_level *level)
{
    (void)level;
}
