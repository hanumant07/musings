/*
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * https://leetcode.com/problems/balanced-binary-tree/
 *
 * Author : Hanumant Singh <hanumant07@gmail.com>
 * LICENSE: GPLv2
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
int Depth(struct TreeNode *root, int depth, bool *resp)
{
	int leftDepth;
	int rightDepth;
	if (root == NULL)
		return depth;
	depth++;
	leftDepth = Depth(root->left, depth, resp);
	rightDepth = Depth(root->right, depth, resp);
	if (abs(leftDepth - rightDepth) > 1)
		*resp = false;
	if (leftDepth > rightDepth)
		return leftDepth;
	else
		return rightDepth;
}

bool isBalanced(struct TreeNode* root) {
	bool resp = true;
	Depth(root, 0, &resp);
	return resp;
}
