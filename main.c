#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include "console.h" //화면제어 헤더
#include "character.h" //캐릭터, 몬스터 상태창
#include "status.h" //전체 상태창
#include "card.h"
#include "draw.h"





int main() {
	//SetConsoleSize(120, 30);
	FirstDraw();
    Sleep(100000);
	system("pause");

}