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
	GotoXY(46, 32);
	printf("턴을 종료하려면 E를 누르십시오");
	GotoXY(3, 2);
	printf("Player");
	GotoXY(30, 2);
	printf("♥ %d/80", Player.hp);
	GotoXY(70, 2);
	printf("%d층", Info.stair);
	GotoXY(100, 2);
	printf("에너지 (%d/3)", Info.energy);
	SET_WHITE

	//내 캐릭터 그리기
	MyCharacterDraw(hConsole);
	DrawEnemyCharacter(Info.stair);
}

void Play_Round(int stair) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	MyCharacterDraw(hConsole);
	DrawEnemyCharacter(Info.stair);
	Player.power = 0;
	Player.shield = 0;
	Info.energy = 3;
	Info.stair++;
	Info.Turn_End = 0;	
}

void Round_Clear(int stair) {
	Clear();
	if (stair == 10) {
		//게임 클리어 화면 띄우기
	}
	else {
		Play_Round(stair);
	}
}