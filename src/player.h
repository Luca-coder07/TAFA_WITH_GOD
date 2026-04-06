#ifndef PLAYER_H
#define PLAYER_H

#include "tafa.h"

void InitPlayer(t_player *player);
void UpdatePlayer(t_player *player, float dt);
void DrawPlayer(t_player player);
void UnloadPlayer(t_player *player);

#endif
