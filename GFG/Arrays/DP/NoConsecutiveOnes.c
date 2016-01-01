/*
 * Problem Code: 
 * Count number of binary strings without consecutive 1’s
 *
 * Problem Description:
 * Given a positive integer N, count all possible distinct binary strings of
 * length N such that there are no consecutive 1’s.
 *
 * Input:
 * The first line of input contains an integer T denoting the number of test
 * cases. The description of T test cases follows.
 * Each test case contain an integer N representing length of the binary string.
 *
 * Output:
 * Print the count number of binary strings without consecutive 1’s of length N.
 *
 * Constraints:
 * 1 ≤ T ≤ 10
 * 1 ≤ N ≤ 70
 *
 * Example:
 * Input:
 * 2
 * 3
 * 2
 *
 * Output:
 * 5
 * 3
 *
 * Explaination:
 * For first test case 5 strings are (000, 001, 010, 100, 101)
 * For second test case 3 strings are (00,01,10)
 *
 * Author : Hanumant Singh <hanumant07@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Dynammic programming
 * 1. using subproblem solution
 * 2. A binary string of size N, can end in 0 or 1.
 * 3. if the string ends in 1, then all possible solutions for size N
 *    will include all solutions of size N - 1 endiing in 0.
 * 4. if the string ends in 0, then all possible solutions for size N
 *    will include all solutions of size N - 1 ending in 0 or 1.
 * 5. The solution for size N will be 3 + 4
 */
void noConsecutiveOnes(int N)
{
	int i;
	int *zeroEnd = malloc(sizeof(int) * (N + 1));
	int *oneEnd = malloc(sizeof(int) * (N + 1));
	memset(zeroEnd, 0, N + 1);
	memset(oneEnd, 0, N + 1);
	zeroEnd[1] = 1;
	oneEnd[1] = 1;
	for (i = 2; i < N + 1; i++) {
		zeroEnd[i] = zeroEnd[i - 1] + oneEnd[i - 1];
		oneEnd[i] = zeroEnd[i - 1];
	}
	printf("\n%d", zeroEnd[N] + oneEnd[N]);
	free(zeroEnd);
	free(oneEnd);
}

int main()
{
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		noConsecutiveOnes(n);
	}
}
