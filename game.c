#include <stdio.h>
#include "game.h"
#include "status.h"
#include "console.h"
#include "draw.h"
#include "character.h"
#include "CSound.h"
#include "card.h"
#include <time.h>

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
		Enemy[Info.stair-1].hp -= 50 + Player.power - Enemy[Info.stair - 1].shield;
	}
	else if (num == 1) { //수비
		Info.energy--;
		Player.shield += 5;
	}
	else if (num == 2) { //강타
		Info.energy -= 2;
		Enemy[Info.stair-1].hp -= 8 + Player.power - Enemy[Info.stair - 1].shield;
		Player.power++;
	}
	else if (num == 3) { //완벽한 타격
		Info.energy -= 2;
		Enemy[Info.stair-1].hp -= 16 + Player.power - Enemy[Info.stair - 1].shield;
	}
	else if (num == 4) { //발화
		Info.energy--;
		Player.power += 2;
	}
	else if (num == 5) { //철의 파동
		Info.energy--;
		Player.shield = 5;
		Enemy[Info.stair-1].hp -= 5 + Player.power - Enemy[Info.stair - 1].shield;
	}
	else if (num == 6) { //사혈
		Player.hp -= 3;
		Info.energy += 2;
	}
	else if (num == 7) { //연타
		Info.energy--;
		for (int i = 0; i < 4; i++) {
			Enemy[Info.stair-1].hp -= 2 + Player.power - Enemy[Info.stair - 1].shield;
		}
	}
	else if (num == 8) { //화형
		Info.energy -= 2;
		Enemy[Info.stair-1].hp -= 21 + Player.power - Enemy[Info.stair - 1].shield;
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
		Enemy[Info.stair-1].hp -= 32 + Player.power - Enemy[Info.stair - 1].shield;
	}
	else if (num == 13) { //드롭킥
		Info.energy--;
		Enemy[Info.stair-1].hp -= 5 + Player.power - Enemy[Info.stair - 1].shield;
	}

}
void Enemy_Set_Zero() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 5; j++) {
			Enemy[i].pattern[j].Enemy_damage = 0;
			Enemy[i].pattern[j].Enemy_protect = 0;
			Enemy[i].pattern[j].is_buff = 0;
			Enemy[i].pattern[j].is_damage = 0;
			Enemy[i].pattern[j].is_protect = 0;
			Enemy[i].pattern[j].power_raise = 0;
		}
	}
}
void Enemy_Pattern_Set(int random) {
	//몬스터들의 패턴 설정
	//슬라임의 공격 : 0, 수비 : 1, 플레이어 힘 감소 : 2 
	//다른 행동을 하고 공격 수비시 전에 했던 행동까지 저장되어 있다. 초기화 필요..
	Enemy_Set_Zero();
	if (Info.stair == 1 && random == 0) {
		//슬라임의 공격 설정
		Enemy[0].pattern[0].Enemy_damage = 4;
		Enemy[0].pattern[0].is_damage = 1;
	}
	else if (Info.stair == 1 && random == 1) {
		//슬라임의 수비 설정
		Enemy[0].pattern[1].Enemy_protect = 5;
		Enemy[0].pattern[1].is_protect = 1;
	}
	else if (Info.stair == 1 && random == 2) {
		//슬라임의 디버프 설정
		//플레이어의 힘감소
		Enemy[0].pattern[2].is_buff = 1;
	}
	else if (Info.stair == 2 && random == 0) {
		//공벌레의 공격 설정
		Enemy[1].pattern[0].Enemy_damage = 7;
		Enemy[1].pattern[0].is_damage = 1;
	}
	else if (Info.stair == 2 && random == 1) {
		//공벌레의 수비 설정
		Enemy[Info.stair - 1].pattern[1].Enemy_protect = 7;
		Enemy[Info.stair - 1].pattern[1].is_protect = 1;
	}
	else if (Info.stair == 2 && random == 2) {
		//공벌레의 힘증가3
		Enemy[Info.stair - 1].pattern[2].is_buff = 1;
	}
	else if (Info.stair == 2 && random == 3) {
		//공벌레의 플레이어 힘감소1
		//플레이어의 힘감소
		Enemy[Info.stair - 1].pattern[2].is_buff = 1;
	}
	else if (Info.stair == 3 && random == 0) {
		//턱벌레의 공격11
		Enemy[Info.stair - 1].pattern[0].Enemy_damage = 11;
		Enemy[Info.stair - 1].pattern[0].is_damage = 1;
	}
	else if (Info.stair == 3 && random == 1) {
		//턱벌레의 공격7
		Enemy[Info.stair - 1].pattern[random].Enemy_damage = 7;
		Enemy[Info.stair - 1].pattern[random].is_damage = 1;
	}
	else if (Info.stair == 3 && random == 2) {
		//턱벌레의 방어도6
		Enemy[Info.stair - 1].pattern[random].Enemy_protect = 6;
		Enemy[Info.stair - 1].pattern[random].is_protect = 1;
	}
	else if (Info.stair == 3 && random == 3) {
		//턱벌레의 힘증가5
		Enemy[Info.stair - 1].pattern[random].is_buff = 1;
	}
	else if (Info.stair == 4 && random == 0) {
		//보초기의 공격10
		Enemy[Info.stair - 1].pattern[random].Enemy_damage = 10;
		Enemy[Info.stair - 1].pattern[random].is_damage = 1;
	}
	else if (Info.stair == 4 && random == 1) {
		//보초기의 플레이어 힘감소1
		Enemy[Info.stair - 1].pattern[random].is_buff = 1;
	}
	else if (Info.stair == 4 && random == 2) {
		//보초기의 공격20
		Enemy[Info.stair - 1].pattern[random].Enemy_damage = 20;
		Enemy[Info.stair - 1].pattern[random].is_damage = 1;
	}
	else if (Info.stair == 5 && random == 0) {
		//카카의 공격6 and 힘증가2
		Enemy[Info.stair - 1].pattern[random].Enemy_damage = 6;
		Enemy[Info.stair - 1].pattern[random].is_damage = 1;
		Enemy[Info.stair - 1].pattern[random].is_buff = 1;
	}
	else if (Info.stair == 6 && random == 0) {
		//수호기의 방어도 25
		Enemy[Info.stair - 1].pattern[random].Enemy_protect = 25;
		Enemy[Info.stair - 1].pattern[random].is_protect = 1;
	}
	else if (Info.stair == 6 && random == 1) {
		//수호기의 공격10
		Enemy[Info.stair - 1].pattern[random].Enemy_damage = 10;
		Enemy[Info.stair - 1].pattern[random].is_damage = 1;
	}
	else if (Info.stair == 6 && random == 2) {
		//수호기의 방어도10
		Enemy[Info.stair - 1].pattern[random].Enemy_protect = 10;
		Enemy[Info.stair - 1].pattern[random].is_protect = 1;
	}
	else if (Info.stair == 6 && random == 3) {
		//수호기의 공격5
		Enemy[Info.stair - 1].pattern[random].Enemy_damage = 5;
		Enemy[Info.stair - 1].pattern[random].is_damage = 1;
	}
	else if (Info.stair == 7 && random == 0) {
		//스네코의 플레이어힘감소1
		Enemy[Info.stair - 1].pattern[random].is_buff = 1;
	}
	else if (Info.stair == 7 && random == 1) {
		//스네코의 공격15
		Enemy[Info.stair - 1].pattern[random].Enemy_damage = 15;
		Enemy[Info.stair - 1].pattern[random].is_damage = 1;
	}
	else if (Info.stair == 7 && random == 2) {
		//스네코의 공격8
		Enemy[Info.stair - 1].pattern[random].Enemy_damage = 8;
		Enemy[Info.stair - 1].pattern[random].is_damage = 1;
	}
	else if (Info.stair == 8 && random == 0) {
		//대왕슬라임의 플레이어 힘감소2
		Enemy[Info.stair - 1].pattern[random].is_buff = 1;
	}
	else if (Info.stair == 8 && random == 1) {
		//대왕슬라임의 공격20
		Enemy[Info.stair - 1].pattern[random].Enemy_damage = 20;
		Enemy[Info.stair - 1].pattern[random].is_damage = 1;
	}
	else if (Info.stair == 8 && random == 2) {
		//대왕슬라임의 ?아무것도 하지않는다.
		GotoXY(60, 45);
		printf("대왕슬라임이 에너지를 충전중입니다..");
	}
	else if (Info.stair == 9 && random == 0) {
		//도누의 플레이어 힘감소1
		Enemy[Info.stair - 1].pattern[random].is_buff = 1;
	}
	else if (Info.stair == 9 && random == 1) {
		//도누의 공격 20
		Enemy[Info.stair - 1].pattern[random].Enemy_damage = 20;
		Enemy[Info.stair - 1].pattern[random].is_damage = 1;
	}
	else if (Info.stair == 9 && random == 2) {
		//도누의 방어도 10
		Enemy[Info.stair - 1].pattern[random].Enemy_protect = 10;
		Enemy[Info.stair - 1].pattern[random].is_protect = 1;
	}
	else if (Info.stair == 10 && random == 0) {
		//데카의 플레이어 힘감소1
		Enemy[Info.stair - 1].pattern[random].is_buff = 1;
	}
	else if (Info.stair == 10 && random == 1) {
		//데카의 공격 22
		Enemy[Info.stair - 1].pattern[random].Enemy_damage = 22;
		Enemy[Info.stair - 1].pattern[random].is_damage = 1;
	}
	else if (Info.stair == 10 && random == 2) {
		//방어력 10
		Enemy[Info.stair - 1].pattern[random].Enemy_protect = 10;
		Enemy[Info.stair - 1].pattern[random].is_protect = 1;
	}
}
int randnum;
void RanPick_Enemy_Pattern(int stair) {
	srand((unsigned)time(NULL));

	if (stair == 1 || stair == 4 || stair == 7 || stair == 8 || stair == 9 || stair == 10) {
		randnum = rand() % 3;
	}
	else if (stair == 2 || stair == 3 || stair == 6) {
		randnum = rand() % 4;
	}
	else if (stair == 5) {
		randnum = 0;
	}
	Enemy_Pattern_Set(randnum);
}


