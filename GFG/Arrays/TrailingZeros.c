/*
 * For an integer n find number of trailing zeroes in n! .
 *
 * Input:
 * The first line contains an integer 'T' denoting the total number of test
 * cases. In each test cases, it contains an integer 'N'.
 *
 *
 * Output:
 * In each seperate line output the answer to the problem.
 *
 *
 * Constraints:
 * 1<=T<=100
 * 1<=N<=1000
 *
 *
 * Example:
 * Input:
 * 1
 * 9
 *
 * Output:
 * 1
 *
 * Author : Hanumant Singh <hanumant07@gmail.com>
 * License: GPLv2
 *
 */
#include <stdio.h>

int trailingZeros(int n)
{
    return n <= 1 ? 0 : n/5 + trailingZeros(n/5);
}

int main() {
	int t, n;

	/* Input the number of test cases you want to run */
	scanf("%d", &t);
	/* One by one run for all input test cases */
	while (t--) {
		/* Input the number */
		scanf("%d", &n);
		/* Compute and print result */
		printf("%d\n", trailingZeros(n));
	}
	return 0;
}
