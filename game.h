#ifndef GAME_H
#define GAME_H
#include <stdio.h>

void SetGame();
void DrawMyCharacter();
void DrawEnemyCharacter();
void UseCard(int num);
void Update_Round();
void Enemy_Set();
void Enemy_Set_Zero();
void Enemy_Pattern_Set();
void RanPick_Enemy_Pattern(int stair);

#endif // !GAME_H