void End_Turn() {
	Enemy_damage_buff_defense(randnum);
	Clear();
	Info.energy = 3;
	Info.Turn_End = 0;
	Player.shield = 0;
	RanPick_Enemy_Pattern(Info.stair);
	Update_Round(Info.stair);
}

void Enemy_Set() {
	//몬스터들의 체력 설정
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
}

void Enemy_damage_buff_defense(int random) {
	if (Info.stair == 1 && random == 0) {
		//슬라임의 공격 설정
		if (Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield >= 0){
			Player.hp -= Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield;
		}
	}
	else if (Info.stair == 1 && random == 1) {
		//슬라임의 수비 설정
		Enemy[Info.stair - 1].shield += 5;
	}
	else if (Info.stair == 1 && random == 2) {
		//슬라임의 디버프 설정
		//플레이어의 힘감소
		Player.power--;
	}
	else if (Info.stair == 2 && random == 0) {
		//공벌레의 공격 설정
		if (Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield >= 0){
		Player.hp -= Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield;
	}
	}
	else if (Info.stair == 2 && random == 1) {
		//공벌레의 수비 설정
		Enemy[Info.stair - 1].shield += 7;
	}
	else if (Info.stair == 2 && random == 2) {
		//공벌레의 힘증가3
		Enemy[Info.stair - 1].power += 3;
	}
	else if (Info.stair == 2 && random == 3) {
		//공벌레의 플레이어 힘감소1
		//플레이어의 힘감소
		Player.power--;
	}
	else if (Info.stair == 3 && random == 0) {
		//턱벌레의 공격10;
		if (Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield >= 0) {
			Player.hp -= Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield;
		}
	}
	else if (Info.stair == 3 && random == 1) {
		//턱벌레의 공격7
		if (Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield >= 0) {
			Player.hp -= Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield;
		}
	}
	else if (Info.stair == 3 && random == 2) {
		//턱벌레의 방어도6
		Enemy[Info.stair-1].shield += 6;
	}
	else if (Info.stair == 3 && random == 3) {
		//턱벌레의 힘증가5
		Enemy[Info.stair-1].power = +5;
	}
	else if (Info.stair == 4 && random == 0) {
		//보초기의 공격10 
		if (Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield >= 0) {
			Player.hp -= Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield;
		}
	}
	else if (Info.stair == 4 && random == 1) {
		//보초기의 플레이어 힘감소1
		Player.power--;
	}
	else if (Info.stair == 4 && random == 2) {
		//보초기의 공격20 
		if (Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield >= 0) {
			Player.hp -= Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield;
		}
	}
	else if (Info.stair == 5 && random == 0) {
		//카카의 공격6 and 힘증가2
		Enemy[Info.stair - 1].power += 2;
	}
	else if (Info.stair == 6 && random == 0) {
		//수호기의 방어도 25
	}
	else if (Info.stair == 6 && random == 1) {
		//수호기의 공격10
		if (Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield >= 0) {
			Player.hp -= Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield;
		}
	}
	else if (Info.stair == 6 && random == 2) {
		//수호기의 방어도10
		Enemy[Info.stair - 1].shield += 10;
	}
	else if (Info.stair == 6 && random == 3) {
		//수호기의 공격5
		if (Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield >= 0) {
			Player.hp -= Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield;
		}
	}
	else if (Info.stair == 7 && random == 0) {
		//스네코의 플레이어힘감소1
	}
	else if (Info.stair == 7 && random == 1) {
		//스네코의 공격15
		if (Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield >= 0) {
			Player.hp -= Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield;
		}
	}
	else if (Info.stair == 7 && random == 2) {
		//스네코의 공격8
		if (Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield >= 0) {
			Player.hp -= Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield;
		}
	}
	else if (Info.stair == 8 && random == 0) {
		//대왕슬라임의 플레이어 힘감소2
		Player.power -= 2;
	}
	else if (Info.stair == 8 && random == 1) {
		//대왕슬라임의 공격20
		if (Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield >= 0) {
			Player.hp -= Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield;
		}
	}
	else if (Info.stair == 8 && random == 2) {
		//대왕슬라임의 ?아무것도 하지않는다.
		GotoXY(60, 45);
		printf("대왕슬라임이 에너지를 충전중입니다..");
	}
	else if (Info.stair == 9 && random == 0) {
		//도누의 플레이어 힘감소1
		Player.power--;
	}
	else if (Info.stair == 9 && random == 1) {
		//도누의 공격 20
		if (Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield >= 0) {
			Player.hp -= Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield;
		}
	}
	else if (Info.stair == 9 && random == 2) {
		//도누의 방어도 10
		Enemy[Info.stair - 1].shield += 10;
	}
	else if (Info.stair == 10 && random == 0) {
		//데카의 플레이어 힘감소1
		Player.power--;
	}
	else if (Info.stair == 10 && random == 1) {
		//데카의 공격 22
		if (Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield >= 0) {
			Player.hp -= Enemy[Info.stair - 1].pattern[random].Enemy_damage + Enemy[Info.stair - 1].power - Player.shield;
		}
	}
	else if (Info.stair == 10 && random == 2) {
		//방어력 10
		Enemy[Info.stair - 1].shield += 10;
	}
}




