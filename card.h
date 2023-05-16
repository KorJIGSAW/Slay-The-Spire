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
    CardType* cardtype;
} Card;


void ReadCardData(const char* filename, struct Card* card, int numCards) { //txt���Ϸκ��� ī���� ������ �о�´�.
    FILE* file = fopen(filename, "r"); //�б��
    if (file == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return;
    }

    for (int i = 0; i < numCards; i++) {
        //fscanf(file, );
        //   fscanf(file, "%d %s %d %d", &cards[i].id, cards[i].name, &cards[i].attack, &cards[i].defense); ����
        // ... �ʿ��� ������ �о�ͼ� ����ü�� �����մϴ�.
    }

    fclose(file);
}


void SetCard(GameManager *gm) {
    Card *card;  // �ִ� 20���� ī�带 ������ �� �ִ� �迭
    card = (Card*)malloc(sizeof(CardType*)*20);  
    // "cards.txt" ���Ϸκ��� ī�� ������ �о�ɴϴ�.
    ReadCardData("card.txt", card, 100);

}

#endif // !STATUS_H
