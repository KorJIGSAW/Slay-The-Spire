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
EnemyCharacter Enemy[10];


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
		Enemy[Info.stair-1].hp = Enemy[Info.stair-1].hp - 6 - Player.power;
	}
	else if (num == 1) { //수비
		Info.energy--;
		Player.shield += 5;
	}
	else if (num == 2) { //강타
		Info.energy -= 2;
		Enemy[Info.stair-1].hp -= 8 + Player.power;
		Player.power++;
	}
	else if (num == 3) { //완벽한 타격
		Info.energy -= 2;
		Enemy[Info.stair-1].hp = Enemy[Info.stair-1].hp - 16 - Player.power;
	}
	else if (num == 4) { //발화
		Info.energy--;
		Player.power += 2;
	}
	else if (num == 5) { //철의 파동
		Info.energy--;
		Player.shield = 5;
		Enemy[Info.stair-1].hp -= 5;
	}
	else if (num == 6) { //사혈
		Player.hp -= 3;
		Info.energy += 2;
	}
	else if (num == 7) { //연타
		Info.energy--;
		for (int i = 0; i < 4; i++) {
			Enemy[Info.stair-1].hp = Enemy[Info.stair-1].hp - 2 - Player.power;
		}
	}
	else if (num == 8) { //화형
		Info.energy -= 2;
		Enemy[Info.stair-1].hp = Enemy[Info.stair-1].hp - 21 - Player.power;
		Player.power--;
	}
	else if (num == 9) { //제물
		Info.energy += 2;
		Player.hp -= 6;
		Player.power += 2;
	}
	else if (num == 10) { //무적
		Info.energy -= 2;
		Player.shield += 30;
	}
	else if (num == 11) { //악마의 형상
		Info.energy -= 3;
		//매턴 힘 3씩
	}
	else if (num == 12) { //몽둥이질
		Info.energy -= 3;
		Enemy[Info.stair-1].hp = Enemy[Info.stair-1].hp - 32 - Player.power;
	}
	else if (num == 13) { //드롭킥
		Info.energy--;
		Enemy[Info.stair-1].hp = Enemy[Info.stair-1].hp - 5 - Player.power;
	}

}