void SetGame() { 
	Enemy_Set();
	RanPick_Enemy_Pattern(Info.stair);
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
	Info.Turn_Count = 1;

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
	GotoXY(40, 2);
	printf("에너지 (%d/3)", Info.energy);
	GotoXY(55, 2);
	printf("내 방어도 : %d", Player.shield);
	RanPick_Enemy_Pattern(Info.stair);
	
	SET_RED
		GotoXY(70, 2);
	if (Enemy[Info.stair - 1].pattern[randnum].is_damage == 1) {
		printf("몬스터 : %d만큼 공격합니다!", Enemy[Info.stair - 1].pattern[randnum].Enemy_damage);
	}
	else if (Enemy[Info.stair - 1].pattern[randnum].is_protect == 1) {
		printf("몬스터 : %d만큼 방어합니다!", Enemy[Info.stair - 1].pattern[randnum].Enemy_protect);
	}
	else if (Enemy[Info.stair - 1].pattern[randnum].is_buff == 1) {
		printf("몬스터 : 디버프를 사용합니다!");
	}
	GotoXY(100, 2);
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
			else if (temp == 'e' || temp == 'E') {
				Info.Turn_End = 1;
				Info.Turn_Count++;
				Clear();
				SET_GREEN
					GotoXY(45, 20);
				if (Enemy[Info.stair - 1].pattern[randnum].is_damage == 1) {
					printf("몬스터가 플레이어에게 %d만큼 공격합니다!", Enemy[Info.stair - 1].pattern[randnum].Enemy_damage);
				}
				else if (Enemy[Info.stair - 1].pattern[randnum].is_protect == 1) {
					printf("몬스터가 %d만큼 방어도를 올립니다!", Enemy[Info.stair - 1].pattern[randnum].Enemy_protect);
				}
				else if (Enemy[Info.stair - 1].pattern[randnum].is_buff == 1) {
					printf("몬스터가 디버프를 사용합니다!");
				}
				Sleep(1000);
				SET_WHITE
				Clear();
				End_Turn();
				Deck_print(Player.Mydeck);
			}
		}
	}
}

