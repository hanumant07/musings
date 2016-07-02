/*
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 *
 * For example,
 * Given [10, 9, 2, 5, 3, 7, 101, 18],
 * The longest increasing subsequence is [2, 3, 7, 101], therefore the length is
 * 4.
 * Note that there may be more than one LIS combination, it is only necessary
 * for you to return the length.
 *
 * Your algorithm should run in O(n2) complexity.
 * https://leetcode.com/problems/longest-increasing-subsequence/
 * Author: Hanumant Singh <hanumant07@gmail.com>
 */

struct listEntry {
	int len;
	int last_ind;
};

int lengthOfLIS(int* nums, int numsSize) {
	if (numsSize == 0) return 0;
	struct listEntry* LIS =
	    malloc((numsSize + 1) * sizeof(struct listEntry));
	LIS[0].len = 0;
	LIS[0].last_ind = -1;
	LIS[1].len = 1;
	LIS[1].last_ind = 0;
	int maxLIS = 1;

	for (int i = 2; i <= numsSize; i++) {
		LIS[i].len = 0;
		for (int j = 1; j < i; j++) {
			if ((nums[i - 1] > nums[LIS[j].last_ind]) &&
			    (LIS[i].len <= LIS[j].len)) {
				LIS[i].len = LIS[j].len + 1;
				LIS[i].last_ind = i - 1;
			}
		}
		if (LIS[i].len == 0) {
			LIS[i].len = 1;
			LIS[i].last_ind = i - 1;
		}
		if (maxLIS < LIS[i].len) maxLIS = LIS[i].len;
	}
	return maxLIS;
}
