/*
 * Given an unsorted integer array, find the first missing positive integer.
 *
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 *
 * Your algorithm should run in O(n) time and uses constant space.
 *
 * Author: Hanumant Singh <hanumant07@gmail.com>
 * https://leetcode.com/problems/first-missing-positive/
 */

class Solution {
public:
    int shiftNeg(vector<int>& nums)
    {
            int i = 0;
            int j = -1;
            for (i = 0; i < nums.size(); i++) {
	                if (nums[i] <= 0) {
			                j++;
			                swap(nums[i], nums[j]);
			            }
	            }
            return j + 1;
    }
    int firstMissingPositive(vector<int>& nums)
    {
	int pivot = shiftNeg(nums);
        int missing = 0;
        for(int i = pivot; i < nums.size(); i++) {
	        if (pivot + abs(nums[i]) -1 < nums.size()) {
			if (nums[pivot + abs(nums[i]) - 1] > 0)
			        nums[pivot + abs(nums[i]) - 1] *= -1;
		}
	}
        while (missing + pivot < nums.size()) {
		if (nums[pivot + missing] > 0)
	                    return missing + 1;
	        missing++;
	}
        return missing + 1;
   }

}
