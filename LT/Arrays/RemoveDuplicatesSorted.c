/*
 * Given a sorted array, remove the duplicates in place such that each element
 * appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with
 * constant memory.
 *
 * For example,
 * Given input array nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively. It doesn't matter what you leave beyond the new
 * length.
 *
 * Author : Hanumant Singh <hanumant07@gmail.com>
 * License: GPLv2
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 */


int removeDuplicates(int *nums, int numsSize)
{
	int prev = nums[0];
	int newEnd = 1;
	int begin = 1;
	if (numsSize == 0)
		return 0;
	while (begin < numsSize) {
		if (nums[begin] != prev) {
			nums[newEnd] = nums[begin];
			prev = nums[newEnd];
			newEnd++;
			begin++;
			continue;
		} else {
			int newBegin = begin;
			while (nums[newBegin] == prev && newBegin < numsSize)
				newBegin++;
			if (newBegin == numsSize)
				return newEnd;
			nums[newEnd] = nums[newBegin];
			prev = nums[newBegin];
			begin = newBegin;
			newEnd++;
			begin++;
		}
	}
	return newEnd;
}
