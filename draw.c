#include <stdio.h>
#include "console.h"
#include "draw.h"
#include "input.h"
#include "data.h"
#include "CSound.h"

void FirstDraw() {
	DrawMainTitle();
	DrawBox(120, 30);
}

void DrawMainTitle() {
	// 
	GotoXY(17, 5);
	printf("       _____  _                   _    _               _____         _              \n");
	GotoXY(17, 6);
	printf("      /  ___|| |                 | |  | |             /  ___|       (_)             \n");
	GotoXY(17, 7);
	printf("      \\ `--. | |  __ _  _   _    | |_ | |__    ___    \\ `--.  _ __   _  _ __   ___  \n");
	GotoXY(17, 8);
	printf("       `--. \\| | / _` || | | |   | __|| '_ \\  / _ \\    `--. \\| '_ \\ | || '__| / _ \\ \n");
	GotoXY(17, 9);
	printf("      /\\__/ /| || (_| || |_| |   | |_ | | | ||  __/   /\\__/ /| |_) || || |   |  __/ \n");
	GotoXY(17, 10);
	printf("      \\____/ |_| \\__,_| \\__, |    \\__||_| |_| \\___|   \\____/ | .__/ |_||_|    \\___| \n");
	GotoXY(17, 11);
	printf("                         __/ |                             | |                    \n");
	GotoXY(17, 12);
	printf("                        |___/                              |_|                    \n");

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
	MyCharacterDraw(hConsole);
	EnemyCharacterDraw(hConsole);

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
	GotoXY(55, 17);

	SET_GREEN  printf("▶ 게임 하기");
	GotoXY(55, 19);
	SET_YELLOW printf("   게임 설명");
	GotoXY(55, 21);
	SET_YELLOW printf("   카드 목록");
	GotoXY(55, 23);
	SET_YELLOW printf("   게임 종료");

	SET_WHITE
}

void TutorialDraw(HANDLE hConsole)
{
	GotoXY(55, 17);

	SET_YELLOW  printf("   게임 하기");
	GotoXY(55, 19);
	SET_GREEN printf("▶ 게임 설명");
	GotoXY(55, 21);
	SET_YELLOW printf("   카드 목록");
	GotoXY(55, 23);
	SET_YELLOW printf("   게임 종료");

	SET_WHITE
}

void ShowCardMenuDraw(HANDLE hConsole) {
	GotoXY(55, 17);

	SET_YELLOW  printf("   게임 하기");
	GotoXY(55, 19);
	SET_YELLOW printf("   게임 설명");
	GotoXY(55, 21);
	SET_GREEN printf("▶ 카드 목록");
	GotoXY(55, 23);
	SET_YELLOW printf("   게임 종료");

	SET_WHITE
}

void ExitMenuDraw(HANDLE hConsole)
{
	GotoXY(55, 17);

	SET_YELLOW  printf("   게임 하기");
	GotoXY(55, 19);
	SET_YELLOW printf("   게임 설명");
	GotoXY(55, 21);
	SET_YELLOW printf("   카드 목록");
	GotoXY(55, 23);
	SET_GREEN printf("▶ 게임 종료");

	SET_WHITE
}

void MyCharacterDraw(HANDLE hConsole) {
	GotoXY(20, 13);
	SET_GREEN
	printf("    Player     \n");
	SET_WHITE
	GotoXY(20, 14);
	printf("    -@!\n");
	GotoXY(20, 15);
	printf("   -@@@@;..\n");
	GotoXY(20, 16);
	printf("   ~@ :$$#@~,\n");
	GotoXY(20, 17);
	printf("  ~@     ;===.\n");
	GotoXY(20, 18);
	printf(" .@ :$@;\n");
	GotoXY(20, 19);
	printf("  =@$!@; \n");
	GotoXY(20, 20);
	printf("  .*@@@=:,     \n");
	GotoXY(20, 21);
	printf("   -@@@@@*;;.  \n");
	GotoXY(20, 22);
	printf("   -@@@=!#@!   \n");
	GotoXY(20, 23);
	printf("   -@@@;.-~.   \n");
	GotoXY(20, 24);
	printf("  ==@@@#=-     \n");
	GotoXY(20, 25);
	printf(" .@@=--*@#-    \n");
	GotoXY(20, 26);
	printf(" .@$.  .*@#,   \n");
	GotoXY(20, 27);
	printf(".##.     *@-   \n");
	GotoXY(20, 28);
	printf(".@$       =-   \n");
}

