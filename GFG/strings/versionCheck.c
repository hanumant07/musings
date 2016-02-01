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

char *mystrtok(char *in, char c, char **end)
{
	char *s = in;
	if (in == NULL)
		return NULL;
//	printf("Printing string and traversing\n");
	while (*s != c && *s!= '\0') {
//		printf("%c ", *s);
		s++;
	}
	if (*s == '\0') {
		*end = NULL;
		return in;
	}
	if (*s == c)
		*end = s + 1;
	*s = '\0';
	return in;
}

int checkVersion(char *ver1, char *ver2)
{
	if (strcmp(ver1, ver2) == 0)
		return 0;

	char *s1 = ver1;
	char *s2 = ver2;
	char *s1_next = s1;
	char *s2_next = s2;
	char *end;
	while(s1_next != NULL && s2_next != NULL) {
		s1 = mystrtok(s1_next, '.', &s1_next);
		s2 = mystrtok(s2_next, '.', &s2_next);
//		if (s1 == NULL || s2 == NULL)
//			break;
		long S1 = strtol(s1, &end, 10);
		long S2 = strtol(s2, &end, 10);
		printf("%ld\n", S1);
		printf("%ld\n", S2);
		if (S1 > S2)
			return 1;
		if (S1 < S2)
			return -1;
	}
	if (s1 == NULL && s2 == NULL)
		return 0;
	if (s1 == NULL && s2 != NULL)
		return -1;
	if (s1 != NULL && s2 == NULL)
		return 1;
}

int main(void)
{
	char ver1[] = "1.2.3";
	char ver2[] = "1.02.2";
	int res = checkVersion(ver1, ver2);
	if (res == 1)
		printf("V1 > V2\n");
	else if (res == -1)
		printf("V1 < V2");
	else
		printf("V1 == V2");
	return 0;
}
