#include <stdio.h>
#include "input.h"
#include "CSound.h"
#include "windows.h"

/// 메뉴 조작
int menuControl()
{
	if (_kbhit())
	{
		char temp = _getch();
		if (temp == -32)
		{
			char temp = _getch();
			if (temp == 72)			return UP;
			else if (temp == 75)	return LEFT;
			else if (temp == 80)	return DOWN;
			else if (temp == 77)	return RIGHT;
		}
		if (temp == ' ') { Music_Select(); Sleep(1000);	return SPACE; }
	}
}