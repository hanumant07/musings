/* Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 *
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2. The number of elements
 * initialized in nums1 and nums2 are m and n respectively.
 *
 * Author: Hanumant Singh <hanumant07@gmail.com>
 * License: GPLv2
 * https://leetcode.com/problems/merge-sorted-array/
 */

void mergeArray(int *output, int *nums1, int *nums2, int size1, int size2) {
	int iter1 = 0;
	int iter2 = 0;
	int out = 0;
	while (iter1 < size1 && iter2 < size2) {
		if (nums1[iter1] < nums2[iter2]) {
			output[out] = nums1[iter1];
			iter1++;
			out++;
		} else {
			output[out] = nums2[iter2];
			iter2++;
			out++;
		}
	}
	while (iter1 < size1) {
		output[out] = nums1[iter1];
		iter1++;
		out++;
	}
	while (iter2 < size2) {
		output[out] = nums2[iter2];
		iter2++;
		out++;
	}
}

void merge(int* nums1, int m, int* nums2, int n) {
	int i = m + n -1;
	int j = m - 1;
	while (j >= 0) {
		nums1[i] = nums1[j];
		i--;
		j--;
	}
	mergeArray(nums1, &nums1[i + 1], nums2, m, n);
}
