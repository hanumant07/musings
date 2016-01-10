/*
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 *
 * If the number of nodes is not a multiple of k then left-out nodes in the end
 * should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 *
 * Only constant memory is allowed.
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 *
 * Author: Hanumant Singh <hanumant07@gmail.com>
 */

#include <stdio.h>
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *revList(struct ListNode *head, int k)
{
	struct ListNode *prev = NULL;
	struct ListNode *curr = head;
	while (k--) {
		struct ListNode *tmp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = tmp;
	}
	return prev;
}

void genResSegment(struct ListNode *resHead, struct ListNode *resEnd,
			 struct ListNode *segEnd, int k)
{
	struct ListNode *segStart = revList(segEnd, k);
	if (!resEnd->next)
		resEnd->next = segEnd;
	else {
		resEnd->next->next = segStart;
		resEnd->next = segEnd;
	}
	if (!resHead->next)
		resHead->next = segStart;
	return;
}

struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
	if (k == 0 || k == 1)
		return head;
	struct ListNode res = {
		.next = NULL,
	};
	struct ListNode resEnd = {
		.next = NULL,
	};
	int revCount = k - 1;
	struct ListNode *kStart = head;
	struct ListNode *iter = head;

	while(iter != NULL) {
		if (!revCount) {
			revCount = k - 1;
			iter = iter->next;
			genResSegment(&res, &resEnd, kStart, k);
			kStart = iter;
		} else {
			revCount--;
			iter = iter->next;
		}
	}
	if (resEnd.next)
		resEnd.next->next = revCount >= 0 ? kStart : NULL;
	return res.next != NULL ? res.next : head;
}