void Choose_Card(int a, int b, int c) {
	GotoXY(30, 10);
	SET_GREEN
		printf("%d층을 클리어 하셨습니다! 보상으로 덱에 추가할 카드를 1~3사이로 선택하세요!", Info.stair);

	GotoXY(30, 20);
	printf("1.%s", card[a].name);
	SET_WHITE
	GotoXY(30, 21);
	if (a == 0) { //타격
		printf("에너지 : 1");
		GotoXY(30, 22);
		printf("데미지 : 6");
	}
	else if (a == 1) { //수비
		printf("에너지 : 1\n");
		GotoXY(30, 22);;
		printf("방어력 : 5\n");
	}
	else if (a == 2) { //강타
		printf("에너지 : 2\n");
		GotoXY(30, 22);
		printf("데미지 : 8\n");
		GotoXY(30, 23);
		printf("힘 증가 : 1\n");
	}
	else if (a == 3) { //완벽한 타격
		printf("에너지 : 2\n");
		GotoXY(30, 22);
		printf("보유 타격 : 5장\n");
		GotoXY(30, 23);
		printf("데미지 : 16\n");
	}
	else if (a == 4) {//발화
		printf("에너지 : 1\n");
		GotoXY(30, 22);
		printf("힘 증가 : 3\n");
	}

	else if (a == 5) {//철의 파동
		printf("에너지 : 1\n");
		GotoXY(30, 22);
		printf("데미지 : 5\n");
		GotoXY(30, 23);
		printf("방어력 : 5\n");
	}
	else if (a == 6) {//사혈
		printf("에너지 : 0\n");
		GotoXY(30, 22);
		printf("자가 데미지 : 3\n");
		GotoXY(30, 23);
		printf("에너지 생성 : 2\n");
	}
	else if (a == 7) {//연타
		printf("에너지 : 1\n");
		GotoXY(30, 22);
		printf("데미지 : 2\n");
		GotoXY(30, 23);
		printf("4번 반복 공격\n");
	}
	else if (a == 8) {//화형
		printf("에너지 : 2\n");
		GotoXY(30, 22);
		printf("적군 전체 데미지 : 21\n");
		GotoXY(30, 23);
		printf("힘 감소 : 1");
	}
	else if (a == 9) {//제물
		printf("에너지 : 0\n");
		GotoXY(30, 22);
		printf("자가 데미지 : 6\n");
	}
	else if (a == 10) {//무적
		printf("에너지 : 2\n");
		GotoXY(30, 22);
		printf("방어도 : 30\n");
	}
	else if (a == 11) {//악마의 형상
		printf("에너지 : 3\n");
		GotoXY(30, 22);
		printf("매턴 힘증가 : 3\n");
	}
	else if (a == 12) {//몽둥이질
		printf("에너지 : 3\n");
		GotoXY(30, 22);
		printf("데미지 : 32\n");
	}
	else if (a == 13) {//드롭킥
		printf("에너지 : 1\n");
		GotoXY(30, 22);
		printf("데미지 : 5\n");
		GotoXY(30, 23);
		printf("카드 드로우 : 1장\n");
	}

	SET_GREEN
	GotoXY(60, 20);
	printf("2.%s", card[b].name);
	SET_WHITE
	GotoXY(60, 21);
	if (b == 0) { //타격
		printf("에너지 : 1");
		GotoXY(60, 22);
		printf("데미지 : 6");
	}
	else if (b == 1) { //수비
		printf("에너지 : 1\n");
		GotoXY(60, 22);;
		printf("방어력 : 5\n");
	}
	else if (b == 2) { //강타
		printf("에너지 : 2\n");
		GotoXY(60, 22);
		printf("데미지 : 8\n");
		GotoXY(60, 23);
		printf("힘 증가 : 1\n");
	}
	else if (b == 3) { //완벽한 타격
		printf("에너지 : 2\n");
		GotoXY(60, 22);
		printf("보유 타격 : 5장\n");
		GotoXY(60, 23);
		printf("데미지 : 16\n");
	}
	else if (b == 4) {//발화
		printf("에너지 : 1\n");
		GotoXY(60, 22);
		printf("힘 증가 : 3\n");
	}
	else if (b == 5) {//철의 파동
		printf("에너지 : 1\n");
		GotoXY(60, 22);
		printf("데미지 : 5\n");
		GotoXY(60, 23);
		printf("방어력 : 5\n");
	}
	else if (b == 6) {//사혈
		printf("에너지 : 0\n");
		GotoXY(60, 22);
		printf("자가 데미지 : 3\n");
		GotoXY(60, 23);
		printf("에너지 생성 : 2\n");
	}
	else if (b == 7) {//연타
		printf("에너지 : 1\n");
		GotoXY(60, 22);
		printf("데미지 : 2\n");
		GotoXY(60, 23);
		printf("4번 반복 공격\n");
	}
	else if (b == 8) {//화형
		printf("에너지 : 2\n");
		GotoXY(60, 22);
		printf("적군 전체 데미지 : 21\n");
		GotoXY(60, 23);
		printf("힘 감소 : 1");
	}
	else if (b == 9) {//제물
		printf("에너지 : 0\n");
		GotoXY(60, 22);
		printf("자가 데미지 : 6\n");
		GotoXY(60, 23);
		printf("에너지 생성 : 2\n");
	}
	else if (b == 10) {//무적
		printf("에너지 : 2\n");
		GotoXY(60, 22);
		printf("방어도 : 30\n");
	}
	else if (b == 11) {//악마의 형상
		printf("에너지 : 3\n");
		GotoXY(60, 22);
		printf("매턴 힘증가 : 3\n");
	}
	else if (b == 12) {//몽둥이질
		printf("에너지 : 3\n");
		GotoXY(60, 22);
		printf("데미지 : 32\n");
	}
	else if (b == 13) {//드롭킥
		printf("에너지 : 1\n");
		GotoXY(60, 22);
		printf("데미지 : 5\n");
		GotoXY(60, 23);
		printf("카드 드로우 : 1장\n");
	}

	SET_GREEN
	GotoXY(90, 20);
	printf("3.%s", card[c].name);
	SET_WHITE
	GotoXY(90, 21);
	if (c == 0) { //타격
		printf("에너지 : 1");
		GotoXY(90, 22);
		printf("데미지 : 6");
	}
	else if (c == 1) { //수비
		printf("에너지 : 1\n");
		GotoXY(90, 22);;
		printf("방어력 : 5\n");
	}
	else if (c == 2) { //강타
		printf("에너지 : 2\n");
		GotoXY(90, 22);
		printf("데미지 : 8\n");
		GotoXY(90, 23);
		printf("힘 증가 : 1\n");
	}
	else if (c == 3) { //완벽한 타격
		printf("에너지 : 2\n");
		GotoXY(90, 22);
		printf("보유 타격 : 5장\n");
		GotoXY(90, 23);
		printf("데미지 : 16\n");
	}
	else if (c == 4) {//발화
		printf("에너지 : 1\n");
		GotoXY(90, 22);
		printf("힘 증가 : 3\n");
	}
	else if (c == 5) {//철의 파동
		printf("에너지 : 1\n");
		GotoXY(90, 22);
		printf("데미지 : 5\n");
		GotoXY(90, 23);
		printf("방어력 : 5\n");
	}
	else if (c == 6) {//사혈
		printf("에너지 : 0\n");
		GotoXY(90, 22);
		printf("자가 데미지 : 3\n");
		GotoXY(90, 23);
		printf("에너지 생성 : 2\n");
	}
	else if (c == 7) {//연타
		printf("에너지 : 1\n");
		GotoXY(90, 22);
		printf("데미지 : 2\n");
		GotoXY(90, 23);
		printf("4번 반복 공격\n");
	}
	else if (c == 8) {//화형
		printf("에너지 : 2\n");
		GotoXY(90, 22);
		printf("적군 전체 데미지 : 21\n");
		GotoXY(90, 23);
		printf("힘 감소 : 1");
	}
	else if (c == 9) {//제물
		printf("에너지 : 0\n");
		GotoXY(30, 22);
		printf("자가 데미지 : 6\n");
		GotoXY(30, 23);
		printf("에너지 생성 : 2\n");
	}
	else if (c == 10) {//무적
		printf("에너지 : 2\n");
		GotoXY(90, 22);
		printf("방어도 : 30\n");
	}
	else if (c == 11) {//악마의 형상
		printf("에너지 : 3\n");
		GotoXY(90, 22);
		printf("매턴 힘증가 : 3\n");
	}
	else if (c == 12) {//몽둥이질
		printf("에너지 : 3\n");
		GotoXY(90, 22);
		printf("데미지 : 32\n");
	}
	else if (c == 13) {//드롭킥
		printf("에너지 : 1\n");
		GotoXY(90, 22);
		printf("데미지 : 5\n");
		GotoXY(90, 23);
		printf("카드 드로우 : 1장\n");
	}
}

