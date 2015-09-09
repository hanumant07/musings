/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
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
    private ListNode editList(ListNode current, int val) {
        if (current == null || ((current.next == null) && (current.val == val)))
            return null;
        ListNode next = editList(current.next, val);
        if (current.val == val)
            return next;
        current.next = next;
        return current;
    }
    public ListNode removeElements(ListNode head, int val) {
        return editList(head, val);
    }
}