#include <errno.h>
#include <inttypes.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "debug.h"

#define NUM_VALS	32

/* operations for min/max heap */
typedef enum ops {MIN, MAX} op_type;

/* heap */
struct data_heap {
	uint16_t heap[NUM_VALS];
	int cnt;
};

static struct data_heap data_rec;

/*
 * Utility functions
 */

static void swap_vals(uint16_t *arr, int left, int right)
{
	uint16_t temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}

/* Return minimum/maximum value on top of the heap */
static uint16_t get_top_val()
{
	return data_rec.heap[0];
}

/*
 * Evaluate for min or max.
 * Check if left operand is smaller/greater than right.
 * Helper to be used when constructing a min or max heap
 */
static inline bool eval(op_type op, uint16_t *arr, int left, int right)
{
	return op == MIN ? (arr[left] < arr[right]) : (arr[left] > arr[right]);
}

/**
 * heapify: Function to generate a heap
 * @op:	  min/max operation specifier.
 * @heap: array representing heap.
 * @root: position of the root of the resulting heap.
 * @end: size of the array that is being 'heapified'
 */
static void heapify(op_type op, uint16_t *heap, int root, int end)
{
	int swap = root;
	int lchild = 2 * root + 1;
	int rchild = 2 * root + 2;

	if (lchild < end && eval(op, heap, lchild, swap))
		swap = lchild;

	if (rchild < end && eval(op, heap, rchild, swap))
		swap = rchild;

	if (swap != root) {
		swap_vals(heap, root, swap);
		root = swap;
		heapify(op, heap, root, end);
	}
}

/**
 * @swap_min_val:
 * Function to swap in an incoming new value
 * in favor of the current minimum value.
 * This is invoked only when we have reached
 * our limit NUM_VALS (32) when inserting values.
 */
static void swap_min_val(uint16_t val)
{
	data_rec.heap[0] = val;
	/*
	 * The above deletion of the minimum value
	 * has probably recked the heap constructed so far.
	 * Generate the min heap again
	 */
	heapify(MIN, data_rec.heap, 0, data_rec.cnt);
}

static void heap_sort(int len)
{
	int i;
	uint16_t *heap = data_rec.heap;
	int end = len;
	for (i = end / 2 - 1; i >= 0; i--)
		heapify(MAX, heap, i, end);
	/*
	 * Each iteration of this loop moves the largest
	 * element in the current length, to the back of the
	 * array and reduces the size of heap by 1.
	 */
	for (i = end - 1; i >= 0; i--) {
		/* Max element is at index 1 after heapify */
		swap_vals(heap, i, 0);
		heapify(MAX, heap, 0, i);
	}
}

/* External functions */

/**
 * @init_max_record_val: Function to initialize tracking
 * of max values.
 * The values are maintained using a min heap.
 */
void init_max_record_val()
{
	data_rec.cnt = 0;
	/* We start heap at 1 to simplify child arithemetic */
	data_rec.heap[0] = -1;
}

/**
 * @record_max_val: Function to insert a new value.
 * 1. If NUM_VALS (32) has been reached, we need to
 *    determine if the value needs to be added or not.
 * 2. If max count has not been reached just insert the value
 *    in the unstructured heap.
 * 3. If the max count is reached upon insertion, then construct
 *    the heap as well before returning.
 */
void record_max_val(uint16_t val)
{
	uint16_t *heap = data_rec.heap;

	if (data_rec.cnt < NUM_VALS) {
		heap[data_rec.cnt] = val;
		data_rec.cnt++;
		if (data_rec.cnt == NUM_VALS) {
			/*
			 * We have reached our max limit.
			 * Construct the min heap
			 */
			int i;
			for (i = data_rec.cnt / 2 - 1; i >= 0; i--)
				heapify(MIN, heap, i, data_rec.cnt);
		}
		return;
	}
	/*
	 * If we have exceeded our count size,
	 * then we need to check if the minimum
	 * value can be deleted in favor of the
	 * new value
	 */
	if (val > get_top_val())
		swap_min_val(val);
	return;
}

/**
 * @write_max_vals: Function to flush out sorted record
 * Sort the values recorded using heapsort.
 */
void write_max_vals(FILE *fp)
{
	if (!fp)
		return;
	int i;
	/* We use heap sort to sort the recorded values */
	heap_sort(data_rec.cnt);
	if (fprintf(fp, "%s\n", "--Sorted Max 32 Values--") < 0) {
		LOG_MSG(ERR, STD_ERR, "error in writing to file");
		return;
	}
	for (i = 0; i < data_rec.cnt; i++) {
		if (fprintf(fp, "%d\n", data_rec.heap[i]) < 0) {
			LOG_MSG(ERR, STD_ERR, "error in writing to out file");
			break;
		}
	}
	return;
}

#ifdef TEST
void test_sort_heap()
{
	heap_sort(data_rec.cnt);
}

uint16_t get_heap_val(int index)
{
	if (index >= NUM_VALS || index < 0 || index > data_rec.cnt)
		return -1;
	return data_rec.heap[index];
}

void dump_sort_heap()
{
	int i;
	for (i = 0; i < data_rec.cnt; i++)
		printf("%d\n", data_rec.heap[i]);
}
#endif
