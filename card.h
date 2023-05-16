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
	short is_range_attack;		// 범위공격? (절단, 소용돌이, 화형...)

	short is_defence_card;
	int shield;

	short is_buff;
	Buff* buff;
	
	short is_draw_card;

	short is_self_damage;
} CardType;

typedef struct {
    CardType* cardtype;
} Card;


void ReadCardData(const char* filename, struct Card* card, int numCards) { //txt파일로부터 카드의 정보를 읽어온다.
    FILE* file = fopen(filename, "r"); //읽기로
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    for (int i = 0; i < numCards; i++) {
        //fscanf(file, );
        //   fscanf(file, "%d %s %d %d", &cards[i].id, cards[i].name, &cards[i].attack, &cards[i].defense); 형식
        // ... 필요한 정보를 읽어와서 구조체에 저장합니다.
    }

    fclose(file);
}


void SetCard(GameManager *gm) {
    Card *card;  // 최대 20개의 카드를 저장할 수 있는 배열
    card = (Card*)malloc(sizeof(CardType*)*20);  
    // "cards.txt" 파일로부터 카드 정보를 읽어옵니다.
    ReadCardData("card.txt", card, 100);

}

#endif // !STATUS_H
