#pragma once
#ifndef CAL_DAMAGE_C
#define CAL_DAMAGE_C
#include <stdio.h>
#include <stdlib.h>
#include "character.h"

void MyAttack(MyCharacter* Me, EnemyCharacter* Enemy, int damage); //���� ���͸� ������ ��
void EnemyAttack(MyCharacter* Me, EnemyCharacter* Enemy, int damage); //���Ͱ� ���� ������ ��

void MyAttack(MyCharacter* Me, EnemyCharacter* Enemy, int damage) {
	Enemy->hp -= Me->power + damage;
}

void EnemyAttack(MyCharacter* Me, EnemyCharacter* Enemy, int damage) {
	Me->hp -= Enemy->power + damage;
}
#endif

