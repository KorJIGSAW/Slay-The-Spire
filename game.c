#include <stdio.h>
#include "game.h"
#include "status.h"
#include "console.h"
#include "draw.h"
#include "character.h"
#include "CSound.h"
#include "card.h"

INFORMATION Info;
MyCharacter Player;
EnemyCharacter Enemy;

void DrawEnemyCharacter(int stair) { //슬라임
	//층수에 따라서 적들의 모습출력을 달리해야한다.
	if (stair == 1) {
		GotoXY(80, 24);
		SET_GREEN
			printf("    슬라임\n");
		SET_WHITE
			GotoXY(80, 25);
		printf("    :::::$ \n");
		GotoXY(80, 26);
		printf("   :◆:◆::! \n");
		GotoXY(80, 27);
		printf("  :::...:::;;\n");
		GotoXY(80, 28);
		printf("   ;:::;:;=$\n");
	}
	else if (stair == 2) { //공벌레
		GotoXY(80, 21);
		SET_GREEN
			printf("        공벌레");
		SET_WHITE
			GotoXY(80, 22);
		printf("     $   #");
		GotoXY(80, 23);
		printf("    $   #");
		GotoXY(80, 24);
		printf("    #,$, .~:");
		GotoXY(80, 25);
		printf("    *,,.  .,,:");
		GotoXY(80, 26);
		printf("    ;◇-◇  ,- .~");		
		GotoXY(80, 27);
		printf("    ,-:-.;., .,#");
		GotoXY(80, 28);
		printf("    -,-- ---,.-- ");           
	}
	else if (stair == 3) { //턱벌레
		GotoXY(80, 19);
		SET_GREEN
			printf("        턱벌레");
		SET_WHITE
		GotoXY(80, 20);
		printf("         -#         ");
		GotoXY(80, 21);
		printf("      :~:~;         ");
		GotoXY(80, 22);
		printf("    :::::::~#       ");
		GotoXY(80, 23);
		printf("   :~◆::::~:$       ");
		GotoXY(80, 24);
		printf("  :◆~~◆::-:~-$     ");
		GotoXY(80, 25);
		printf("  ;::◆::::~~:;!     ");
		GotoXY(80, 26);
		printf("  ;;;;:::~:;;;:#    ");
		GotoXY(80, 27);
		printf("   $=!!===*~# *:~:~ ");
		GotoXY(80, 28);
		printf("         !!#        ");         
	}
	else if (stair == 4) { // 보초기
		GotoXY(80, 13);
		SET_GREEN
			printf("     보초기\n");
		SET_WHITE
			GotoXY(80, 14);
		printf("       !*      \n");
		GotoXY(80, 15);
		printf("       :;      \n");
		GotoXY(80, 16);
		printf("       ~*      \n");
		GotoXY(80, 17);
		printf("      .-~      \n");
		GotoXY(80, 18);
		printf("      .,~#     \n");
		GotoXY(80, 19);
		printf("      ,,~:     \n");
		GotoXY(80, 20);
		printf("     ,.,~;#    \n");
		GotoXY(80, 21);
		printf("    .!.◆:##    \n");
		GotoXY(80, 22);
		printf("     -!-!~#    \n");
		GotoXY(80, 23);
		printf("     ~,:;$~    \n");
		GotoXY(80, 24);
		printf("      ~~!#~     \n");
		GotoXY(80, 25);
		printf("       ~~=     \n");
		GotoXY(80, 26);
		printf("       -~=     \n");
		GotoXY(80, 27);
		printf("       !!      \n");
		GotoXY(80, 28);
		printf("        $      \n");
	}
	else if (stair == 5) { //카카
		GotoXY(80, 10);
		SET_GREEN
			printf("     광신도\n");
		SET_WHITE
			GotoXY(80, 11);
		printf("*=      \n");
		GotoXY(80, 12);
		printf("# =               ;\n");
		GotoXY(80, 13);
		printf("  *                #\n");
			GotoXY(80, 14);
		printf(" !$  !!$        *  #\n");
		GotoXY(80, 15);
		printf("  # *!. -       ~ * \n");
		GotoXY(80, 16);
		printf("  *#!◆-...    :~;:= \n");
		GotoXY(80, 17);
		printf("  #*:.!::;;!~~~:;:# \n");
		GotoXY(80, 18);
		printf("  !!,!~;:;--~~-~~~:$\n");
		GotoXY(80, 19);
		printf("  !! $#;;;;:$~   ~::\n");
		GotoXY(80, 20);
		printf("  #   #;;;::      :$\n");
		GotoXY(80, 21);
		printf("       ;::;:     =! \n");
		GotoXY(80, 22);
		printf("      :;;:;;=     # \n");
		GotoXY(80, 23);
		printf("      ;:;;::#       \n");
		GotoXY(80, 24);
		printf("     *;:;:::=       \n");
		GotoXY(80, 25);
		printf("     $;;;;;;;;;!    \n");
		GotoXY(80, 26);
		printf("       ~= ~$**#     \n");
		GotoXY(80, 27);
		printf("       ~  -#        \n");
		GotoXY(80, 28);
		printf("      $ $  #       \n");
	}
	else if (stair == 6) {//수호기
		GotoXY(76, 14);
	printf(",.. ");
	SET_GREEN
		printf("수호기");
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
	else if (stair == 7) {//스네코
		GotoXY(80, 15);
		SET_GREEN
			printf("        스네코\n");
		SET_WHITE
		GotoXY(80, 16);
		printf("	  ,,,            \n");
		GotoXY(80, 17);
		printf("         .,,,-       \n");
		GotoXY(80, 18);
		printf("       -.,,/ \\--          \n");
		GotoXY(80, 19);
		printf("      ,,-/  /-~         \n");
		GotoXY(80, 20);
		printf("     ;,◆/  /--;          \n");
		GotoXY(80, 21);
		printf("     ;,./  /,-          \n");
		GotoXY(80, 22);
		printf("      |   ~.~,        \n");
		GotoXY(80, 23);
		printf("      S   ..-,*~;-,    \n");
		GotoXY(80, 24);
		printf("         ;.,,,----,~   \n");
		GotoXY(80, 25);
		printf("       ---.,,,,  /.,-      \n");
		GotoXY(80, 26);
		printf("       -:~/.,-  /--./     \n");
		GotoXY(80, 27);
		printf(" !:::~:-/ ,-----.;/   \n");
		GotoXY(80, 28);
		printf(" !#;;;=/   ,---:-  \n");    
	}
	else if (stair == 8) { //대왕슬라임
		GotoXY(80, 9);
		SET_GREEN
			printf("         대왕슬라임\n");
		SET_WHITE
			GotoXY(80, 10);
		printf("                 ##          \n");
		GotoXY(80, 11);
		printf("           ,.....=###         \n");
		GotoXY(80, 12);
		printf("         ........~#$#         \n");
		GotoXY(80, 13);
		printf("        ..........-$#$        \n");
		GotoXY(80, 14);
		printf("       .............,.,       \n");
		GotoXY(80, 15);
		printf("       ...............:       \n");
		GotoXY(80, 16);
		printf("      .................       \n");
		GotoXY(80, 17);
		printf("     ....,.............-      \n");
		GotoXY(80, 18);
		printf("    ....  .....  .......~     \n");
		GotoXY(80, 19);
		printf("    ...   ......  .......~     \n");
		GotoXY(80, 20);
		printf("   ...   .    ...  ......~     \n");
		GotoXY(80, 21);
		printf("   ..... .       .........~     \n");
		GotoXY(80, 22);
		printf("   ...               .....~    \n");
		GotoXY(80, 23);
		printf("   ... .-=~===:===*==  ...:$  \n");
		GotoXY(80, 24);
		printf("     .**==:======*==-....~   \n");
		GotoXY(80, 25);
		printf("     .-*;*;****=:*=;:....,   \n");
		GotoXY(80, 26);
		printf("    *. ,~!;*-*!!,!*~,...-$   \n");
		GotoXY(80, 27);
		printf("      ..... .....~,,.,,,$    \n");
		GotoXY(80, 28);
		printf("       #$:-..,....,..~=      \n");                 
	}
	else if (stair == 9) { //도누
		GotoXY(80, 5);
		SET_GREEN
			printf("         도누\n");
		SET_WHITE
		GotoXY(80, 7);
		printf("          *!;          \n");
		GotoXY(80, 8);
		printf("      ---,,---~~:      \n");
		GotoXY(80, 9);
		printf("     :,.....--.--~     \n");
		GotoXY(80, 10);
		printf("    ,..,-----,.----*   \n");
		GotoXY(80, 11);
		printf("   -.,-~~~----,-----   \n");
		GotoXY(80, 12);
		printf("  -.-~~~~~~~~--,,---~  \n");
		GotoXY(80, 13);
		printf(" -.,-~~~:::~~---,,---~ \n");
		GotoXY(80, 14);
		printf(" ~.-~~~:!*!:~-~~,,---; \n");
		GotoXY(80, 15);
		printf(" ,,-~~:!=   ~---,,---: \n");
		GotoXY(80, 16);
		printf(";.--~~:!*   :---,,---:=\n");
		GotoXY(80, 17);
		printf(":.-~~~:!    ~---,,---;=\n");
		GotoXY(80, 18);
		printf(";--~~~:!*   ----,,--~!*\n");
		GotoXY(80, 19);
		printf("*~--~~~:;;::~~---,--~!=\n");
		GotoXY(80, 20);
		printf(" ---~~~~~~~~~--,,-~~;! \n");
		GotoXY(80, 21);
		printf(" ;,-~~~~~~~----,,~:;!= \n");
		GotoXY(80, 22);
		printf(" ;,-:~~------~-,-~;!*  \n");
		GotoXY(80, 23);
		printf("  ,-:~~~-~~~~~,,-:;!*  \n");
		GotoXY(80, 24);
		printf(" / !~~~~~~~~~~--:;:! \\\n");
		GotoXY(80, 25);
		printf("/   ~:!!;;;;;;;!!!:!  \\\n");
		GotoXY(80, 26);
		printf("    ~:            :!   \n");
		GotoXY(80, 27);
		printf("    ~*            :*   \n");
		GotoXY(80, 28);
		printf("    *=            $=   \n");
	}
	else if (stair == 10) { //데카
		GotoXY(80, 5);
		SET_GREEN
			printf("         데카\n");
		SET_WHITE
		GotoXY(80, 6);
		printf("          .             \n");
		GotoXY(80, 7);
		printf("         -....          \n");
		GotoXY(80, 8);
		printf("        -.....          \n");
		GotoXY(80, 9);
		printf("       ........;        \n");
		GotoXY(80, 10);
		printf("      ...........       \n");
		GotoXY(80, 11);
		printf("     ,............      \n");
		GotoXY(80, 12);
		printf("    ...............     \n");
		GotoXY(80, 13);
		printf("   .................    \n");
		GotoXY(80, 14);
		printf("  ~.................,   \n");
		GotoXY(80, 15);
		printf(" ~...................~  \n");
		GotoXY(80, 16);
		printf(" .....................  \n");
		GotoXY(80, 17);
		printf(".........,----,---~~~:* \n");
		GotoXY(80, 18);
		printf(" -.....-~-----------~!  \n");
		GotoXY(80, 19);
		printf(" ;......~----------.~   \n");
		GotoXY(80, 20);
		printf("  ......----------..:   \n");
		GotoXY(80, 21);
		printf("  ..,....------~~~-.!   \n");
		GotoXY(80, 22);
		printf("  .. ....,~--~~-~  ,    \n");
		GotoXY(80, 23);
		printf("  ;.  ....-~~~-.-  -    \n");
		GotoXY(80, 24);
		printf("   .  =.,,,~~~.,!  :    \n");
		GotoXY(80, 25);
		printf("      =.,---~~,-        \n");
		GotoXY(80, 26);
		printf("        ,  ~; ~~        \n");
		GotoXY(80, 27);
		printf("       =#      :        \n");
		GotoXY(80, 28);
		printf("       =#      #        \n");
	}
}

void UseCard(int num) {
	if (num == 0) { //타격
		Info.energy--;
		Enemy.hp = Enemy.hp - 6 - Player.power;
		Player.hp -= 10;
	}
	else if (num == 2) { //수비
		Info.energy--;
		Player.shield += 5;
	}
	else if (num == 3) { //강타
		Info.energy -= 2;
		Enemy.hp = Enemy.hp - 8 - Player.power;
		Player.power++;
	}
	else if (num == 4) { //완벽한 타격
		Info.energy -= 2;
		Enemy.hp = Enemy.hp - 16 - Player.power;
	}
	else if (num == 5) { //발화
		Info.energy--;
		Player.power += 2;
	}
	else if (num == 6) { //철의 파동
		Info.energy--;
		Player.shield = 5;
		Enemy.hp -= 5;
	}
	else if (num == 7) { //사혈
		Player.hp -= 3;
		Info.energy += 2;
	}
	else if (num == 8) { //연타
		Info.energy--;
		for (int i = 0; i < 4; i++) {
			Enemy.hp = Enemy.hp - 2 - Player.power;
		}
	}
	else if (num == 9) { //화형
		Info.energy -= 2;
		Enemy.hp = Enemy.hp - 21 - Player.power;
		Player.power--;
	}
	else if (num == 10) { //제물
		Info.energy += 2;
		Player.hp -= 6;
		Player.power += 2;
	}
	else if (num == 11) { //무적
		Info.energy -= 2;
		Player.shield += 30;
	}
	else if (num == 12) { //악마의 형상
		Info.energy -= 3;
		//매턴 힘 3씩
	}
	else if (num == 13) { //몽둥이질
		Info.energy -= 3;
		Enemy.hp = Enemy.hp - 32 - Player.power;
	}
	else if (num == 14) { //드롭킥
		Info.energy--;
		Enemy.hp = Enemy.hp - 5 - Player.power;
	}

}

void SetGame() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Clear();
	Music_Round1();

	//첫 기본세팅
	Info.energy = 3;
	Info.Non_Picked_Card = 10;
	Info.Picked_Card = 0;
	Info.stair = 1;
	Info.Turn_End = 0;
	Info.Deck_count = 10;

	// 플레이어 기본세팅
	Player.Mydeck = Init_Card();
	Player.hp = 80;
	Player.power = 0;
	Player.shield = 0;
	MixCard(Info.Deck_count, Player.Mydeck);

	

	// 현재 스텟을 표기하기 위한 창분리 위쪽 체력창칸 분리 등.
	GotoXY(0, 0);
	DrawBox(120, 30);
	for (int i = 3; i < 119; i++) {
		GotoXY(i, 3);
		printf("-");
	} 
	
	SET_GREEN
	GotoXY(27, 32);
	printf("턴을 종료하려면 E를 누르십시오");
	GotoXY(73, 32);
	printf("선택할 카드를 G,H,J,K,L순으로 입력하시오");
	GotoXY(3, 2);
	printf("Player");
	GotoXY(12, 2);
	printf("♥ %d/80", Player.hp);
	GotoXY(30, 2);
	printf("%d층", Info.stair);
	GotoXY(50, 2);
	printf("에너지 (%d/3)", Info.energy);
	GotoXY(80, 2);
	SET_RED
		printf("적의 체력 %d/20", Enemy.hp);
	SET_WHITE

	//내 캐릭터 그리기
	MyCharacterDraw(hConsole);
	DrawEnemyCharacter(Info.stair);

	while (1) {
		if (kbhit())
		{
			char temp = getch();
			if (temp == 103) {
				//1번 카드 사용 후 적 체력 감소등 처리
				Clear();
				UseCard(Deck_sequence[0]);
				Update_Round(Info.stair);
			}
			else if (temp == 104) {
				//2번 카드 사용 후 적 체력 감소등 처리
				UseCard(Deck_sequence[1]);
				Clear();
				Update_Round(Info.stair);
			}
			else if (temp == 105) {
				//1번 카드 사용 후 적 체력 감소등 처리
				UseCard(Deck_sequence[2]);
				Clear();
				Update_Round(Info.stair);
			}
			else if (temp == 106) {
				//1번 카드 사용 후 적 체력 감소등 처리
				UseCard(Deck_sequence[3]);
				Clear();
				Update_Round(Info.stair);
			}
			else if (temp == 107) {
				//1번 카드 사용 후 적 체력 감소등 처리
				UseCard(Deck_sequence[4]);
				Clear();
				Update_Round(Info.stair);
			}
			else if (temp == 101) {
				Info.Turn_End = 1;
				Clear();
				Update_Round(Info.stair);
			}
		}
	}
}

