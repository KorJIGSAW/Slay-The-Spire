#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "character.h"

typedef struct {
	int current_level;			// 현재 층
	Character* const player;	// 플레이어에 대한 정보 (플레이어는 교체되지 않음!)
	Character** enemy;	// 적들의 주소에 대한 배열
	int enemy_count;	// 현재 레벨(층)에 몇 명의 적이 있는지에 대한 정보
	Card* deck;			// 얼마나 쩌는 덱을 갖고 있을까?
	Card* hand;			// 내 손패
}GameManager;

#endif