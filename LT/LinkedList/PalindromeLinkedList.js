
/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/


/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
 
var move_next = function(head, curr, iter){
    var res;
    iter.count = iter.count + 1;

    if (curr.next !== null)
        res = move_next(head, curr.next, iter);
    if (curr.next === null) {
        if (head.val === curr.val)
            iter.count = iter.count - 1;
        return head.next;
    } else {
        if (res === null)
            return null;
        if (res.val === curr.val)
            iter.count = iter.count - 1;
        return res.next;
    }
}

var isPalindrome = function(head) {
    var iter = {};
    iter.count = 0;
    if (head === null)
        return true;
    if (head.next === null)
        return true;
    move_next(head, head, iter);
    if (iter.count !== 0)
        return false;
    return true;
};
