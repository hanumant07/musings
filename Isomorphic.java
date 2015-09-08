/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.

*/


public class Isomorphic {
    public boolean isIsomorphic(String s, String t) {
        int []forwardDirectory = new int[256];
        int []backwardDirectory = new int[256];
        int iter = 0;
        while(iter < s.length()) {
            if (forwardDirectory[(int)s.charAt(iter)] == 0 && backwardDirectory[(int)t.charAt(iter)] == 0) {
                forwardDirectory[(int)s.charAt(iter)] = (int)t.charAt(iter);
                backwardDirectory[(int)t.charAt(iter)] = (int)s.charAt(iter);
            }
            else if ((forwardDirectory[(int)s.charAt(iter)] != (int)t.charAt(iter)) || (backwardDirectory[(int)t.charAt(iter)] != s.charAt(iter)))
                return false;
            iter++;
        }
        return true;
    }
}