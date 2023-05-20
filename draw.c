#include <stdio.h>
#include "console.h"
#include "draw.h"
#include "input.h"

void FirstDraw() {
	DrawMainTitle();
	DrawBox(120, 30);
}

void DrawMainTitle() {
	// 
	GotoXY(17, 5);
	printf("       _____  _                 _    _             _____         _              \n");
	GotoXY(17, 6);
	printf("      /  ___|| |               | |  | |           /  ___|       (_)             \n");
	GotoXY(17, 7);
	printf("      \\ `--. | |  __ _  _   _  | |_ | |__    ___  \\ `--.  _ __   _  _ __   ___  \n");
	GotoXY(17, 8);
	printf("       `--. \\| | / _` || | | | | __|| '_ \\  / _ \\  `--. \\| '_ \\ | || '__| / _ \\ \n");
	GotoXY(17, 9);
	printf("      /\\__/ /| || (_| || |_| | | |_ | | | ||  __/ /\\__/ /| |_) || || |   |  __/ \n");
	GotoXY(17, 10);
	printf("      \\____/ |_| \\__,_| \\__, |  \\__||_| |_| \\___| \\____/ | .__/ |_||_|    \\___| \n");
	GotoXY(17, 11);
	printf("                         __/ |                           | |                    \n");
	GotoXY(17, 12);
	printf("                        |___/                            |_|                    \n");

	/*임시 제목
	printf("░██████╗██╗░░░░░░█████╗░██╗░░░██╗  ████████╗██╗░░██╗███████╗  ░██████╗██████╗░██╗██████╗░███████╗\n");
	printf("██╔════╝██║░░░░░██╔══██╗╚██╗░██╔╝  ╚══██╔══╝██║░░██║██╔════╝  ██╔════╝██╔══██╗██║██╔══██╗██╔════╝\n");
	printf("╚█████╗░██║░░░░░███████║░╚████╔╝░  ░░░██║░░░███████║█████╗░░  ╚█████╗░██████╔╝██║██████╔╝█████╗░░\n");
	printf("░╚═══██╗██║░░░░░██╔══██║░░╚██╔╝░░  ░░░██║░░░██╔══██║██╔══╝░░  ░╚═══██╗██╔═══╝░██║██╔══██╗██╔══╝░░\n");
	printf("██████╔╝███████╗██║░░██║░░░██║░░░  ░░░██║░░░██║░░██║███████╗  ██████╔╝██║░░░░░██║██║░░██║███████╗\n");
	printf("╚═════╝░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░  ░░░╚═╝░░░╚═╝░░╚═╝╚══════╝  ╚═════╝░╚═╝░░░░░╚═╝╚═╝░░╚═╝╚══════╝\n");
	*/
	
}
void DrawBox(int width, int height) {
	int i, j;

	// Top border
	GotoXY(1, 1);
	printf("┌");
	for (i = 3; i < width - 1; i+=2) {
		printf("─");
	}
	printf("┐");

	// Middle rows
	for (i = 2; i < height - 1; i++) {
		GotoXY(1, i);
		printf("│");
		GotoXY(width-1, i);
		printf("│");
	}

	// Bottom border
	GotoXY(1, height-1);
	printf("└");
	for (i = 3; i < width - 1; i+=2) {
		printf("─");
	}
	printf("┘");
}



int MenuDraw()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int mode = 0;
	int n = 0;
	StartMenuDraw(hConsole);

	// 키보드 입력을 기다리는 부분
	// 스페이스바가 입력되면 return하여 빠져나감
	while (1)
	{
		n = 0;
		//키보드 이벤트를 키값으로 받아오기
		n = menuControl();

		switch (n)
		{

			case DOWN:
			{
				//PlaySoundEffect(SOUND_SELECT);

				if (mode == 0)
				{
					TutorialDraw(hConsole);
					mode = 1;
				}
				else if (mode == 1)
				{
					ShowCardMenuDraw(hConsole);
					mode = 2;
				}
				else if (mode == 2) {
					ExitMenuDraw(hConsole);
					mode = 3;
				}
				break;
			}

			case UP:
			{
				//PlaySoundEffect(SOUND_SELECT);

				if (mode == 4) {
					ExitMenuDraw(hConsole);
					mode = 3;
				}
				else if (mode == 3) {
					ShowCardMenuDraw(hConsole);
					mode = 2;
				}
				else if (mode == 2)
				{
					TutorialDraw(hConsole);
					mode = 1;
				}

				else if (mode == 1)
				{
					StartMenuDraw(hConsole);
					mode = 0;
				}
				break;
			}

			case SPACE:
			{
				//PlaySoundEffect(SOUND_CLICK);
				// 스페이스바(선택)되었을 경우
				return mode;
			}
		}
	}
}

void StartMenuDraw(HANDLE hConsole) //메뉴창 드로우 첫 세팅선택지는 새로하기.
{
	GotoXY(55, 20);

	SET_GREEN  printf("▶ 게임 하기");
	GotoXY(55, 22);
	SET_YELLOW printf("   게임 설명");
	GotoXY(55, 24);
	SET_YELLOW printf("   카드 목록");
	GotoXY(55, 26);
	SET_YELLOW printf("   게임 종료");

	SET_WHITE
}

void TutorialDraw(HANDLE hConsole)
{
	GotoXY(55, 20);

	SET_YELLOW  printf("   게임 하기");
	GotoXY(55, 22);
	SET_GREEN printf("▶ 게임 설명");
	GotoXY(55, 24);
	SET_YELLOW printf("   카드 목록");
	GotoXY(55, 26);
	SET_YELLOW printf("   게임 종료");

	SET_WHITE
}

void ShowCardMenuDraw(HANDLE hConsole) {
	GotoXY(55, 20);

	SET_YELLOW  printf("   게임 하기");
	GotoXY(55, 22);
	SET_YELLOW printf("   게임 설명");
	GotoXY(55, 24);
	SET_GREEN printf("▶ 카드 목록");
	GotoXY(55, 26);
	SET_YELLOW printf("   게임 종료");

	SET_WHITE
}

void ExitMenuDraw(HANDLE hConsole)
{
	GotoXY(55, 20);

	SET_YELLOW  printf("   게임 하기");
	GotoXY(55, 22);
	SET_YELLOW printf("   게임 설명");
	GotoXY(55, 24);
	SET_YELLOW printf("   카드 목록");
	GotoXY(55, 26);
	SET_GREEN printf("▶ 게임 종료");

	SET_WHITE
}


