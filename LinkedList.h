#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "draw.h"

typedef struct ListNode {
	Card Deck;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode *head, Card value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->Deck = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, Card value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->Deck = value;
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
	for (ListNode* p = head; p != NULL; p = p->link) {
		//printf("");
	}
}

#endif // !LINKEDLIST_H