void Update_Round(int stair) {
	if (Enemy.hp <= 0) {
		//Round_Clear();
	}
	else if (Player.hp <= 0) {
		StopSound();
		Music_GameOver();
		GameOverDraw();
		Sleep(37000); //GameOver.mp3의 노래 재생시간 37초동안 재생 후 종료
		exit(1);
	}
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// 현재 스텟을 표기하기 위한 창분리 위쪽 체력창칸 분리 등.
	GotoXY(0, 0);
	DrawBox(120, 30);
	for (int i = 3; i < 119; i++) {
		GotoXY(i, 3);
		printf("-");
	}

	SET_GREEN
	GotoXY(27, 32);
	printf("턴을 종료하려면 E를 누르십시오");
	GotoXY(73, 32);
	printf("선택할 카드를 G,H,J,K,L순으로 입력하시오");
	GotoXY(3, 2);
	printf("Player");
	GotoXY(12, 2);
	printf("♥ %d/80", Player.hp);
	GotoXY(30, 2);
	printf("%d층", Info.stair);
	GotoXY(50, 2);
	printf("에너지 (%d/3)", Info.energy);
	GotoXY(80, 2);
	SET_RED
	printf("적의 체력 %d/20", Enemy.hp);
	SET_WHITE

	MyCharacterDraw(hConsole);
	DrawEnemyCharacter(Info.stair);
}

void Round_Clear(int stair) {
	Clear();
	if (stair == 10) {
		//게임 클리어 화면 띄우기
		//Game_Clear();
	}
	else {
		Info.stair++;
		//다음 라운드 진행
	}
}