#ifndef CARD_H
#define CARD_H
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "LinkedList.h"
#include "draw.h"
#include "time.h"


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
	srand((unsigned)time(NULL));

	a = rand() % CardCount;
	b = rand() % CardCount;
	if (a == b) {
		b = rand() % CardCount;
	}
	clist* list = (clist *)malloc(sizeof(clist));
	list->first = MyDeck;
	list->count = 0;
	change_data(list, a, b); //�������ɼ�
	GotoXY(50, 20);
	SET_GREEN
	printf("ī�带 �������Դϴ�...");
	SET_WHITE
	Sleep(300);
	Clear();
	Deck_print(MyDeck);
	
	free(list);
}



void PlayCard() { // ������ ī���� ȿ���� �ߵ��ϴ� �Լ�, ī���� ȿ���� ���� ���¿� ����

}


#endif 