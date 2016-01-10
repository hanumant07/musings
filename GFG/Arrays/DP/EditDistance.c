/*
 * Given two strings str1 and str2 and below operations that can performed on
 * str1. Find minimum number of edits (operations) required to convert ‘str1′
 * into ‘str2′.
 *
 * Insert
 * Remove
 * Replace
 * All of the above operations are of cost=1.
 * Both the strings are of lowercase.
 *
 * Input:
 * First line contains no of test cases T, for every test case 2 integers are
 * input and then in the next line 2 strings of sizes equal to 2 integers
 * respectively are given as a input.
 *
 *
 * Output:
 * For each line minimum number of operations required.
 *
 *
 * Constraints:
 * 1<=T<=30
 * 1<= Length(str1) <= 100
 * 1<= Length(str2) <= 100
 *
 *  Example:
 *  Input:
 *  1
 *  4 5
 *  geek gesek
 *
 *  Output:
 *  1
 *
 *  Author: Hanumant Singh <hanumant07@gmail.com>
 */

/*
 * MinEdit(m, n) =  { = MinEdit(m -1, n -1), if str1[m] == str2[n];
 *				or
 *		      = 1 + min(MinEdit(m - 1, n), MinEdit(m - 1, n - 1)),
 *		      if str1[m] != str2[n];
 *		    }
 */
#include <stdio.h>

int getMin(int a, int b, int c)
{
	if (a <= b && a <= c) return a;
	if (b <= a && b <= c) return b;
	if (c <= a && c <= b) return c;
}

void getMinEdit(char *s1, char *s2, int size1, int size2)
{
	int i = 0, j;
	int sol[size1 + 1][size2 + 1];

	for (i = 0; i <= size1; i++)
		for (j = 0; j <= size2; j++)
			sol[i][j] = 0;
	for (i = 0; i < (size1 + 1); i++) {
		for (j = 0; j < (size2 + 1); j++) {
			if (i == 0)
				sol[i][j] = j;
			else if (j == 0)
				sol[i][j] = i;
			else if (s1[i - 1] == s2[j - 1])
				sol[i][j] = sol[i - 1][j -1];
			else
				sol[i][j] = getMin(1 + sol[i - 1][j - 1],
						   1 + sol[i][j - 1],
						   1 + sol[i - 1][j]);
		}
	}
	printf("\n%d", sol[size1][size2]);
	return;
}

int main()
{
	int t, size1, size2;
	char str1[100], str2[100];
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &size1, &size2);
		scanf("%s %s", str1, str2);
		getMinEdit(str1, str2, size1, size2);
	}
	return 0;
}
