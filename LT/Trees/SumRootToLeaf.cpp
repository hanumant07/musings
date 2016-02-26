/*
*Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
*
*An example is the root-to-leaf path 1->2->3 which represents the number 123.
*
*Find the total sum of all root-to-leaf numbers.
*
*For example,
*
*    1
*   / \
*  2   3
*The root-to-leaf path 1->2 represents the number 12.
*The root-to-leaf path 1->3 represents the number 13.
*
*Return the sum = 12 + 13 = 25.
*https://leetcode.com/problems/sum-root-to-leaf-numbers/
*
*Author: Hanumant Singh <hanumant07@gmail.com>
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
    int total;
public:
    void computeSum(TreeNode *root, int sum)
    {
        if (root->left == nullptr && root->right == nullptr) {
            total += (sum * 10) + root->val;
            return;
        }
        int currSum = sum * 10 + root->val;
        if (root->left)
            computeSum(root->left, currSum);
        if (root->right)
            computeSum(root->right, currSum);
    }
    int sumNumbers(TreeNode* root) {
        total = 0;
        if (root == nullptr)
            return total;
        computeSum(root, 0);
        return total;
    }
};