/*
 * Given a binary search tree, write a function kthSmallest to find the kth
 * smallest element in it.
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 * Author : Hanumant Singh <hanumant07@gmail.com>
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
    int kth;
public:
    void countK(TreeNode *root, int k, int *curr) {
        if (root == nullptr)
            return;

        countK(root->left, k, curr);
        if (*curr == k)
            return;
        (*curr)++;
        if (*curr == k) {
            kth = root->val;
            return;
        }
        countK(root->right, k, curr);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        countK(root, k, &cnt);
        return kth;
    }
};
