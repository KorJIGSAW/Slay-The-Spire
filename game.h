#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include "status.h"
#include "character.h"

INFORMATION Info;
MyCharacter Player;
EnemyCharacter Enemy;


void SetGame();
void DrawMyCharacter();
void DrawEnemyCharacter();

#endif // !GAME_H
