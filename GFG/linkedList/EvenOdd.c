#include <stdio.h>
#include <stdlib.h>
#include <list.h>

struct node *joinList(struct node *list1, struct node *list2)
{
	if (list1->next == NULL && list2->next == NULL)
		return NULL;
	if (list1->next == NULL && list2->next != NULL)
		return list2->next;
	if (list1->next != NULL && list2->next == NULL)
		return list1->next;
	struct node *newHead = list1->next;
	struct node *iter = newHead;
	while(iter->next != NULL)
		iter = iter->next;
	iter->next = list2->next;
	return newHead;
}

void splitList(struct node *orig, struct node **eList, struct node **oList)
{
	*eList = createNode(0);
	*oList = createNode(0);

	struct node *curr = orig;
	struct node *eListIter = *eList;
	struct node *oListIter = *oList;
	while(curr != NULL) {
		if (curr->val % 2 == 0) {
			eListIter->next = curr;
			eListIter = curr;
			curr = curr->next;
			eListIter->next = NULL;
		} else {
			oListIter->next = curr;
			oListIter = curr;
			curr = curr->next;
			oListIter->next = NULL;
		}
	}
}

int main() {
	struct node *evenList, *oddList;
	int listarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	struct node *list = constructIntList(listarr, ARRAY_SIZE(listarr));
	printf("Original List :");
	printList(list);
	splitList(list, &evenList, &oddList);
	printf("Even List : ");
	printList(evenList->next);
	printf("Odd List : ");
	printList(oddList->next);
	printf("Final List : ");
	struct node *finalList = joinList(evenList, oddList);
	printList(finalList);
	freeList(finalList);
	free(evenList);
	free(oddList);
	return 0;
}
