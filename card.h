#pragma once
#ifndef CARD_H
#define CARD_H

#include <stdio.h>
#include "character.h"

typedef struct {
	char* name;
	char* description;

	short is_offence_card;
	int damage;
	int hits;
	short is_range_attack;		// ��������? (����, �ҿ뵹��, ȭ��...)

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
