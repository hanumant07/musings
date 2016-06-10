/*
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 *
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length:
 * 4.
 *
 * Your algorithm should run in O(n) complexity.
 *
 * Author: Hanumant Singh <hanumant07@gmail.com>
 *
 */

class Solution {

public:
    int longestConsecutive(vector<int>& nums) {
            unordered_set<int> table;
            for (int i = 0; i < nums.size(); i++)
                table.insert(nums[i]);
            int maxCount = 0;
            for (int i  = 0; i < nums.size(); i++) {
		int pivot = nums[i];
	        int count = 0;
	        while(table.count(pivot--))
			count++;
	        pivot = nums[i] + 1;
	        while(table.count(pivot++))
	                count++;
	        if (count > maxCount)
	                maxCount = count;
	}
        return maxCount;
    }
};
