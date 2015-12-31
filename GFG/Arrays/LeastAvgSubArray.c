/*
 * Find the subarray with least average of size K. Given an array arr[] of size
 * n and integer k such that k <= n.
 *
 * Input:
 * The first line contains an integer 'T' denoting the total number of test
 * cases. In each test cases, the first line contains an integer 'N' and 'K'
 * denoting the size of array. The second line contains N space-separated
 * integers A1, A2, ..., AN denoting the elements of the array.
 *
 *
 * Output:
 * The first and last index of the subarray. (Index begins from 1).
 *
 *
 * Constraints:
 * 1<=T<=30
 * 1<=N<=1000
 * 1<=K<=N
 * 1<=A[i]<=103
 *
 * Example:
 * Input:
 * 1
 * 3 1
 * 30 20 10
 *
 * Output:
 * 3 3
 *
 * Author : Hanumant Singh <hanumant07@gmail.com>
 */
#include <stdio.h>

void minAvgArray(int *nums, int numsSize, int k)
{
	int end = 0;
	int minSum, prevStart = 0, currentSum = 0;
	int minStart = 0;

	while (end < k)
		minSum = nums[end++];
	currentSum = minSum;

	while (end < numsSize) {
		currentSum += nums[end] - nums[end - k];
		if (currentSum < minSum) {
			minStart = end - k + 1;
			minSum = currentSum;
		}
		end++;
	}
	printf("output is ");
	printf("%d %d", minStart + 1, minStart + k);
}

int main()
{
	int input[1000];
	int aSize, t, k, i;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &aSize, &k);
		printf("Array Size %d, subset size %d\n", aSize, k);
		for (i = 0; i < aSize; i++)
			scanf("%d", &input[i]);
		printf("scanned array is ");
		for (i = 0; i < aSize; i++)
			printf("%d ", input[i]);
		printf("\n");
		minAvgArray(input, aSize, k);
	}
	return 0;
}
