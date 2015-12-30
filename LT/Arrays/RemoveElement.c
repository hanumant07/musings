/*
 * Given an array and a value, remove all instances of that value in place and
 * return the new length.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond
 * the new length.
 *
 * Author: Hanumant Singh <hanumant07@gmail.com>
 * License: GPLv2
 * https://leetcode.com/problems/remove-element/
 */

int removeElement(int* nums, int numsSize, int val) {
	int i = 0, k = 0;
	for(; i < numsSize; i++) {
		if (nums[i] != val) {
			nums[k] = nums[i];
			k++;
		}
	}
	return k;
}
