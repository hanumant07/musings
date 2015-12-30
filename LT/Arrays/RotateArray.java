/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
*/

public class Solution {
    private void flip(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[end];
            nums[end] = nums[start];
            nums[start] = temp;
            start++;
            end--;
        }
    }
    public void rotate(int[] nums, int k) {
        int i = 0;
        int j = 0;
        
        if (nums.length <=1 || k % nums.length == 0)
            return;
        if (k > nums.length)
            k = k % nums.length;
        flip(nums, 0, nums.length-1);
        flip(nums, 0, k-1);
        flip(nums, k, nums.length-1);
    }

}