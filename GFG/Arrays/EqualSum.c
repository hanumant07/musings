/*
 * Given an array A of length N. Determine if there exists an element in the
 * array such that the sum of the elements on its left is equal to the sum of
 * the elements on its right. If there are no elements to the left/right, then
 * the sum is considered to be zero.
 * Formally, find an i, such that, A1+A2...Ai-1 =Ai+1+Ai+2...AN.
 *
 *  Input:
 *
 *   The first line contains T, the number of test cases. For each test case,
 *   the first line contains N, the number of elements in the array A. The
 *   second line for each test case contains N space-separated integers,
 *   denoting the array A.
 *
 *
 *   Output:
 *
 *   For each test case print YES if there exists an element in the array, such
 *   that the sum of the elements on its left is equal to the sum of the
 *   elements on its right; otherwise print NO in a separate line.
 *
 *
 *   Constraints:
 *
 *   1≤ T ≤ 30
 *   1≤ N ≤100000
 *   1≤ Ai ≤ 2×10000
 *   1≤ i ≤N
 *
 *
 *   Example:
 *
 *   Input
 *   1
 *   1 2 3 3
 *   Output:
 *   YES
 *
 * Author: Hanumant Singh <hanumant07@gmail.com>
 *
 */
#include <stdio.h>
#include <stdlib.h>

void checkEqualSum(int *input, int size)
{
	int i;

	if (size == 1) {
		printf("\nYES");
		return;
	}
	int *leftSum = malloc(sizeof(int) * size);
	int *rightSum = malloc(sizeof(int) * size);
	leftSum[0] = 0;
	rightSum[size - 1] = 0;

	for (i = 1; i < size; i++)
		leftSum[i] = input[i - 1] + leftSum[i - 1];
	for (i = size - 2; i >= 0; i--)
		rightSum[i] = input[i + 1] + rightSum[i + 1];
	for (i = 1; i < size - 1; i++) {
		if (leftSum[i] == rightSum[i]) {
			printf("\nYES");
			break;
		}
	}
	if (i == size - 1)
		printf("\nNO");
	free(leftSum);
	free(rightSum);
	return;
}

int main()
{
	int t, i, n, *input;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		input = malloc(sizeof(int) * n);
		for (i = 0; i < n; i++)
			scanf("%d", &input[i]);
		checkEqualSum(input, n);
		free(input);
	}
	return 0;
}
