#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct MyCharacter {
	int hp; //�� ü��
	int power; //���� ����� ��
	int shield; //�� ��
}MyCharacter;

typedef struct EnemyCharacter {
	int hp;
	int power;
	int shield;
}EnemyCharacter;

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
