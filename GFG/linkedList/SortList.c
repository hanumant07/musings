#include <stdio.h>
#include <stdlib.h>
#include <list.h>

struct node *orderList(struct node *iter)
{
	int counter[3] = {0};
	int i = 0;
	struct node *next = NULL;
	struct node *curr = NULL;
	struct node *newHead = NULL;
	struct node *node = NULL;
	while(iter != NULL) {
		next = iter->next;
		counter[iter->val]++;
		free(iter);
		iter = next;
	}
	for (i = 0; i < counter[0]; i++) {
		node = createNode(0);
		if (newHead == NULL) {

			curr = node;
			newHead = curr;
		} else
			curr->next = node;
	}
	for (i = 0; i < counter[1]; i++) {
		node = createNode(1);
		if (newHead == NULL) {
			curr = node;
			newHead = node;
		} else {
			curr->next = node;
			curr = node;
		}
	}
	for (i = 0; i < counter[2]; i++) {
		node = createNode(2);
		if (newHead == NULL) {
			newHead = node;
			curr = node;
		} else {
			curr->next = node;
			curr = node;
		}
	}
	return newHead;
}

int main(int argc, char *argv[])
{
	int listarr[] = {1, 1, 2, 2, 1, 1, 1, 1, 1};
	struct node *origList = constructIntList(listarr, ARRAY_SIZE(listarr));
	struct node *result;
	printf("Initial List: ");
	printList(origList);
	printf("Final list: ");
	result = orderList(origList);
	printList(result);
	return 0;
}
