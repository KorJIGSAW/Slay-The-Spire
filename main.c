#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include "console.h"
#include "cal_damage.h"
#include "character.h"

typedef struct MyCharacter {
	int hp; //내 체력
	int power; //힘을 얻었을 때
	int shield; //내 방어도
}MyCharacter;

typedef struct EnemyCharacter {
	int hp;
	int power;
	int shield;
}EnemyCharacter;


int main() {
	SetConsoleSize(30, 30);
	system("pause");
	return 0;
}