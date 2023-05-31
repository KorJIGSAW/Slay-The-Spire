#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "sts.h"

int Deck_sequence[5];

typedef struct ListNode {
	int data;
	struct ListNode* link;
}ListNode;

typedef struct CountList {
	ListNode* first;
	int count;
}clist;

ListNode* insert_first(ListNode *head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void change_data(clist* list, int a, int b) {
	int temp;
	if (a > b) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	ListNode* k = list->first;

	for (int i = 0; i < a; i++) {
		k = k->link;
	}

	ListNode* ret = k;

	for (int i = a; i < b; i++) {
		k = k->link;
	}
	
	temp = k->data;
	k->data = ret->data;
	ret->data = temp;
}


ListNode* insert(ListNode* head, ListNode* pre, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL)
		return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode* delete_(ListNode* head, ListNode* pre) {
	ListNode *removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void Deck_print(ListNode* head) {
	int count = 0;
	for (ListNode* p = head; p != NULL; p = p->link) {
		DrawCard(p->data, count);
		Deck_sequence[count] = p->data; //뽑은 패의 순서를 Deck_sequence에 담는다.
		count++;
		if (count == 5) {
			break;
		}
	}
}

#endif 