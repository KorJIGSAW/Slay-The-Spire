#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <fmod.h> //음악 재생 헤더파일
#include "console.h" //화면제어 헤더
#include "character.h" //캐릭터, 몬스터 상태창
#include "status.h" //전체 상태창
#include "card.h"
#include "draw.h"
#include "CSound.h" //음악 재생 헤더파일
#include "input.h" //값 입력 헤더

void StartGame() {
	int menucode;
	SetTitle("Slay the Spire"); //한자로 출력된다.
	FirstDraw();
	Music_Start();
	menucode = MenuDraw();
	if (menucode == 3) { //게임 종료
		//goto GameOver
		GameOverDraw();
		Sleep(37000); //GameOver.mp3의 노래 재생시간 37초동안 재생 후 종료
		exit(1);
	}
	else if (menucode == 2) { //카드 목록실행
		CardListDraw();
	}
	else if (menucode == 1) { //게임 설명실행
		PlayExampleDraw();
	}
	else if (menucode == 0) { //게임 시작실행
		
	}
}

int main() {
	//SetConsoleSize(120, 30);
	StartGame();
	
    Sleep(100000);
	system("pause");
}