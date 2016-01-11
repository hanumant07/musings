/*
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 * return 1->4->3->2->5->NULL.
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 *
 * Author: Hanumant Singh <hanumant07@gmail.com>
 */

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n || head == nullptr || head->next == nullptr)
                return head;
        ListNode *runner = head;
        ListNode *prev = nullptr;
        int index = 0;
        while (runner != nullptr) {
	     if (++index == m) {
		ListNode *savedPrev = prev;
		ListNode *savedRunner = runner;
		ListNode *newEnd = nullptr;
		while (index <= n) {
		    newEnd = runner->next;
		    runner->next = prev;
		    prev = runner;
		    runner = newEnd;
		    ++index;
		}
		if (m != 1)
		   savedPrev->next = prev;
		else
		   head = prev;
		savedRunner->next = newEnd;
		break;
	    }
	    else {
		prev = runner;
		runner = runner->next;
	    }
       }
       return head;
   }
};
