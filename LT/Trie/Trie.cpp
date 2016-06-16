/*
 * Implement a trie with insert, search, and startsWith methods.
 *
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 *
 * Author: Hanumant Singh <hanumant07@gmail.com>
 * https://leetcode.com/problems/implement-trie-prefix-tree/
 */

class TrieNode {
       public:
	TrieNode *child[26];
	bool last;
	// Initialize your data structure here.
	TrieNode() {
		for (int i = 0; i < 26; i++) child[i] = nullptr;
		last = false;
	}
};

class Trie {
       public:
	Trie() { root = new TrieNode(); }

	void insert(string word) {
		TrieNode *parent = root;
		TrieNode *node;
		for (char c : word) {
			node = parent->child[c - 'a'];
			if (node == nullptr) {
				node = new TrieNode();
				parent->child[c - 'a'] = node;
			}
			parent = node;
		}
		node->last = true;
	}
	bool search(string word) {
		TrieNode *parent = root;
		TrieNode *node;
		for (char c : word) {
			node = parent->child[c - 'a'];
			if (node == nullptr) return false;
			parent = node;
		}
		if (node->last)
			return true;
		else
			return false;
	}
	// Returns true if there
	bool startsWith(string prefix) {
		TrieNode *parent = root;
		TrieNode *node;
		for (char c : prefix) {
			node = parent->child[c - 'a'];
			if (node == nullptr) return false;
			parent = node;
		}
		return true;
	}

       private:
	TrieNode *root;
};
