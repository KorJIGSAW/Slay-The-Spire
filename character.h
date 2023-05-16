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

void StartBattle() { // ���� �����Լ�

}

void CheckBattleEnd(GameManager* gm) { //���� ü���� 0�� �Ǿ�����, �÷��̾ ü���� 0�� �Ǿ�����

	short is_cleared = 1;

	if (gm->player->hp <= 0) {
		// ���� ���� �� ���� ���� �� ù ȭ�� ����
	}
	else {
		// ������ ���� or ���� ����
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
