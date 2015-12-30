#include <stdio.h>
#include <stdlib.h>
#include <list.h>

void printList(const struct node *list)
{
	const struct node *curr = list;
	while(curr != NULL) {
		if (curr->next == NULL)
			printf("%d", curr->val);
		else
			printf("%d->", curr->val);
		curr = curr->next;
	}
	printf("\n");
	return;
}


struct node *reverseList(struct node **curr, struct node **newHead)
{
	struct node *newPrev;
	if ((*curr)->next == NULL) {
		*newHead = (*curr);
		return *newHead;
	} else {
		newPrev = reverseList(&(*curr)->next, newHead);
		newPrev->next = *curr;
		(*curr)->next = NULL;
		return *curr;
	}
}

struct node *createNode(int val)
{
	struct node *node = (struct node *)malloc(sizeof(struct node));
	node->val = 0;
	node->next = NULL;
	return node;
}

struct node *constructIntList(int *arr, int size)
{
	int i;
	struct node *head = NULL, *node = NULL, *prev = NULL;
	for(i = 0; i < size; i++) {
		node = malloc(sizeof(struct node));
		node->val = arr[i];
		node->next = NULL;
		if (prev != NULL) {
			prev->next = node;
			prev = node;
		} else {
			head = node;
			prev = head;
		}
	}
	return head;
}

void freeList(struct node *list)
{
	struct node *next = NULL;
	struct node *iter = list;
	while (iter != NULL) {
		next = iter->next;
		free(iter);
		iter = next;
	}
}

struct node *mergeDescend(struct node *left, struct node *right)
{
	struct node *newHead = NULL;
	struct node *iterMerge = NULL;
	struct node *iter1 = left;
	struct node *iter2 = right;

	while (iter1 != NULL && iter2 != NULL) {
		if (iter1->val >= iter2->val) {
			if (newHead == NULL) {
				newHead = iter1;
				iterMerge = newHead;
			} else {
				iterMerge->next = iter1;
				iterMerge = iterMerge->next;
			}
			iter1 = iter1->next;
		} else {
			if (newHead == NULL) {
				newHead = iter2;
				iterMerge = newHead;
			} else {
				iterMerge->next = iter2;
				iterMerge = iterMerge->next;
			}
			iter2 = iter2->next;
		}
	}
	if (iter1 == NULL)
		iterMerge->next = iter2;
	else
		iterMerge->next = iter1;
	return newHead;
}

