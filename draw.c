﻿#include <stdio.h>
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
	GotoXY(17, 5);
	SET_GREEN printf("       _____  _                   "); SET_YELLOW printf("_    _               "); SET_RED printf("_____         _              \n"); SET_GREEN

	GotoXY(17, 6);
	printf("      /  ___|| |                 "); SET_YELLOW printf("| |  | |             "); SET_RED printf("/ ___ |       (_)             \n"); SET_GREEN

	GotoXY(17, 7);
	printf("      \\ `--. | |  __ _  _   _    "); SET_YELLOW printf("| |_ | |__    ___    "); SET_RED printf("\\ `- - ._ __   _  _ __   ___  \n"); SET_GREEN

	GotoXY(17, 8);
	printf("       `--. \\| | / _` || | | |   "); SET_YELLOW printf("| __|| '_ \\  / _ \\    "); SET_RED printf("`--. \\| '_ \\ | || '__| / _ \\ \n"); SET_GREEN

	GotoXY(17, 9);
	printf("      /\\__/ /| || (_| || |_| |   "); SET_YELLOW printf("| |_ | | | ||  __/ "); SET_RED printf("  /\\__/ /| |_) || || |   |  __/ \n"); SET_GREEN

	GotoXY(17, 10);
	printf("      \\____/ |_| \\__,_| \\__, |   "); SET_YELLOW printf("\\__/ |_| |_| \\___| "); SET_RED printf("  \\____/ |. __/ |_||_|    \\___| \n"); SET_GREEN

	GotoXY(17, 11);
	printf("                         __/ |"); SET_RED printf("                               | |                    \n"); SET_GREEN

	GotoXY(17, 12);
	printf("                        |___/"); SET_RED printf("                                |_| \n");
	SET_WHITE

	/*
	 GotoXY(17, 5);
	printf("░██████╗██╗░░░░░░█████╗░██╗░░░██╗  ████████╗██╗░░██╗███████╗  ░██████╗██████╗░██╗██████╗░███████╗\n");
		GotoXY(17, 6);
	printf("██╔════╝██║░░░░░██╔══██╗╚██╗░██╔╝  ╚══██╔══╝██║░░██║██╔════╝  ██╔════╝██╔══██╗██║██╔══██╗██╔════╝\n");
	GotoXY(17, 7);
	printf("╚█████╗░██║░░░░░███████║░╚████╔╝░  ░░░██║░░░███████║█████╗░░  ╚█████╗░██████╔╝██║██████╔╝█████╗░░\n");
	GotoXY(17, 8);
	printf("░╚═══██╗██║░░░░░██╔══██║░░╚██╔╝░░  ░░░██║░░░██╔══██║██╔══╝░░  ░╚═══██╗██╔═══╝░██║██╔══██╗██╔══╝░░\n");
		GotoXY(17, 9);
	printf("██████╔╝███████╗██║░░██║░░░██║░░░  ░░░██║░░░██║░░██║███████╗  ██████╔╝██║░░░░░██║██║░░██║███████╗\n");
	GotoXY(17, 10);
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
				return mode;
			}
			case 'r':
				return mode;
			case 'R':
				return mode;
		}
	}
}

void StartMenuDraw(HANDLE hConsole) //메뉴창 드로우 첫 세팅선택지는 새로하기.
{
	GotoXY(55, 17);

	SET_GREEN  printf("▶ 게임 하기");
	GotoXY(55, 19);
	SET_WHITE printf("   게임 설명");
	GotoXY(55, 21);
	SET_WHITE printf("   카드 목록");
	GotoXY(55, 23);
	SET_WHITE printf("   게임 종료");
}

void TutorialDraw(HANDLE hConsole)
{
	GotoXY(55, 17);

	SET_WHITE  printf("   게임 하기");
	GotoXY(55, 19);
	SET_GREEN printf("▶ 게임 설명");
	GotoXY(55, 21);
	SET_WHITE printf("   카드 목록");
	GotoXY(55, 23);
	SET_WHITE printf("   게임 종료");
}

void ShowCardMenuDraw(HANDLE hConsole) {
	GotoXY(55, 17);

	SET_WHITE  printf("   게임 하기");
	GotoXY(55, 19);
	SET_WHITE printf("   게임 설명");
	GotoXY(55, 21);
	SET_GREEN printf("▶ 카드 목록");
	GotoXY(55, 23);
	SET_WHITE printf("   게임 종료");
}

void ExitMenuDraw(HANDLE hConsole)
{
	GotoXY(55, 17);

	SET_WHITE  printf("   게임 하기");
	GotoXY(55, 19);
	SET_WHITE printf("   게임 설명");
	GotoXY(55, 21);
	SET_WHITE printf("   카드 목록");
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
	SET_RED
	printf("    Slime\n");
	SET_WHITE
	GotoXY(80, 25);
	printf("    :::::$ \n"); 
	GotoXY(80, 26);
	printf("   :"); SET_RED printf("◆"); SET_WHITE printf(":"); SET_RED printf("◆"); SET_WHITE printf("::!\n");
	GotoXY(80, 27);
	printf("  :::...:::;;\n");
	GotoXY(80, 28);
	printf("   ;:::;:;=$\n");

	//Guardian
	GotoXY(95, 13);
	SET_RED
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
	printf("    .!."); SET_RED printf("◆"); SET_WHITE printf(";:##\n");
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
	SET_RED
	printf("Protector");
	SET_WHITE
	GotoXY(76, 15);
	printf("~");  SET_RED printf("◆"); SET_WHITE printf("~. - :; , ");
	GotoXY(76, 16);
	printf("-:! .,,,.,#  ..:");
	GotoXY(76, 17);
	printf("   ,-,...,-- .");  SET_RED printf("◆"); SET_WHITE printf("* ");
	GotoXY(76, 18);
	printf("   -"); SET_RED printf("◆"); SET_WHITE printf(",,"); SET_RED printf("◆"); SET_WHITE printf(".- ~## * ");
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

void CreatingCard() {
	for (int i = 0; i < 14; i++) {
		fgets(card[i].name, sizeof(card[i].name), stdin);
		card[i].name[strcspn(card[i].name, "\n")] = '\0'; // 문자 제거

		scanf("%d", &card[i].damage);
		scanf("%d", &card[i].damage_times);
		scanf("%d", &card[i].damage_all);
		scanf("%d", &card[i].protect);
		scanf("%d", &card[i].My_debuff);
		scanf("%d", &card[i].Enemy_debuff);

		fgetc(stdin); // 이전 입력 버퍼 제거

		fgets(card[i].description, sizeof(card[i].description), stdin);
		card[i].description[strcspn(card[i].description, "\n")] = '\0'; // 문자 제거
	}
	card[0].energy = 1;
	card[1].energy = 1;
	card[2].energy = 2;
	card[3].energy = 2;
	card[4].energy = 1;
	card[5].energy = 1;
	card[6].energy = 0;
	card[7].energy = 1;
	card[8].energy = 2;
	card[9].energy = 0;
	card[10].energy = 2;
	card[11].energy = 3;
	card[12].energy = 3;
	card[13].energy = 1;
}

void CardListDraw() { //카드 목록 그리기	
	//system("cls");
	Clear();
	for (int i = 0; i < 14; i++) {
		printf("카드 이름 : ");
		if (i == 0 || i == 2 || i == 3 || i == 5 ||  i == 7 || i == 8 || i == 12 || i ==13) {//공격 카드
			SET_RED
			printf("%s\n", card[i].name);
			SET_WHITE
		}
		else if (i == 1 || i == 4 || i == 6 || i == 9 || i == 10 || i == 11) { //스킬카드 일때
			SET_GREEN
			printf("%s\n", card[i].name);
			SET_WHITE
		}
		if (i == 2 || i == 3 || i == 8 || i == 10) {
			printf("카드 비용 : 2\n");
		}
		else if (i == 11 || i == 12) {
			printf("카드 비용 : 3\n");
		}
		else if (i == 6 || i == 9) {
			printf("카드 비용 : 0\n");
		}
		else {
			printf("카드 비용 : 1\n");
		}
		printf("데미지 : %d\n", card[i].damage);
		printf("방어도 : %d\n", card[i].protect);
		printf("카드 설명 : %s\n", card[i].description);
		printf("\n\n");
	}
}

void PlayExampleDraw1(HANDLE hConsole) { //게임 설명 그리기
	//system("cls");
	Clear();
	GotoXY(0, 0);
	DrawBox(120,30);
	for (int i = 3; i < 119; i++) {
		GotoXY(i, 3);
		printf("-");
	}

	SET_GREEN
	GotoXY(3, 2);
	printf("Player");
	GotoXY(12, 2);
	printf("♥ 80/80");
	GotoXY(22, 2);
	printf("%1층");
	GotoXY(32, 2);
	printf("힘 : 0");
	GotoXY(40, 2);
	printf("에너지 (3/3)");
	GotoXY(55, 2);
	printf("내 방어도 : 0");
	GotoXY(46, 4);
	printf("↑");
	GotoXY(55, 31);
	printf("Page (1/3)");
	SET_RED
	GotoXY(70, 2);
	printf("몬스터가 7만큼 공격합니다!");

	SET_WHITE
	GotoXY(60, 13);
	printf("손에 있는 카드를 사용하여 적들을 물리치십시오!");
	GotoXY(60, 15);
	printf("카드를 사용하려면 "); SET_GREEN printf("에너지"); SET_WHITE printf("가 필요합니다.");
	GotoXY(60, 16);
	printf("낼 수 있는 카드가 없어지면, 턴을 종료하십시오.");
	GotoXY(60, 18);
	printf("당신의 턴이 시작될 때 새로운 카드들을 뽑고");
	GotoXY(60, 19);
	SET_GREEN printf("에너지"); SET_WHITE printf("를 다시 채웁니다.");

	SET_GREEN
	GotoXY(3, 31);
	printf("R을 누르면 메인화면으로 돌아갑니다.\n");
	GotoXY(80, 31);
	printf("N을 누르면 다음화면으로 넘어갑니다.\n");
	SET_WHITE

	GotoXY(7, 7);
	printf("┌─────────────────────┐");
	GotoXY(7, 8);
	printf("│                                          │");
	GotoXY(7, 9);
	printf("│                                          │");
	GotoXY(7, 10);
	printf("│                                          │");
	GotoXY(7, 11);
	printf("│1."); SET_RED printf("타격    "); SET_WHITE  printf("2."); SET_RED printf("강타    "); SET_WHITE printf("3."); SET_GREEN printf("수비   "); SET_WHITE printf("4."); SET_GREEN printf("악마의 형상"); SET_WHITE printf("│"); 
	GotoXY(7, 12);
	printf("│에너지:1  에너지:2  에너지:1 에너지:3     │");
	GotoXY(7, 13);
	printf("│공격:6    공격:8    방어:5   매턴 힘3증가 │");
	GotoXY(7, 14);
	printf("│                                          │");
	GotoXY(7, 15);
	printf("│                                          │");
	GotoXY(7, 16);
	printf("│                                          │");
	GotoXY(7, 17);
	printf("│                                          │");
	GotoXY(7, 18);
	printf("│    총 "); SET_GREEN printf("에너지"); SET_WHITE printf(" 수에 맞게 카드를 선택해서   │");
	GotoXY(7, 19);
	printf("│            사용가능합니다!               │");
	GotoXY(7, 20);
	printf("│                                          │");
	GotoXY(7, 21);
	printf("│                                          │");
	GotoXY(7, 22);
	printf("│                                          │");
	GotoXY(7, 23);
	printf("│                                          │");
	GotoXY(7, 24);                     
	printf("└─────────────────────┘");
}

void PlayExampleDraw2(HANDLE hConsole) {
	GotoXY(0, 0);
	DrawBox(120, 30);
	for (int i = 3; i < 119; i++) {
		GotoXY(i, 3);
		printf("-");
	}

	SET_GREEN
		GotoXY(3, 2);
	printf("Player");
	GotoXY(12, 2);
	printf("♥ 80/80");
	GotoXY(22, 2);
	printf("%1층");
	GotoXY(32, 2);
	printf("힘 : 0");
	GotoXY(40, 2);
	printf("에너지 (3/3)");
	GotoXY(55, 2);
	printf("내 방어도 : 0");
	GotoXY(66, 4);
	printf("↑");
	GotoXY(55, 31);
	printf("Page (2/3)");
	SET_RED
	GotoXY(70, 2);
	printf("몬스터가 7만큼 공격합니다!");

	SET_WHITE
	GotoXY(60, 13);
	printf("적들이 당신을 공격하려 하면, 방어 카드를");
	GotoXY(60, 14);
	printf("사용하여 "); SET_GREEN printf("방어도"); SET_WHITE printf("를 얻으십시오.");
	GotoXY(60, 16);
	SET_GREEN printf("방어도"); SET_WHITE printf("는 받는 공격 피해를 줄여주지만");
	GotoXY(60, 17);
	printf("당신의 다음 턴이 시작될 때");	SET_RED printf(" 효과가 사라집니다."); SET_WHITE 

	SET_GREEN
	GotoXY(3, 31);
	printf("B를 누르면 이전화면으로 돌아갑니다.\n");
	GotoXY(80, 31);
	printf("N을 누르면 다음화면으로 넘어갑니다.\n");
	SET_WHITE

	GotoXY(10, 7);
	printf("┌─────────────────────┐");
	GotoXY(10, 8);
	printf("│                                          │");
	GotoXY(10, 9);
	printf("│        총 "); SET_GREEN printf("10"); SET_WHITE printf("라운드로 구성되어있고        │");
	GotoXY(10, 10);
	printf("│                                          │");
	GotoXY(10, 11);
	printf("│                                          │");
	GotoXY(10, 12);
	printf("│     라운드마다 "); SET_GREEN printf("적의 체력이 0"); SET_WHITE printf(" 이 된다면   │");
	GotoXY(10, 13);
	printf("│        다음 라운드로 넘어갑니다.         │");
	GotoXY(10, 14);
	printf("│                                          │");
	GotoXY(10, 15);
	printf("│                                          │");
	GotoXY(10, 16);
	printf("│                                          │");
	GotoXY(10, 17);
	printf("│                                          │");
	GotoXY(10, 18);
	printf("│      만약 "); SET_RED printf("플레이어의 체력"); SET_WHITE printf("이 0이 되면     │");
	GotoXY(10, 19);
	printf("│           게임은 종료됩니다.             │");
	GotoXY(10, 20);
	printf("│                                          │");
	GotoXY(10, 21);
	printf("│                                          │");
	GotoXY(10, 22);
	printf("│                                          │");
	GotoXY(10, 23);
	printf("│                                          │");
	GotoXY(10, 24);
	printf("└─────────────────────┘");
}

void PlayExampleDraw3(HANDLE hConsole) {
	GotoXY(0, 0);
	DrawBox(120, 30);
	for (int i = 3; i < 119; i++) {
		GotoXY(i, 3);
		printf("-");
	}

	SET_GREEN
	GotoXY(55, 31);
	printf("Page (3/3)");

	GotoXY(3, 2);
	printf("Player");
	GotoXY(12, 2);
	printf("♥ 80/80");
	GotoXY(22, 2);
	printf("%1층");
	GotoXY(32, 2);
	printf("힘 : 0");
	GotoXY(40, 2);
	printf("에너지 (3/3)");
	GotoXY(55, 2);
	printf("내 방어도 : 0");
	SET_RED
	GotoXY(70, 2);
	printf("몬스터가 7만큼 공격합니다!");
	GotoXY(82, 4);
	printf("↑");
	SET_WHITE

	GotoXY(60, 13);
	printf("당신의 턴이 진행될 동안 적의"); SET_GREEN printf(" 태세"); SET_WHITE printf("를");
	GotoXY(60, 14);
	printf("확인할 수 있습니다.");
	GotoXY(60, 16);
	printf("적이 당신을 공격하려 한다면, ");  SET_GREEN printf("방어도"); SET_WHITE printf("를");
	GotoXY(60, 17);
	printf("올리십시오!");

	SET_GREEN
	GotoXY(3, 31);
	printf("B를 누르면 이전화면으로 돌아갑니다.\n");
	GotoXY(80, 31);
	printf("R을 누르면 메인화면으로 넘어갑니다.\n");
	SET_WHITE

	GotoXY(10, 7);
	printf("┌─────────────────────┐");
	GotoXY(10, 8);
	printf("│                                          │");
	GotoXY(10, 9);
	printf("│                                          │");
	GotoXY(10, 10);
	printf("│   적의 태세에는 3가지 종류가 있습니다.   │");
	GotoXY(10, 11);
	printf("│                                          │");
	GotoXY(10, 12);
	printf("│    "); SET_RED printf("1. 몬스터가 10만큼 공격합니다!"); SET_WHITE printf("        │");
	GotoXY(10, 13);
	printf("│                                          │");
	GotoXY(10, 14);
	printf("│    "); SET_RED printf("2. 몬스터가 10만큼 방어도를 얻습니다!"); SET_WHITE printf(" │");
	GotoXY(10, 15);
	printf("│                                          │");
	GotoXY(10, 16);
	printf("│    "); SET_RED printf("3. 몬스터가 디버프를 사용합니다!"); SET_WHITE printf("      │");
	GotoXY(10, 17);
	printf("│                                          │");
	GotoXY(10, 18);
	printf("│  각 상황에 맞게 적절한 카드를 선택하여   │");
	GotoXY(10, 19);
	printf("│                                          │");
	GotoXY(10, 20);
	printf("│         게임을 "); SET_GREEN printf("클리어"); SET_WHITE printf("하십시오!           │");
	GotoXY(10, 21);
	printf("│                                          │");
	GotoXY(10, 22);
	printf("│                                          │");
	GotoXY(10, 23);
	printf("│                                          │");
	GotoXY(10, 24);
	printf("└─────────────────────┘");
}

void DrawCard(int value, int count) { // 카드를 드로우하는 함수
	GotoXY(count*25, 35);
	printf("     %d.%s", count+1, card[value].name);
	GotoXY(count*25, 37);
	if (value == 0) { //타격
		printf("에너지 : 1");
		GotoXY(count * 25, 38);
		printf("데미지 : 6");
	}
	else if (value == 1) { //수비
		printf("에너지 : 1\n");
		GotoXY(count * 25, 38);
		printf("방어력 : 5\n");
	}
	else if (value == 2) { //강타
		printf("에너지 : 2\n");
		GotoXY(count * 25, 38);
		printf("데미지 : 8\n");
		GotoXY(count * 25, 39);
		printf("힘 증가 : 1\n");
	}
	else if (value == 3) { //완벽한 타격
		printf("에너지 : 2\n");
		GotoXY(count * 25, 38);
		printf("보유 타격 : 5장\n");
		GotoXY(count * 25, 39);
		printf("데미지 : 16\n");
	}
	else if (value == 4) {//발화
		printf("에너지 : 1\n");
		GotoXY(count * 25, 38);
		printf("힘 증가 : 3\n");
	}
	else if (value == 5) {//철의 파동
		printf("에너지 : 1\n");
		GotoXY(count * 25, 38);
		printf("데미지 : 5\n");
		GotoXY(count * 25, 39);
		printf("방어력 : 5\n");
	}
	else if (value == 6) {//사혈
		printf("에너지 : 0\n");
		GotoXY(count * 25, 38);
		printf("자가 데미지 : 3\n");
		GotoXY(count * 25, 39);
		printf("에너지 생성 : 2\n");
	}
	else if (value == 7) {//연타
		printf("에너지 : 1\n");
		GotoXY(count * 25, 38);
		printf("데미지 : 2\n");
		GotoXY(count * 25, 39);
		printf("4번 반복 공격\n");
	}
	else if (value == 8) {//화형
		printf("에너지 : 2\n");
		GotoXY(count * 25, 38);
		printf("적군 전체 데미지 : 21\n");
		GotoXY(count * 25, 39);
		printf("힘 감소 : 1");
	}
	else if (value == 9) {//제물
		printf("에너지 : 0\n");
		GotoXY(count * 25, 38);
		printf("자가 데미지 : 6\n");
		GotoXY(count * 25, 39);
		printf("에너지 생성 : 2\n");
		GotoXY(count * 25, 40);
		printf("카드 드로우 : 3장\n");
	}
	else if (value == 10) {//무적
		printf("에너지 : 2\n");
		GotoXY(count * 25, 38);
		printf("방어도 : 30\n");
	}
	else if (value == 11) {//악마의 형상
		printf("에너지 : 3\n");
		GotoXY(count * 25, 38);
		printf("매턴 힘증가 : 3\n");
	}
	else if (value == 12) {//몽둥이질
		printf("에너지 : 3\n");
		GotoXY(count * 25, 38);
		printf("데미지 : 32\n");
	}
	else if (value == 13) {//드롭킥
		printf("에너지 : 1\n");
		GotoXY(count * 25, 38);
		printf("데미지 : 5\n");
		GotoXY(count * 25, 39);
		printf("카드 드로우 : 1장\n");
	}
	SET_WHITE
}

