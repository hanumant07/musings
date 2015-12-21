/***********************************************************
 * Author: Hanumant Singh <hanumant07@gmail.com>
 * License: GPLV2
 *
 * Write a program to print all the LEADERS in the array. An element is leader
 * if it is greater than all the elements to its right side. And the rightmost
 * element is always a leader. For example int the array {16, 17, 4, 3, 5, 2},
 * leaders are 17, 5 and 2.
 */

#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

int main()
{
	int arr[] = {16, 17, 4, 3, 5, 2};
	int leaders[ARRAY_SIZE(arr)] = {0};
	int i, lastLeader, leaderCount = 0;
	leaders[leaderCount] = arr[ARRAY_SIZE(arr) - 1];
	lastLeader = ARRAY_SIZE(arr) - 1;

	for (i = ARRAY_SIZE(arr) - 1; i >= 0; i--) {
		if (arr[i] > arr[lastLeader]) {
			leaderCount++;
			leaders[leaderCount] = arr[i];
			lastLeader = i;
		}
	}
	printf("\nLeaders are :");
	for(i = 0; i <= leaderCount; i++)
		printf("%d, ", leaders[i]);
}
