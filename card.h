#pragma once
#ifndef CARD_H
#define CARD_H

<<<<<<< HEAD
typedef struct Card{
	char name[10];
	int damage;
	int protect;
}Card;

void CreateCard() { //카드 생성

}

void AddCardToDeck() { //선택한 카드를 덱에 추가하는 함수

}

void DrawCard() { //덱에서 카드를 드로우하는 함수

}

void PlayCard() { // 선택한 카드의 효과를 발동하는 함수, 카드의 효과를 게임 상태에 적용

}

#endif // !CARD_H=
=======
#include <stdio.h>
#include "character.h"

typedef struct {
	char* name;
	char* description;

	short is_offence_card;
	int damage;
	int hits;
	short is_range_attack;		// 범위공격? (절단, 소용돌이, 화형...)

	short is_defence_card;
	int shield;

	short is_buff;
	Buff* buff;
	
	short is_draw_card;

	short is_self_damage;
} CardType;

typedef struct {
	CardType* const cardtype;
} Card;

#endif // !STATUS_H
>>>>>>> 84f3928f9c85bf575b587d6deaa81603efa76d8e
