
#ifndef __LIST_H__
#define __LIST_H__

#define ARRAY_SIZE(a) sizeof(a)/sizeof(*a)
struct node {
	 int val;
	struct node *next;
};

struct node *reverseList(struct node **curr, struct node **newHead);
struct node *constructIntList(int *arr, int size);
struct node *createNode(int val);
struct node *mergeDescend(struct node *list1, struct node *list2);
void printList(const struct node *list);
void freeList(struct node *list);
#endif
