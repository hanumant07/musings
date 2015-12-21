/*******************************************************************
 * Author: Hanumant Singh <hanumant07@gmail.com>
 * License: GPLv2
 *
 * Given an array arr[] of n integers, construct a Product Array prod[] (of same
 * size) such that prod[i] is equal to the product of all the elements of arr[]
 * except arr[i]. Solve it without division operator and in O(n).
 *
 * Example:
 * arr[] = {10, 3, 5, 6, 2}
 * prod[] = {180, 600, 360, 300, 900}
 ******************************************************************/
#include <stdio.h>
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

void updateProd(int *prod, int except, int multiplier, int size) {
	int i = 0;
	for (i = 0; i < size; i++) {
		if (i == except)
			continue;
		prod[i] = prod[i] * multiplier;
	}
	printf("\n");
	for (i = 0; i < size; i++)
		printf("%d ", prod[i]);
}

int main()
{
	int arr[] = {10, 3, 5, 6, 2};
	int prod[] = {1, 1, 1, 1, 1};
	int i;
	for (i = ARRAY_SIZE(arr) - 1; i >= 0; i--)
		updateProd(prod, i, arr[i], ARRAY_SIZE(prod));
	for (i = 0; i < ARRAY_SIZE(arr); i++)
		printf("%d ", prod[i]);
}


