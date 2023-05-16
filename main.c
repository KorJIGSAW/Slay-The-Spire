#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include "console.h" //화면제어 헤더
#include "cal_damage.h" //데미지 계산및 처리헤더
#include "character.h" //캐릭터, 몬스터 상태창
#include "status.h" //전체 상태창
#include "card.h"

void DrawBox(int width, int height) //120,30 게임 화면 체크용 함수
{
    int i, j;

    // Top border
    printf("┌");
    for (i = 1; i < width - 1; i++)
    {
        printf("─");
    }
    printf("┐\n");

    // Middle rows
    for (i = 0; i < height - 2; i++)
    {
        printf("│");
        for (j = 1; j < width - 1; j++)
        {
            printf(" ");
        }
        printf("│\n");
    }

    // Bottom border
    printf("└");
    for (i = 1; i < width - 1; i++)
    {
        printf("─");
    }
    printf("┘\n");
}



int main() {
	//SetConsoleSize(120, 30);
    DrawBox(120, 30);
	system("pause");
	//return 0;
}