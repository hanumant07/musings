/*
 * Version Check
 * Return 1 if V1 > V2
 * Return 0 if V1 = V2
 * Return -1 if V1 < V2
 *
 * Author : Hanumant Singh <hanumant07@gmail.com>
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int checkVersion(char *ver1, char *ver2)
{
	if (strcmp(ver1, ver2) == 0)
		return 0;

	char *s1 = ver1;
	char *s2 = ver2;
	char *s1_next = s1;
	char *s2_next = s2;
	char *end;
	long S1 = LONG_MAX;
	long S2 = LONG_MIN;
	do {
		S1 = strtol(s1, &s1_next, 10);
		S2 = strtol(s2, &s2_next, 10);

		if (S1 > S2)
			return 1;
		if (S1 < S2)
			return -1;
		if (s1_next == s1 || s2_next == s2)
			break;
		s1 = s1_next + 1;
		s2 = s2_next + 1;

	} while(S1 == S2);
	if (S1 == S2)
		return 0;
	if (S1 < S2)
		return -1;
	if (S1 > S2)
		return 1;
}

int main(void)
{
	char ver1[] = "1.01";
	char ver2[] = "1.1";
	int res = checkVersion(ver1, ver2);
	if (res == 1)
		printf("V1 > V2\n");
	else if (res == -1)
		printf("V1 < V2");
	else
		printf("V1 == V2");
	return 0;
}
