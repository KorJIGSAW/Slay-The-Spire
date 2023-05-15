#pragma once
#ifndef CAL_DAMAGE_C
#define CAL_DAMAGE_C
#include <stdio.h>
#include <stdlib.h>
#include "character.h"

void MyAttack(MyCharacter* Me, EnemyCharacter* Enemy, int damage) { //���� ���͸� ������ ��
	Enemy->hp -= Me->power + damage;
}

void EnemyAttack(MyCharacter* Me, EnemyCharacter* Enemy, int damage) { //���Ͱ� ���� ������ ��
	Me->hp -= Enemy->power + damage;
}

void StartBattle() { // ���� �����Լ�

}

void PlayerAction() { // �÷��̾� �ൿ ó�� (����, ���)

}

void EnemyAction() { // ���� �ൿ ó�� (����, ���)

}

void CheckBattleEnd(MyCharacter * Me, EnemyCharacter * Enemy) { //���� ü���� 0�� �Ǿ�����, �÷��̾ ü���� 0�� �Ǿ�����
	if (Me->hp <= 0) {
		// ���� ���� �� ���� ���� �� ù ȭ�� ����
	}
	else if (Enemy->hp <= 0) {
		// ������ ���� or ���� ����
	}
}

#endif

