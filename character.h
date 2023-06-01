#ifndef CHARACTER_H
#define CHARACTER_H
#include "LinkedList.h"

typedef struct MyCharacter {
	int hp; //�� ü��
	int power; //���� ����� ��
	int shield; //�� ��
	ListNode* Mydeck;
}MyCharacter;

typedef struct EnemyPattern EnemyPattern;

struct EnemyPattern {
	int is_damage;
	int Enemy_damage;
	int is_protect;
	int Enemy_protect;
	int is_buff;
	int power_raise;
};

typedef struct EnemyCharacter {
	int hp;
	int power;
	int shield;
	EnemyPattern pattern[5];
} EnemyCharacter;

/* ���
typedef struct Character {
	int hp;
	int power;
	int shield;
	int isPlayer;	//0 or 1
}Character;

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
*/

#endif // !CHARACTER_H