void Round_Clear(int stair) {
	Clear();
	if (stair == 10) {
		//게임 클리어 화면 띄우기
		//Game_Clear();
		//StopSound();
		Music_GameOver();
		GameOverDraw();
	}
	else {
		Clear();
		//카드 고르기
		srand((unsigned)time(NULL));

		int a = rand() % 11 + 3;
		int b = rand() % 11 + 3;
		int c = rand() % 11 + 3;

		Choose_Card(a,b,c);
		while (1) {
			if (kbhit())
			{
				char temp = getch();
				if (temp == 49) { // 1
					//Player.Mydeck = AddCardToDeck(a);
					Player.Mydeck = insert_first(head, a);
					break;
				}
				else if (temp == 50) { // 2
					Player.Mydeck = insert_first(head, b);
					break;
				}
				else if (temp == 51) { // 3
					Player.Mydeck = insert_first(head, c);
					break;
				}
			}
		}
		

		//다음 라운드 진행
		Info.stair++;
		Clear();
		SET_GREEN
			//3번 깜박임
			GotoXY(50, 20);
		//printf("다음 층 : %d층", Info.stair);
		//Sleep(500);
		//Clear();
		Sleep(700);
		GotoXY(50, 20);
		printf("다음 층 : %d층", Info.stair);
		Sleep(700);
		Clear();
		Sleep(700);
		GotoXY(50, 20);
		printf("다음 층 : %d층", Info.stair);
		Sleep(700);
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

		RanPick_Enemy_Pattern(Info.stair);
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
	GotoXY(40, 2);
	printf("에너지 (%d/3)", Info.energy);
	GotoXY(55, 2);
	printf("내 방어도 : %d", Player.shield);
	SET_RED
		GotoXY(70, 2);
	if (Enemy[Info.stair - 1].pattern[randnum].is_damage == 1) {
		printf("몬스터 : %d만큼 공격합니다!", Enemy[Info.stair-1].pattern[randnum].Enemy_damage);
	}
	else if (Enemy[Info.stair - 1].pattern[randnum].is_protect == 1) {
		printf("몬스터 : %d만큼 방어합니다!", Enemy[Info.stair - 1].pattern[randnum].Enemy_protect);
	}
	else if (Enemy[Info.stair - 1].pattern[randnum].is_buff == 1) {
		printf("몬스터 : 디버프를 사용합니다!");
	}
	
	GotoXY(100, 2);
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