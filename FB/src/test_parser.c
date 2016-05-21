#include <errno.h>
#include <inttypes.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "recval.h"
#include "debug.h"

#define SIZE		64
#define HEAP_SIZE	32
#define ARRAY_SIZE(arr)	sizeof((arr))/sizeof(*(arr))

static uint16_t input[SIZE] = {0};


/* A test descriptor
 * @name            : Name of the test in menu options
 * @test_fn_unsorted: vector invoked before sorting of input data
 * @test_fn_sorted  : vector invoked after sorting of input data
 * @data	    : auxillary test specific data passed to test vectors
 */
struct test {
	const char *name;
	int (*test_fn_unsorted)(void *, int num_entries);
	int (*test_fn_sorted)(void *, int num_entries);
	void *data;
};

/*************TEST HEAP IMPLEMENTATION***********************/
/**
 * @@setup_heap: Function to setup and feed heap data values.
 * 1. Initialize heap implementation.
 * 2. Feed input values to heap.
 * Heap should keep track of largest 32 values.
 */
static int setup_heap(void *data, int num_entries)
{
	int i;
	/* Initialize heap implementation */
	init_max_record_val();
	/* Feed data values to heap implementation */
	for(i = 0; i < num_entries; i++)
		record_max_val(input[i]);
	return 0;
}
/**
 * @@compare_heap: Function to compare input data with sorted heap.
 * 1. Sort heap
 * 2. Spit out largest 32 sorted input values and the heap
 */
static int compare_heap(void *data, int num_entries)
{
	int in, cnt = 0;
	/* sort the min heap */
	test_sort_heap();
	printf("\tinput largest 32\t  heap largest 32\t\n\n");
	in = num_entries > 32 ? num_entries - 32 : 0;
	while (in < num_entries && cnt < 32) {
		printf("INDEX[%d]\t  %d\t\t\t", cnt, input[in]);
		printf("%d\n", get_heap_val(cnt));
		cnt++;
		in++;
	}
	return 0;
}

/************PARSER INPUT/OUTPUT GENERATOR*********************/
/*
 *  parser generator data type
 *  passed as input to the input/output
 *  generator above
 */
struct parser_info {
	uint16_t last_32_vals[32];
	uint8_t last_val_cnt;
};

static struct parser_info pinfo;

/**
 * gen_parser_input(): Function to generate test input for parser
 * 1. packs the 12 bit input values in consecutive bytes in big endian format.
 * 2. if odd number of entries, last nibble is zeroed out.
 * 3. Also records the last 32 values of the input in pinfo for
 * writing to output file
 */
static int gen_parser_input(void *data, int num_entries)
{
	FILE *fp;
	int i, lval_thresh;
	uint8_t vals[3] = {0};
	struct parser_info *pinfo = (struct parser_info *)data;

	fp = fopen("sample_input.bin", "wb");
	if (!fp) {
		LOG_MSG(ERR, STD_ERR, "Unable to open sample file");
		return EIO;
	}
	lval_thresh = num_entries > 32 ? num_entries - 32 : 0;
	for(i = 0; i < num_entries;) {
		vals[0] = (input[i] >> 4) & 0xFF;
		vals[1] = (input[i] & 0xF) << 4 | 0;
		if (i >= lval_thresh) {
			pinfo->last_32_vals[pinfo->last_val_cnt] = input[i];
			pinfo->last_val_cnt++;
		}
		i++;

		if (i < num_entries) {
			vals[1] = vals[1] | ((input[i] >> 8) & 0xF);
			vals[2] = input[i] & 0xFF;
			if (fwrite(vals, sizeof(uint8_t), 3,fp) != 3) {
				LOG_MSG(ERR, STD_ERR, "unable to write to binary file");
				fclose(fp);
				return EIO;
			}
			if (i >= lval_thresh) {
				pinfo->last_32_vals[pinfo->last_val_cnt] =
								input[i];
				pinfo->last_val_cnt++;
			}
			i++;
		} else {
			if (fwrite(vals, sizeof(uint8_t), 2, fp) != 2) {
				LOG_MSG(ERR, STD_ERR, "unable to write to binary file");
				fclose(fp);
				return EIO;
			}
		}
		/* Zero out buffer */
		vals[0] = 0;
		vals[1] = 0;
		vals[2] = 0;
	}
	fclose(fp);
	printf("\nGenerated Input file sample_input.bin\n");
	return 0;
}