void SetGame() {
	Enemy[0].hp = 14;
	Enemy[1].hp = 15;
	Enemy[2].hp = 40;
	Enemy[3].hp = 50;
	Enemy[4].hp = 48;
	Enemy[5].hp = 20;
	Enemy[6].hp = 60;
	Enemy[7].hp = 75;
	Enemy[8].hp = 100;
	Enemy[9].hp = 150;

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
	
	for (int i = 0; i < 10; i++) {
		MixCard(Info.Deck_count, Player.Mydeck);
	}

	// 현재 스텟을 표기하기 위한 창분리 위쪽 체력창칸 분리 등.
	GotoXY(0, 0);
	DrawBox(120, 30);
	for (int i = 3; i < 119; i++) {
		GotoXY(i, 3);
		printf("-");
	} 
	
	SET_GREEN
		GotoXY(20, 32);
	printf("턴을 종료하려면 E를 누르십시오");
	GotoXY(60, 32);
	printf("선택할 카드를 1~5순으로 입력하시오");
	GotoXY(3, 2);
	printf("Player");
	GotoXY(12, 2);
	printf("♥ %d/80", Player.hp);
	GotoXY(22, 2);
	printf("%d층", Info.stair);
	GotoXY(32, 2);
	printf("힘 : %d", Player.power);
	GotoXY(50, 2);
	printf("에너지 (%d/3)", Info.energy);
	GotoXY(100, 2);
	SET_RED
		if (Info.stair == 1) {
			printf("적의 체력 %d/14", Enemy[Info.stair - 1].hp);
		}
		else if (Info.stair == 2) {
			printf("적의 체력 %d/15", Enemy[Info.stair - 1].hp);
		}
		else if (Info.stair == 3) {
			printf("적의 체력 %d/40", Enemy[Info.stair - 1].hp);
		}
		else if (Info.stair == 4) {
			printf("적의 체력 %d/50", Enemy[Info.stair - 1].hp);
		}
		else if (Info.stair == 5) {
			printf("적의 체력 %d/48", Enemy[Info.stair - 1].hp);
		}
		else if (Info.stair == 6) {
			printf("적의 체력 %d/20", Enemy[Info.stair - 1].hp);
		}
		else if (Info.stair == 7) {
			printf("적의 체력 %d/60", Enemy[Info.stair - 1].hp);
		}
		else if (Info.stair == 8) {
			printf("적의 체력 %d/75", Enemy[Info.stair - 1].hp);
		}
		else if (Info.stair == 9) {
			printf("적의 체력 %d/100", Enemy[Info.stair - 1].hp);
		}
		else if (Info.stair == 10) {
			printf("적의 체력 %d/150", Enemy[Info.stair - 1].hp);
		}
	SET_WHITE

	//내 캐릭터 그리기
	MyCharacterDraw(hConsole);
	DrawEnemyCharacter(Info.stair);

	while (1) {
		if (kbhit())
		{
			char temp = getch();
			if (temp == 49) {
				//1번 카드 사용 후 적 체력 감소등 처리
				if (Info.energy - card[Deck_sequence[0]].energy < 0) {
					GotoXY(45, 20);
					SET_GREEN
					printf("에너지가 부족합니다!");
					Sleep(1000);
					Clear();
					SET_WHITE
					Update_Round(Info.stair);
					Deck_print(Player.Mydeck);
					continue;
				}
				Clear();
				UseCard(Deck_sequence[0]);
				Update_Round(Info.stair);
				Deck_print(Player.Mydeck);
			}
			else if (temp == 50) {
				//2번 카드 사용 후 적 체력 감소등 처리
				if (Info.energy - card[Deck_sequence[1]].energy < 0) {
					GotoXY(45, 20);
					SET_GREEN
						printf("에너지가 부족합니다!");
					Sleep(1000);
					Clear();
					SET_WHITE
					Update_Round(Info.stair);
					Deck_print(Player.Mydeck);
					continue;
				}
				UseCard(Deck_sequence[1]);
				Clear();
				Update_Round(Info.stair);
				Deck_print(Player.Mydeck);
			}
			else if (temp == 51) {
				//3번 카드 사용 후 적 체력 감소등 처리
				if (Info.energy - card[Deck_sequence[2]].energy < 0) {
					GotoXY(45, 20);
					SET_GREEN
						printf("에너지가 부족합니다!");
					Sleep(1000);
					Clear();
					SET_WHITE
					Update_Round(Info.stair);
					Deck_print(Player.Mydeck);
					continue;
				}
				UseCard(Deck_sequence[2]);
				Clear();
				Update_Round(Info.stair);
				Deck_print(Player.Mydeck);
			}
			else if (temp == 52) {
				//4번 카드 사용 후 적 체력 감소등 처리
				if (Info.energy - card[Deck_sequence[3]].energy < 0) {
					GotoXY(45, 20);
					SET_GREEN
						printf("에너지가 부족합니다!");
					Sleep(1000);
					Clear();
					SET_WHITE
						Update_Round(Info.stair);
					Deck_print(Player.Mydeck);
					continue;
				}
				UseCard(Deck_sequence[3]);
				Clear();
				Update_Round(Info.stair);
				Deck_print(Player.Mydeck);
			}
			else if (temp == 53) {
				//5번 카드 사용 후 적 체력 감소등 처리
				if (Info.energy - card[Deck_sequence[4]].energy < 0) {
					GotoXY(45, 20);
					SET_GREEN
						printf("에너지가 부족합니다!");
					Sleep(1000);
					Clear();
					SET_WHITE
						Update_Round(Info.stair);
					Deck_print(Player.Mydeck);
					continue;
				}
				UseCard(Deck_sequence[4]);
				Clear();
				Update_Round(Info.stair);
				Deck_print(Player.Mydeck);
			}
			else if (temp == 54) {
				Info.Turn_End = 1;
				Clear();
				Update_Round(Info.stair);
				Deck_print(Player.Mydeck);
			}
		}
	}
}

void Round_Clear(int stair) {
	Clear();
	if (stair == 10) {
		//게임 클리어 화면 띄우기
		//Game_Clear();
	}
	else {
		//다음 라운드 진행
		Info.stair++;
		//카드 보상 3중 1택
		//Choose_Card();
		Clear();
		SET_GREEN
			//3번 깜박임
			GotoXY(50, 20);
		printf("다음 층 : %d층", Info.stair);
		Sleep(500);
		Clear();
		Sleep(500);
		GotoXY(50, 20);
		printf("다음 층 : %d층", Info.stair);
		Sleep(500);
		Clear();
		Sleep(500);
		GotoXY(50, 20);
		printf("다음 층 : %d층", Info.stair);
		Sleep(500);
		Clear();
		Sleep(500);
			SET_WHITE
		for (int i = 0; i < 10; i++) {
			MixCard(Info.Deck_count, Player.Mydeck);
		}
		Info.energy = 3;
		Info.Turn_End = 0;
		Player.power = 0;
		Player.shield = 0;
		if (Info.stair == 2) {
			StopSound();
			Music_Round2();
		}
		else if (Info.stair == 3) {
			StopSound();
			Music_Round3();
		}
		else if (Info.stair == 4) {
			StopSound();
			Music_Round4();
		}
		else if (Info.stair == 5) {
			StopSound();
			Music_Round5();
		}
		else if (Info.stair == 6) {
			StopSound();
			Music_Round6();
		}
		else if (Info.stair == 7) {
			StopSound();
			Music_Round7();
		}
		else if (Info.stair == 8) {
			StopSound();
			Music_Round8();
		}
		else if (Info.stair == 9) {
			StopSound();
			Music_Round9();
		}
		else if (Info.stair == 10) {
			StopSound();
			Music_Round10();
		}
	}
}