void EnemyCharacterDraw(HANDLE hConsole) {
	//Slime
	GotoXY(80, 24);
	SET_GREEN
	printf("    Slime\n");
	SET_WHITE
	GotoXY(80, 25);
	printf("    :::::$ \n"); 
	GotoXY(80, 26);
	printf("   :◆:◆::! \n");
	GotoXY(80, 27);
	printf("  :::...:::;;\n");
	GotoXY(80, 28);
	printf("   ;:::;:;=$\n");

	//Guardian
	GotoXY(95, 13);
	SET_GREEN
		printf("    Guardian\n");
	SET_WHITE
	GotoXY(95, 14);
	printf("       !*      \n");
	GotoXY(95, 15);
	printf("       :;      \n");
	GotoXY(95, 16);
	printf("       ~*      \n");
	GotoXY(95, 17);
	printf("      .-~      \n");
	GotoXY(95, 18);
	printf("      .,~#     \n");
	GotoXY(95, 19);
	printf("      ,,~:     \n");
	GotoXY(95, 20);
	printf("     ,.,~;#    \n");
	GotoXY(95, 21);
	printf("    .!.◆:##    \n");
	GotoXY(95, 22);
	printf("     -!-!~#    \n");
	GotoXY(95, 23);
	printf("     ~,:;$~    \n");
	GotoXY(95, 24);
	printf("      ~~!#~     \n");
	GotoXY(95, 25);
	printf("       ~~=     \n");
	GotoXY(95, 26);
	printf("       -~=     \n");
	GotoXY(95, 27);
	printf("       !!      \n");
	GotoXY(95, 28);
	printf("        $      \n");

	//Protector
	GotoXY(76, 14);
	printf(",.. ");
	SET_GREEN
		printf("Protector");
	SET_WHITE
	GotoXY(76, 15);
	printf("~◆~  .-:;,");
	GotoXY(76, 16);
	printf("-:! .,,,.,#  ..:");
	GotoXY(76, 17);
	printf("   ,-,...,-- .◆*");
	GotoXY(76, 18);
	printf("   -◆,,◆.- ~##*");
	GotoXY(76, 19);
	printf("   ,,,.  :;#");
	GotoXY(76, 20);
	printf("   !,,.-~;;$");
	GotoXY(76, 21);
	printf("    -~,-:!=");
	GotoXY(76, 22);
	printf("     =-~;#");
}

void GameOverDraw() {
	//system("cls");
	//박스 다시 그리기
	//DrawBox(120, 30);
	
	Music_Stop(1); //선택사운드 재생중지
	Music_Init();
	Music_GameOver();
	//Game Over 글자 출력
	GotoXY(9,  4); printf(".----------------------------------------------------------------------------------------------------.");
	GotoXY(9,  5); printf("| Slay the Spire.exe                                                                             |x| |");
	GotoXY(9,  6); printf("|----------------------------------------------------------------------------------------------------|");
	GotoXY(9,  7); printf("|                                                                                                    |");
	GotoXY(9,  8); printf("|                                                                                                    |");
	GotoXY(9,  9); printf("|                                                                                                    |");
	GotoXY(9, 10); printf("|                                                                                                    |");
	GotoXY(9, 11); printf("|      ,-----.    ,---.    ,--.   ,--.  .------.          ,-----. ,--.    ,--. ,------.,------.      |");
	GotoXY(9, 12); printf("|     |  ,---/   / ,-. \\   |   `.'   |  |  .---'         / .-.  '\\   \\   /   / |  .---'|   /`. '     |");
	GotoXY(9, 13); printf("|     | |       / /---\\ \\  |         |  |  |            |  | |  | \\   \\ /   /  |  |    |  /  | |     |");
	GotoXY(9, 14); printf("|     | |  `--. |  ,--. |  |  |'.'|  |  |  '--.         |  | |  |  \\   '   /   |  '--. |  |_.' |     |");
	GotoXY(9, 15); printf("|     | |   | | | |   | |  |  |   |  |  |  .--'         |  | |  |   \\     /    |  .--' |  .  '.'     |");
	GotoXY(9, 16); printf("|     | `---' | | |   | |  |  |   |  |  |  `---.        '  '-'  '    \\   /     |  `---.|  |\\  \\      |");
	GotoXY(9, 17); printf("|      `-----'  `-'   `-'  `--'   `--'  `------'         `-----'      `-'      `------'`--' '--'     |");
	GotoXY(9, 18); printf("|                                                                                                    |");
	GotoXY(9, 19); printf("|                                                                                                    |");
	GotoXY(9, 20); printf("|                                                                                                    |");
	GotoXY(9, 21); printf("|                                                                                                    |");
	GotoXY(9, 22); printf("|                                                                                                    |");
	GotoXY(9, 23); printf("|____________________________________________________________________________________________________|");
}


void CardListDraw() { //카드 목록 그리기

}

void PlayExampleDraw() { //게임 설명 그리기

}