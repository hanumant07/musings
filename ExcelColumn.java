/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

public class Solution {
    public int titleToNumber(String s) {
        int i=0;
        int col = 0;
        int iter = s.length()-1;
        while(iter >= 0) {
            col += (int)(s.charAt(iter) - 'A' + 1) * Math.pow(26, i);
            iter--;
            i++;
    
        }
        return col;
    }
}