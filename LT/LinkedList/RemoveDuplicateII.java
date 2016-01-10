/*
* Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
*
* For example,
* Given 1->2->3->3->4->4->5, return 1->2->5.
* Given 1->1->1->2->3, return 2->3.
* 
* Author: Hanumant Singh <hanumant07@gmail.com>
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) return head;
        int key;
        ListNode newHead = new ListNode(0);
        ListNode runner = head;
        ListNode newRunner = newHead;
        newHead.next = null;
        
        while (runner != null) {
            key = Runner.val;
            System.out.println(runner.val);
            if (runner.next != null && runner.next.val != runner.val) {
                newRunner.next = runner;
                newRunner = runner;
                key = runner.val;
                runner = runner.next;
            }
            while (runner != null && runner.val == key)
                runner = runner.next;
            if (runner == null) break;
        }
        
        newRunner.next = runner != null ? runner : null;
        return newHead.next;
    }
}

