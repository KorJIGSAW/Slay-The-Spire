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

Card card[14];

ListNode* Init_Card() { //�ʱ� ī�� ����
	ListNode* head = NULL;
	for (int i = 0; i < 5; i++) { //5�� Ÿ�ݼ���
		head = insert_first(head, 0); //Ÿ��
	}
	for (int i = 5; i < 9; i++) { //4�� ������
		head = insert_first(head, 1); //����
	}
	//���������� ��Ÿ ����.
	head = insert_first(head, 2); //��Ÿ
	return head;
}

void AddCardToDeck() { //������ ī�带 ���� �߰��ϴ� �Լ�

}

void MixCard(int CardCount, ListNode* MyDeck) {//	������ ī�带 ���´�.
	int a, b;

	a = rand() % CardCount;
	b = rand() % CardCount;
	if (a == b) {
		b = rand() % CardCount;
	}
	clist* list = (clist *)malloc(sizeof(clist));
	list->first = MyDeck;
	list->count = 0;

	change_data(list, a, b); //�������ɼ�

	Deck_print(MyDeck);

	free(list);
}



void PlayCard() { // ������ ī���� ȿ���� �ߵ��ϴ� �Լ�, ī���� ȿ���� ���� ���¿� ����

}


#endif 