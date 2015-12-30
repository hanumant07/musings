/*
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 *
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums
 * should be [1, 3, 12, 0, 0].
 *
 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 *
 * Author: Hanumant Singh <hanumant07@gmail.com>
 * License: GPLv2
 * https://leetcode.com/problems/move-zeroes/
 */

void moveZeroes(int *nums, int numsSize)
{
	int begin = 0;
	int newBegin;
	int nonZero = 0;
	if (numsSize == 0)
		return 0;
	while (begin < numsSize) {
		if (nums[begin] != 0) {
			nums[nonZero++] = nums[begin++];
			continue;
		}
		newBegin = begin;
		while (nums[newBegin] == 0 && newBegin < numsSize)
			newBegin++;
		if (newBegin == numsSize)
			break;
		begin = newBegin;
	}
	while (nonZero < numsSize)
		nums[nonZero++] = 0;
	return;
}

