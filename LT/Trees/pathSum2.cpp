/*
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 *
 * https://leetcode.com/problems/path-sum-ii/
 * Author: Hanumant Singh <hanumant07@gmail.com>
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
    vector<vector<int>> sol;
public:
    void computePath(TreeNode *root, const int total, int currSum, vector<int> path)
    {
        if (root->left == nullptr && root->right == nullptr &&
                                    currSum + root->val == total) {
            path.push_back(root->val);
            sol.push_back(path);
            return;
        }
        path.push_back(root->val);
        if (root->left)
            computePath(root->left, total, currSum + root->val, path);
        if (root->right)
            computePath(root->right, total, currSum + root->val, path);
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return sol;
        vector<int> path;
        computePath(root, sum, 0, path);
        return sol;
    }
};
