#ifndef DRAW_H
#define DRAW_H

#include <stdio.h>
#include "sts.h"

/*
#define SET_GREEN SetConsoleTextAttribute(hConsole, 10);
#define SET_YELLOW SetConsoleTextAttribute(hConsole, 14);
#define SET_WHITE SetConsoleTextAttribute(hConsole, 15);
*/

#define SET_GREEN SetColor(0, 2);
#define SET_YELLOW SetColor(0, 6);
#define SET_WHITE SetColor(0, 7);
#define SET_RED SetColor(0,4); 

void FirstDraw();
void DrawMainTitle();
void DrawBox(int width, int height);	
int MenuDraw();
void StartMenuDraw(HANDLE hConsole);
void ShowCardMenuDraw(HANDLE hConsole);
void TutorialDraw(HANDLE hConsole);
void ExitMenuDraw(HANDLE hConsole);
void MyCharacterDraw(HANDLE hConsole);
void EnemyCharacterDraw(HANDLE hConsole);
void GameOverDraw();
void CardListDraw();
void PlayExampleDraw1(HANDLE hConsole);
void CreatingCard();
void PlayExampleDraw2(HANDLE hConsole);
void PlayExampleDraw3(HANDLE hConsole);
void DrawCard(int value, int count);

#endif // !DRAW_H