/*
 * Given two words word1 and word2, find the minimum number of steps required to
 * convert word1 to word2. (each operation is counted as 1 step.)
 *
 * You have the following 3 operations permitted on a word:
 *
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
 *
 * https://leetcode.com/problems/edit-distance/
 * Author: Hanumant Singh <hanumant07@gmail.com>
 */

class Solution {
 public:
  int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    if (!m && !n) return 0;

    vector<vector<int>> ed(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
      ed[0][i] = i;
    }
    for (int i = 1; i <= m; i++) {
      ed[i][0] = i;
    }

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (word1[i - 1] == word2[j - 1]) {
          ed[i][j] = ed[i - 1][j - 1];
          continue;
        }
        ed[i][j] = min(ed[i - 1][j - 1], min(ed[i][j - 1], ed[i - 1][j])) + 1;
      }
    }
    return ed[m][n];
  }
};