void Update_Round(int stair) {
	if (Enemy[stair-1].hp <= 0) {
		Round_Clear(Info.stair);
		SET_RED
			/*
			* if (Info.stair == 1) {
				printf("적의 체력 %d/14", Enemy[Info.stair - 1].hp);
			}
			else if (Info.stair == 2) {
				printf("적의 체력 %d/15", Enemy[Info.stair - 1].hp);
			}
			else if (Info.stair == 3) {
				printf("적의 체력 %d/40", Enemy[Info.stair - 1].hp);
			}
			else if (Info.stair == 4) {
				printf("적의 체력 %d/50", Enemy[Info.stair - 1].hp);
			}
			else if (Info.stair == 5) {
				printf("적의 체력 %d/48", Enemy[Info.stair - 1].hp);
			}
			else if (Info.stair == 6) {
				printf("적의 체력 %d/20", Enemy[Info.stair - 1].hp);
			}
			else if (Info.stair == 7) {
				printf("적의 체력 %d/60", Enemy[Info.stair - 1].hp);
			}
			else if (Info.stair == 8) {
				printf("적의 체력 %d/75", Enemy[Info.stair - 1].hp);
			}
			else if (Info.stair == 9) {
				printf("적의 체력 %d/100", Enemy[Info.stair - 1].hp);
			}
			else if (Info.stair == 10) {
				printf("적의 체력 %d/150", Enemy[Info.stair - 1].hp);
			}
			*/
			
		SET_WHITE
	}
	if (Player.hp <= 0) {
		Music_GameOver(); 
		//3번 깜박임.
		Clear();
		GotoXY(50, 20);
		printf("플레이어의 체력이 모두 소진되었습니다!");
		Sleep(500);
		Clear();
		Sleep(500);
		GotoXY(50, 20);
		printf("플레이어의 체력이 모두 소진되었습니다!");
		Sleep(500);
		Clear();
		Sleep(500);
		GotoXY(50, 20);
		printf("플레이어의 체력이 모두 소진되었습니다!");
		Sleep(500);

		StopSound();
		GameOverDraw();
		Sleep(40000); //GameOver.mp3의 노래 재생시간 37초동안 재생 후 종료 + 플레이어 체력소진창 3초
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
	GotoXY(20, 32);
	printf("턴을 종료하려면 E를 누르십시오");
	GotoXY(60, 32);
	printf("선택할 카드를 1~5순으로 입력하시오");
	GotoXY(3, 2);
	printf("Player");
	GotoXY(12, 2);
	printf("♥ %d/80", Player.hp);
	GotoXY(22, 2);
	printf("%d층", Info.stair);
	GotoXY(32, 2);
	printf("힘 : %d", Player.power);
	GotoXY(50, 2);
	printf("에너지 (%d/3)", Info.energy);
	GotoXY(100, 2);
	SET_RED
		if (Info.stair == 1) {
			printf("적의 체력 %d/14", Enemy[0].hp);
		}
		else if (Info.stair == 2) {
			printf("적의 체력 %d/15", Enemy[1].hp);
		}
		else if (Info.stair == 3) {
			printf("적의 체력 %d/40", Enemy[2].hp);
		}
		else if (Info.stair == 4) {
			printf("적의 체력 %d/50", Enemy[3].hp);
		}
		else if (Info.stair == 5) {
			printf("적의 체력 %d/48", Enemy[4].hp);
		}
		else if (Info.stair == 6) {
			printf("적의 체력 %d/20", Enemy[5].hp);
		}
		else if (Info.stair == 7) {
			printf("적의 체력 %d/60", Enemy[6].hp);
		}
		else if (Info.stair == 8) {
			printf("적의 체력 %d/75", Enemy[7].hp);
		}
		else if (Info.stair == 9) {
			printf("적의 체력 %d/100", Enemy[8].hp);
		}
		else if (Info.stair == 10) {
			printf("적의 체력 %d/150", Enemy[9].hp);
		}
	SET_WHITE

	MyCharacterDraw(hConsole);
	DrawEnemyCharacter(Info.stair);
}
