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
#include "game.h"

void StartGame() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetCursorVisible(0);
	int menucode;
	SetTitle(TEXT("Slay the Spire.exe")); //한자 문제 해결완료
	Music_Start();
MainMonitor:
	FirstDraw();
	menucode = MenuDraw();
	if (menucode == 3) { //게임 종료
		//goto GameOver
		StopSound();
		Music_GameOver();
		GameOverDraw();
		Sleep(37000); //GameOver.mp3의 노래 재생시간 37초동안 재생 후 종료
		exit(1);
	}
	else if (menucode == 2) { //카드 목록실행
		CardListDraw();
		SET_GREEN
		printf("R을 누르시면 메인화면으로 돌아갑니다.");
		SET_WHITE
		while (1) { //메인화면으로 돌아가기.
			if (kbhit())
			{
				char temp = getch();
				if (temp == 'R' || temp == 'r')
				{
					Music_Select();
					//system("cls");
					Clear();
					goto MainMonitor;
				}
			}
		}
	}
	else if (menucode == 1) { //게임 설명실행
	Example1:
		PlayExampleDraw1(hConsole);
		while (1) {
			if (kbhit())
			{
				char temp = getch();
				if (temp == 'R' || temp == 'r') //메인화면으로 돌아가기.
				{
					Music_Select();
					//system("cls");
					Clear();
					goto MainMonitor;
				}
				else if (temp == 'N' || temp == 'n') { // 다음 듀토리얼 보기
					Music_Select();
					//system("cls");
					Clear();
					goto Example2;
					break;
				}
				else if (temp == 'D' || temp == 'd') { //자신의 카드덱 확인
					Music_Select();
					//system("cls");
					Clear();
					break;
					//자신의 카드덱 프린트함수
				}
			}
		}
	Example2:
		PlayExampleDraw2(hConsole);
		while (1) {
			if (kbhit())
			{
				char temp = getch();
				if (temp == 'B' || temp == 'b') //이전화면으로 돌아가기.
				{
					Music_Select();
					//system("cls");
					Clear();
					goto Example1; //2번째 설명 -> 1번째 설명 돌아가기
					break;
				}
				else if (temp == 'R' || temp == 'r') //메인화면으로 돌아가기.
				{
					Music_Select();
					//system("cls");
					Clear();
					goto MainMonitor;
				}
				else if (temp == 'N' || temp == 'n') { // 다음 듀토리얼 보기
					Music_Select();
					//system("cls");
					Clear();
					goto Example3;
					break;
				}
				else if (temp == 'D' || temp == 'd') { //자신의 카드덱 확인
					Music_Select();
					//system("cls");
					Clear();
					break;
					//자신의 카드덱 프린트함수
				}
			}
		}
	Example3:
		PlayExampleDraw3(hConsole); 
		while (1) {
			if (kbhit())
			{
				char temp = getch();
				if (temp == 'B' || temp == 'b'){ //이전화면으로 돌아가기
					Music_Select();
					//system("cls");
					Clear();
					goto Example2; //3번째 설명 -> 2번째 설명 돌아가기
					break;
				}
				else if (temp == 'R' || temp == 'r') //메인화면으로 돌아가기.
				{
					Music_Select();
					//system("cls");
					Clear();
					goto MainMonitor;
				}
				else if (temp == 'D' || temp == 'd') { //자신의 카드덱 확인
					Music_Select();
					//system("cls");
					Clear();
					break;
					//자신의 카드덱 프린트함수
				}
			}
		}
	}
	else if (menucode == 0) { //게임 시작실행
		SetGame();
	}
}

int main() {
	//SetConsoleSize(120, 30);
	StartGame();
	
    Sleep(100000);
	//system("pause");
	Clear();
}