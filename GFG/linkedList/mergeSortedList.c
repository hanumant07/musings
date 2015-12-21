#include <stdio.h>
#include <list.h>

int main(int argc, const char *argv[])
{
	int arrlist1[] = {1, 10, 20};
	int arrlist2[] = {1, 6, 11, 16, 21};
	struct node *list1 = constructIntList(arrlist1, ARRAY_SIZE(arrlist1));
	struct node *list2 = constructIntList(arrlist2, ARRAY_SIZE(arrlist2));
	struct node *revList1 = NULL;
	struct node *revList2 = NULL;
	struct node *mergeList = NULL;
	printf("Reverse List 1: ");
	reverseList(&list1, &revList1);
	printList(revList1);
	printf("Reverse List 2: ");
	reverseList(&list2, &revList2);
	printList(revList2);
	printf("Merge Descend List: ");
	mergeList = mergeDescend(revList1, revList2);
	printList(mergeList);
	return 0;
}
