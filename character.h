#ifndef CHARACTER_H
#define CHARACTER_H

#include <stdio.h>
#include <stdlib.h>
#include "gamemanager.h"

typedef struct {
	int power;
	int vulnerable;
	int weakness;
	
}Buff;

typedef struct Character {
	int hp;
	int shield;
	int isPlayer;	//0 or 1

	Buff buff;
	
}Character;

void StartBattle() { // 전투 시작함수

}

void CheckBattleEnd(GameManager* gm) { //적이 체력이 0이 되었을때, 플레이어가 체력이 0이 되었을때

	short is_cleared = 1;

	if (gm->player->hp <= 0) {
		// 게임 엔딩 후 점수 인출 및 첫 화면 복귀
	}
	else {
		// 다음층 진출 or 게임 엔딩
		for (int i = 0, z = gm->enemy_count; i < z; i++) {
			if (gm->enemy[i]->hp > 0) {
				is_cleared = 0;
				break;
			}
		}
	}

	if (is_cleared) {
		// todo: goto next level
	}
}

void do_damage(Character* attacker, Character* defender, int damage) {
	if (defender->shield < damage) {
		defender->hp -= damage - defender->shield;
		defender->shield = 0;
	}
	else {
		defender->shield -= damage;
	}
}

int attack(Character* attacker, Character* defender, int damage, int hits) {
	for (int i = hits; i--;) {
		do_damage(attacker, defender, damage+attacker->power);
	}
}

#endif // !CHARACTER_H
