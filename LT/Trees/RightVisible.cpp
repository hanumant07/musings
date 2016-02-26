/*
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 *
 * For example:
 * Given the following binary tree,
 *    1            <---
 *     /   \
 *     2     3         <---
 *      \     \
 *        5     4       <---
 *        You should return [1, 3, 4].
 *
 * Author : Hanumant Singh <hanumant07@gmail.com>
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *	int val;
 *	TreeNode *left;
 *      TreeNode *right;
 *      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	vector<int> sol;
	queue<TreeNode *> q;
	bool addNext;
public:
	vector<int> rightSideView(TreeNode* root) {
		if (root == nullptr)
			return sol;
		TreeNode *marker = new TreeNode(-1);
		q.push(root);
		q.push(marker);
		sol.push_back(root->val);
		addNext = false;
		while (!q.empty()) {
			TreeNode *curr = q.front();
			q.pop();
			if (curr == marker) {
				q.push(marker);
				if (q.front() == marker)
					q.pop();
					addNext = true;
					continue;
			}
			if (addNext) {
				sol.push_back(curr->val);
				addNext = false;
			}
			if (curr->right)
				q.push(curr->right);
			if (curr->left)
				q.push(curr->left);
		}
		return sol;
	}
};
