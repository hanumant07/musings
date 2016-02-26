/*
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes
 * in the tree.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes v and w as the lowest node in T that has both v
 * and w as descendants (where we allow a node to be a descendant of itself).”
 *
 *         _______3______
 *	  /              \
 *    ___5__           ___1__
 *   /      \         /      \
 *  6       _2        0       8
 *         /  \
 *         7   4
 * For example, the lowest common
 * ancestor (LCA) of nodes 5 and 1 is
 * 3. Another example is LCA of nodes
 * 5 and 4 is 5, since a node can be
 * a descendant of itself according
 * to the LCA definition.
 *
 * Author Hanumant Singh <hanumant07@gmail.com>
 */



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    stack<TreeNode *> parentP;
    stack<TreeNode *> parentQ;
public:
    bool getPathToNode(TreeNode *root, TreeNode *dest, stack<TreeNode *>& path)
    {
        if (root == nullptr)
            return false;

        if (root == dest) {
            path.push(dest);
            return true;
        }
        if (getPathToNode(root->left, dest, path)) {
            path.push(root);
            return true;
        }

        if (getPathToNode(root->right, dest, path)) {
            path.push(root);
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        getPathToNode(root, p, parentP);
        getPathToNode(root, q, parentQ);
        TreeNode *lca = nullptr;
        while(!parentQ.empty() && !parentP.empty()) {
            TreeNode *currentP = parentP.top();
            TreeNode *currentQ = parentQ.top();
            if (currentP != currentQ)
                break;
            lca = currentP;
            parentP.pop();
            parentQ.pop();
        }
        return lca;
    }
};
