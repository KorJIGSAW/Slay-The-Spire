#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "character.h"

typedef struct {
	int current_level;			// ���� ��
	Character* const player;	// �÷��̾ ���� ���� (�÷��̾�� ��ü���� ����!)
	Character** enemy;	// ������ �ּҿ� ���� �迭
	int enemy_count;	// ���� ����(��)�� �� ���� ���� �ִ����� ���� ����
	Card* deck;			// �󸶳� ¼�� ���� ���� ������?
	Card* hand;			// �� ����
}GameManager;

#endif