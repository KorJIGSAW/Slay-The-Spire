#ifndef CARD_H
#define CARD_H
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "LinkedList.h"
#include "draw.h"
#include "time.h"


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

void AddCardToDeck() { //선택한 카드를 덱에 추가하는 함수

}

void MixCard(int CardCount, ListNode* MyDeck) {//	덱에서 카드를 섞는다.
	int a, b;
	srand((unsigned)time(NULL));

	a = rand() % CardCount;
	b = rand() % CardCount;
	if (a == b) {
		b = rand() % CardCount;
	}
	clist* list = (clist *)malloc(sizeof(clist));
	list->first = MyDeck;
	list->count = 0;
	change_data(list, a, b); //오류가능성
	GotoXY(50, 20);
	SET_GREEN
	printf("카드를 섞는중입니다...");
	SET_WHITE
	Sleep(300);
	Clear();
	Deck_print(MyDeck);
	
	free(list);
}



void PlayCard() { // 선택한 카드의 효과를 발동하는 함수, 카드의 효과를 게임 상태에 적용

}


#endif 