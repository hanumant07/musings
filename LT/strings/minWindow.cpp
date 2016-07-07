/*
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 *
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 *
 * Note:
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 *
 * If there are multiple such windows, you are guaranteed that there will always
 * be only one unique minimum window in S.
 *
 * Author: Hanumant Singh <hanumant07@gmail.com>
 * https://leetcode.com/problems/minimum-window-substring/
 */

class Solution {
  int winStart;
  int lastStart;
  int minLen;
  string minWin;
  string pattern;

 public:
  string minWindow(string s, string t) {
    if (t == "" || s == "") return minWin;
    int map[256] = {0};
    int found[256] = {0};
    pattern = t;
    for (char c : pattern) map[c]++;

    int start = 0;
    lastStart = 0;
    minLen = INT_MAX;
    bool patternStart = false;
    bool foundOne = false;
    for (int i = 0; i < s.length(); i++) {
      if (!map[s[i]]) continue;
      found[s[i]]++;
      if (!patternStart) {
        patternStart = true;
        start = i;
      }
      if (!foundOne) {
        if (!allFound(map, found)) continue;
        foundOne = true;
        while (canDrop(found, map, s[start])) start++;
        recordWin(s, start, i);
      } else {
        start = lastStart;
        while (canDrop(found, map, s[start]) && start < i) start++;
        recordWin(s, start, i);
      }
    }
    return minWin;
  }

 private:
  bool allFound(int *map, int *found) {
    for (char i : pattern) {
      if (map[i] > found[i]) return false;
    }
    return true;
  }
  bool canDrop(int *found, int *map, char c) {
    if (map[c] > 0) {
      if (found[c] > map[c]) {
        found[c]--;
        return true;
      } else
        return false;
    }
    return true;
  }
  void recordWin(string &s, int start, int end) {
    lastStart = start;
    if (end - start + 1 > minLen) return;
    minLen = end - start + 1;
    winStart = start;
    minWin = s.substr(start, minLen);
  }
};
