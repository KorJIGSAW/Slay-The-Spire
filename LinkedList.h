#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "draw.h"

typedef struct ListNode {
	Card data;
	struct ListNode* link;
}ListNode;

typedef struct CountList {
	ListNode* first;
	int count;
}clist;

ListNode* insert_first(ListNode *head, Card value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* change_data(clist* list, int a, int b) {
	Card temp;
	if (a > b) {
		a = a ^ b; //xor������
		b = a ^ b;
		a = a ^ b;
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


ListNode* insert(ListNode* head, ListNode* pre, Card value) {
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
	for (ListNode* p = head; p != NULL; p = p->link) {
		//printf("");
	}
}

#endif // !LINKEDLIST_H
