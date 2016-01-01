/*
 * Given a binary string, count number of substrings that start and end with 1.
 * For example, if the input string is “00100101”, then there are three
 * substrings “1001”, “100101” and “101”.
 *
 *  Input:
 *
 *  The first line of input contains an integer T denoting the number of test
 *  cases.
 *  Each test case consist of an integer 'n' denoting the string length and next
 *  line is followed by a binary string .
 *
 *
 *  Output:
 *
 *  Print the number of substring starting and ending with 1 in a separate line.
 *
 *  Constraints:
 *
 *  1 ≤ T ≤ 40
 *  1 ≤ |s| ≤ 1000
 *
 *
 *  Example:
 *
 *  Input:
 *  1
 *  4
 *  1111
 *  Output:
 *  6
 *
 *  Author : Hanumant Singh <hanumant07@gmail.com>
 */
#include <stdio.h>

void numStrings(char *input, int size)
{
	int j = 0;
	int oneCount = 0;
	while (j < size) {
		if (input[j] == '1')
			oneCount++;
		j++;
	}
	printf ("\n%d", (oneCount*(oneCount - 1))/2);
	return;
}

int main()
{
	int t, n, i;
	char input[1000] = {'\0'};
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf("%s", input);
		numStrings(input, n);
	}
	return 0;
}
