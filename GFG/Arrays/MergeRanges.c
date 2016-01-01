/*
 * Given a collection of Intervals,merge all the overlapping Intervals.
 * For example:
 *
 * Given [1,3],[2,6],[8,10],[15,18],
 *
 * return [1,6],[8,10],[15,18].
 *
 * Make sure the returned intervals are sorted.
 *
 *
 *  Input:
 *
 *  The first line contains an integer T, depicting total number of test cases. 
 *  Then following T lines contains an integer N depicting the number of
 *  Intervals and next line followed by the intervals starting and ending
 *  positions 'x' and 'y' respectively.
 *
 *
 *  Output:
 *
 *  Print the intervals after overlapping in sorted manner.
 *
 *  Constraints:
 *
 *  1 ≤ T ≤ 30
 *  1 ≤ N ≤ 100
 *  0 ≤ x ≤ y ≤ 100
 *
 *
 *  Example:
 *
 *  Input
 *  1
 *  4
 *  1 3 2 4 6 8 9 10
 *  Output
 *  1 4 6 8 9 10
 *
 * Author Hanumant Singh <hanumant07@gmail.com>
 */
#include <stdio.h>
#include <stdlib.h>

struct element {
	int start;
	int end;
	struct element *next;
	struct element *last;
};

int eCompare(const void *entry1, const void *entry2)
{
	struct element *e1 = (struct element *)entry1;
	struct element *e2 = (struct element *)entry2;

	if (e1->start > e2->start) return 1;
	if (e1->start < e2->start) return -1;
	if (e1->start == e2->start && e1->end >= e2->end) return 1;
	if (e1->start == e2->start && e1->end < e2->end) return -1;
	return 0;
}

void addRange(struct element *res, int newStart, int newEnd)
{
	struct element *range = malloc(sizeof(struct element));
	range->start = newStart;
	range->end = newEnd;
	range->next = NULL;
	if (res->next == NULL) {
		res->next = range;
		res->last = range;
		return;
	}
	res->last->next = range;
	res->last = range;
	return;
}

void mergeRanges(struct element *eArr, int size)
{
	struct element res, *iter;
	qsort(eArr, size, sizeof(struct element), eCompare);
	res.next = NULL;
	int minStart = eArr[0].start;
	int maxEnd = eArr[0].end;
	int i = 1;
	for (; i < size; i++) {
		if (eArr[i].start == minStart) {
			maxEnd = eArr[i].end > maxEnd ? eArr[i].end : maxEnd;
			continue;
		}
		if (eArr[i].start <= maxEnd) {
			maxEnd = eArr[i].end > maxEnd ? eArr[i].end : maxEnd;
			continue;
		}
		/* Hit Non overlapping range. */
		/* Add current superRange to solution set */
		addRange(&res, minStart, maxEnd);
		/* New Range inital values */
		minStart = eArr[i].start;
		maxEnd = eArr[i].end;
	}
	addRange(&res, minStart, maxEnd);
	iter = res.next;
	printf("\n");
	while (iter != NULL) {
		struct element *next = iter->next;
		printf("%d %d ", iter->start, iter->end);
		free(iter);
		iter = next;
	}

}

int main()
{
	int t, n, i;
	struct element input[100];
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &input[i].start);
			scanf("%d", &input[i].end);
		}
		mergeRanges(input, n);
	}
	return 0;
}