/**
 * gen_parser_output: Function to generate expected parser output file
 * uses pinfo to write the last 32 values to output.
 */
static int gen_parser_output(void *data, int num_entries)
{
	int i, start, end;
	FILE *fp;
	struct parser_info *pinfo = (struct parser_info *)data;

	fp = fopen("sample_out.txt", "w");

	fprintf(fp, "--Sorted Max 32 Values--\n");
	start = num_entries > 32 ? num_entries - 32 : 0;
	for(i = start; i < num_entries; i++) {
		if (fprintf(fp, "%d\n", input[i]) < 0) {
			LOG_MSG(ERR, STD_ERR, "Error in writing to out FILE");
			fclose(fp);
			return EIO;
		}
	}

	fprintf(fp, "--Last 32 Values--\n");
	end = num_entries > 32 ? 32 : num_entries;
	for(i = 0; i < end; i++) {
		if (fprintf(fp, "%d\n", pinfo->last_32_vals[i]) < 0) {
			LOG_MSG(ERR, STD_ERR, "Error in writing to out file");
			fclose(fp);
			return EIO;
		}
	}
	fclose(fp);
	printf("\nGenerated Output file sample_out.txt\n");
	return 0;
}
/************************TEST INFRASTRUCTURE***********************/

/**
 * gen_data_set: Function to generate input data
 * 1. Uses randon number generator 0 <= val <= 4095 (masx 12 bit val)
 * 2. Tries to randomly duplicate values
 */
static int gen_data_set()
{
	int i, unique = 0;
	uint16_t val;
	int num_entries = (rand() + 1) % SIZE;
	if (!num_entries)
		num_entries = 1;
	for (i = 0; i < num_entries; i++) {
		val = rand() % 4095;
		input[i] = val;
		unique = rand() % 7;
		if (!unique && i + 1 < num_entries) {
			i++;
			input[i] = val;
		}
	}
	return num_entries;
}

/* quick sort compare fn */
int comp(const void *elem1, const void *elem2)
{
	return (*(uint16_t *)elem1) - (*(uint16_t *)elem2);
}

/* Collection of Test cases */
static struct test test_cases[] = {
	{
		.name = "Generate sample input/output binary",
		.test_fn_unsorted = gen_parser_input,
		.test_fn_sorted	  = gen_parser_output,
		.data = &pinfo,
	},
	{
		.name = "Test heap implementation",
		.test_fn_unsorted = setup_heap,
		.test_fn_sorted   = compare_heap,
		.data = NULL,
	},
};


int main()
{
	int i, ret, num_entries;
	uint16_t val;
	int quit = ARRAY_SIZE(test_cases) + 1;
	int num = 0;

	struct test *selected;

	/* seed random number generator */
	srand(time(NULL));
	/* Print option menu */
	while (num != quit) {
		printf("\n Test options\n");
		for (i = 0; i < ARRAY_SIZE(test_cases); i++)
			printf("%d. %s\n", i + 1, test_cases[i].name);
		printf("%d. quit\n", i + 1);
		printf("\nEnter choice: ");
		scanf("%d", &num);
		if (num == quit)
			break;
		/* Get selected test vector */
		selected = &test_cases[num - 1];
		/* generate the data set for the test */
		num_entries = gen_data_set();
		printf("\nData set size for test %d\n", num_entries);
		/* run the selected test cases's before sort function */
		if (selected->test_fn_unsorted)
			ret = selected->test_fn_unsorted(selected->data,
								num_entries);
		if (ret)
			goto test_err;
		/* Sort the input using qsort */
		qsort(input, num_entries, sizeof(uint16_t), comp);
		/* run seleted test case's after sort function */
		if (selected->test_fn_sorted)
			ret = selected->test_fn_sorted(selected->data,
								num_entries);
		if (ret)
			goto test_err;
	}
	return 0;
test_err:
	printf("\n%s failed\n", selected->name);
	return EIO;
}
