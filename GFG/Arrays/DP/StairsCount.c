/*
 * There are n stairs, a person standing at the bottom wants to reach the top.
 * The person can climb either 1 stair or 2 stairs at a time. Count the number
 * of ways, the person can reach the top (order does matter).
 *
 * Input:
 * The first line contains an integer 'T' denoting the total number of test
 * cases. In each test cases, an integer N will be given.
 *
 *
 * Output:
 * Print number of possible ways to reach Nth stair. Answer your output %
 * 10^9+7.
 *
 *
 * Constraints:
 * 1<=T<=1000
 * 1<=N<=100
 *
 * Example:
 * Input:
 * 1
 * 4
 * Output:
 * 5
 *
 * Hanumant Singh <hanumant07@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countStairs(int n)
{
	int i, j;
	int sol[n + 1];

	sol[0] = 1;
	sol[1] = 1;
	for (i = 2; i < n + 1; i++)
		sol[i] = sol[i - 1] + sol[i - 2];
	printf("\n%d", sol[n]);
	return;
}

int main()
{
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		countStairs(n);
	}
}
