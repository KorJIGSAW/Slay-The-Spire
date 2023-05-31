#ifndef CARD_H
#define CARD_H
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "sts.h"

typedef struct Card {
	char name[14];
	int damage;
	int damage_times;
	int damage_all;
	int protect;
	int My_debuff;
	int Enemy_debuff;
	char description[150];
}Card;

/* Kind and nice translations
 * [ 0] STRIKE : 타격
 * [ 1] DEFEND : 수비
 * [ 2] BASH : 강타
 * [ 3] PERFECTED_STRIKE : 완벽한 타격
 * [ 4] INFLAME : 발화
 * [ 5] IRON_WAVE : 철의 파동
 * [ 6] BLOODLETTING : 사혈
 * [ 7] PUMMEL : 연타
 * [ 8] IMMOLATE : 화형
 * [ 9] OFFERING : 제물
 * [10] IMPREVIOUS : 무적
 * [11] DEMON_FORM : 악마의 형상
 * [12] BLUDGEON : 몽둥이질
 * [13] DROPKICK : 드롭킥
 */
typedef enum {
	STRIKE, DEFEND, BASH, PERFECTED_STRIKE, INFLAME,
	IRON_WAVE, BLOODLETTING, PUMMEL, IMMOLATE, OFFERING,
	IMPREVIOUS, DEMON_FORM, BLUDGEON, DROPKICK
} CardType;

Card card[14];

ListNode* Init_Card() { //초기 카드 세팅
	ListNode* head = NULL;
	for (int i = 0; i < 5; i++) { //5장 타격설정
		head = insert_first(head, 0); //타격
	}
	for (int i = 5; i < 9; i++) { //4장 수비설정
		head = insert_first(head, 1); //수비
	}
	//마지막한장 강타 설정.
	head = insert_first(head, 2); //강타
	return head;
}

void AddCardToDeck(CardType card, ListNode* MyDeck) { //선택한 카드를 덱에 추가하는 함수
	
}

void MixCard(int CardCount, ListNode* MyDeck) {//	덱에서 카드를 섞는다.
	int a, b;

	a = rand() % CardCount;
	b = rand() % CardCount;
	if (a == b) {
		b = rand() % CardCount;
	}
	clist* list = (clist *)malloc(sizeof(clist));
	list->first = MyDeck;
	list->count = 0;

	change_data(list, a, b); //오류가능성

	Deck_print(MyDeck);

	free(list);
}



void PlayCard() { // 선택한 카드의 효과를 발동하는 함수, 카드의 효과를 게임 상태에 적용

}


#endif 