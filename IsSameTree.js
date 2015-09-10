
/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/


/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */


var isSameTree = function(p, q) {
    var visited1 = [];
    var visited2 = [];
    if (p === null && q === null)
        return true;
    visited1.push(p);
    visited2.push(q);
    while(visited1.length > 0 && visited2.length > 0) {
        var node1 = visited1.shift();
        var node2 = visited2.shift();
        if (((node1 === null) && (node2 !== null)) || ((node1 !== null) && (node2 === null)))
            return false;
        if (node1 === null && node2 === null)
            continue;
        if (node1.val !== node2.val)
            return false;
        else {
            visited1.push(node1.left);
            visited1.push(node1.right);
            visited2.push(node2.left);
            visited2.push(node2.right);
        }
    }
    return true;    
};