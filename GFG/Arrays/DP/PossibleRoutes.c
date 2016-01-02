/*
 * Given a A X B grid with initial position at top-left corner, find the number
 * of possible unique paths to reach the bottom right corner of the grid
 * from the initial position.
 * NOTE: Possible moves can be either down or right at any point in time.
 *
 *
 *  Input:
 *
 *  The first line contains an integer T, depicting total number of test cases.
 *  Then following T lines contains an two integers A and B depicting the size
 *  of the grid.
 *
 *  Output:
 *
 *  Print the number of unique paths to reach bottom-right corner from the
 *  top-left corner.
 *
 *
 *  Constraints:
 *
 *  1 ≤ T ≤ 30
 *  1 ≤ A ≤ 15
 *  1 ≤ B ≤ 15
 *
 *  Example:
 *
 *  Input
 *  2
 *  2 2
 *  3 4
 *  Output
 *  2
 *  10
 *
 *  Author : Hanumant Singh <hanumant07@gmail.com>
 *
 */

#include <stdio.h>
#include <string.h>
/* Using DP,
 * Solution space is built on solution to smaller problems
 * Solution for MxN = Solution for M-1xN + Solution for MxN-1
 */
void countRoutes(int sol[15][15], int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++)
		sol[i][0] = 1;
	for (i = 0; i < cols; i++)
		sol[0][i] = 1;
	for (i = 1; i < rows; i++) {
		for (j = 1; j < cols; j++)
			sol[i][j] = sol[i - 1][j] + sol[i][j - 1];
	}
	printf("\n%d", sol[rows - 1][cols - 1]);
	return;
}
int main()
{
	int row, col, t, sol[15][15] = {0};
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &row, &col);
		countRoutes(sol, row, col);
	}
	return 0;
}
