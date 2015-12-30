/*
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var invertTree = function(root) {
    var visit = [];
    if (root === null)
       return root;
    
    visit.push(root);
    while(visit.length > 0) {
        var current_node = visit.pop();
        
        if (current_node.left !== null && current_node.right !== null) {
            var temp_node = current_node.left;
            current_node.left = current_node.right;
            current_node.right = temp_node;
            visit.push(current_node.left);
            visit.push(current_node.right);
            
        } if (current_node.left === null && current_node.right !== null) {
            
            current_node.left = current_node.right;
            current_node.right = null
            visit.push(current_node.left);
            continue;
        } if (current_node.right === null && current_node.left !== null) {
            
            current_node.right = current_node.left;
            current_node.left = null
            visit.push(current_node.right);
            continue;
        }
    }    
    return root;
};