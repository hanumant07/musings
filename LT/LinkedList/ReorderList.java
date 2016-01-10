/*
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You must do this in-place without altering the nodes' values.
 *
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 *
 * Author: Hanumant Singh <hanumant07@gmail.com>
 *
 */

/*
 * Definition for singly-linked list.
 * public class ListNode {
 * 	int val;
 * 	ListNode next;
 *      ListNode(int x) { val = x; }
 * }
 */

public class Solution {
    static ListNode mergeList(ListNode head1, ListNode head2)
    {
            ListNode runner1 = head1;
            ListNode runner2 = head2;
            while (runner1 != null && runner2 != null) {
	          ListNode tmp1 = runner1.next;
	          ListNode tmp2 = runner2.next;
	          runner1.next = runner2;
	          runner1 = tmp1;
	          runner2.next = runner1;
	          runner2 = tmp2;
	    }
            return head1;
    }
    static ListNode revList(ListNode head)
    {
            ListNode curr = head;
            ListNode prev = null;
            while(curr != null) {
	         ListNode tmp = curr.next;
	         curr.next = prev;
	         prev = curr;
	         curr = tmp;
	    }
            return prev;
    }
    public void reorderList(ListNode head) {
            if (head == null || head.next == null) return;
            ListNode fast = head;
            ListNode slow = head;
            ListNode head2;
            while(fast != null && fast.next != null) {
	         fast = fast.next.next;
	         slow = slow.next;
	    }
            head2 = slow.next;
            slow.next = null;
            head2 = revList(head2);
            head = mergeList(head, head2);
    }
}
