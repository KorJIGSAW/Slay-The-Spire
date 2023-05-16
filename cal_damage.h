#pragma once
#ifndef CAL_DAMAGE_C
#define CAL_DAMAGE_C
#include <stdio.h>
#include <stdlib.h>
#include "character.h"

void MyAttack(MyCharacter* Me, EnemyCharacter* Enemy, int damage) { //내가 몬스터를 공격할 때
	Enemy->hp -= Me->power + damage;
}

void EnemyAttack(MyCharacter* Me, EnemyCharacter* Enemy, int damage) { //몬스터가 나를 공격할 때
	Me->hp -= Enemy->power + damage;
}

void StartBattle() { // 전투 시작함수

}

void CheckBattleEnd(MyCharacter * Me, EnemyCharacter * Enemy) { //적이 체력이 0이 되었을때, 플레이어가 체력이 0이 되었을때
	if (Me->hp <= 0) {
		// 게임 엔딩 후 점수 인출 및 첫 화면 복귀
	}
	else if (Enemy->hp <= 0) {
		// 다음층 진출 or 게임 엔딩
	}
}

#endif

