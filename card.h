#ifndef CARD_H
#define CARD_H
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
#include "LinkedList.h"
#include "draw.h"


void Init_Card() { //�ʱ� ī�� ����
	ListNode* head = NULL;
	for (int i = 0; i < 5; i++) { //5�� Ÿ�ݼ���
		head = insert_first(head, card[0]); //Ÿ��
	}
	for (int i = 5; i < 9; i++) { //4�� ������
		head = insert_first(head, card[1]); //����
	}
	//���������� ��Ÿ ����.
	head = insert_first(head, card[2]); //��Ÿ
}

void AddCardToDeck() { //������ ī�带 ���� �߰��ϴ� �Լ�

}

void DrawCard() { //������ ī�带 ��ο��ϴ� �Լ�

}

void PlayCard() { // ������ ī���� ȿ���� �ߵ��ϴ� �Լ�, ī���� ȿ���� ���� ���¿� ����

}


#endif 