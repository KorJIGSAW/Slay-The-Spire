#ifndef DRAW_H
#define DRAW_H

#include <stdio.h>
#include "console.h"

#define SET_GREEN SetConsoleTextAttribute(hConsole, 10);
#define SET_YELLOW SetConsoleTextAttribute(hConsole, 14);
#define SET_WHITE SetConsoleTextAttribute(hConsole, 15);


void FirstDraw();
void DrawMainTitle();
void DrawBox(int width, int height);	
int MenuDraw();
void StartMenuDraw(HANDLE hConsole);
void ShowCardMenuDraw(HANDLE hConsole);
void TutorialDraw(HANDLE hConsole);
void ExitMenuDraw(HANDLE hConsole);

#endif // !DRAW_H