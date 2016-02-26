/*
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its zigzag level order traversal as:
 * [
 *  [3],
 *  [20,9],
 *  [15,7]
 * ]
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 *
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
	queue<TreeNode *> q;
	vector<vector <int>> sol;
	vector<int> currList;
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (root == nullptr)
			return sol;
		TreeNode *marker = new TreeNode(-1);
		q.push(root);
		q.push(marker);
		while (!q.empty()) {
			TreeNode *curr = q.front();
			q.pop();
			if (curr == marker) {
				sol.push_back(currList);
				currList.clear();
				if (q.empty())
					break;
				if (q.front() != marker)
					q.push(marker);
				else
					q.pop();
				continue;
		        }
			currList.push_back(curr->val);
			if (curr->left)
				q.push(curr->left);
			if (curr->right)
				q.push(curr->right);
		}
		for (int i = 0; i < sol.size(); i++) {
			if (i & 0x1)
				reverse(sol[i].begin(), sol[i].end());
		}
		return sol;
	}
};
