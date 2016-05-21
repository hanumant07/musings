#include <errno.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "debug.h"

#define NUM_LAST_VALS	32

/* Track Last 32 values using a circular buffer of 32 */
/**
 * @vals: List of last 32 values
 * @cnt: number of times circular buffer has been updated.
 * @index: index of the next location to update.
 */
struct valTracker {
	uint16_t vals[NUM_LAST_VALS];
	uint32_t cnt;
	int index;
};

static struct valTracker last_32;

#define RESET_INDEX	NUM_LAST_VALS - 1
static inline int update_index(int ind)
{
	return (ind + 1) & RESET_INDEX;
}

/* record a value in circular buffer */
void record_last_val(uint16_t val)
{
	int index = last_32.index;
	last_32.cnt++;
	last_32.vals[index] = val;
	last_32.index = update_index(last_32.index);
}

void write_last_vals(FILE *fp)
{
	int curr, end;
	int index = last_32.index;

	if (last_32.cnt == 32) {
		curr = 0;
		end = 31;
	}
	else if (last_32.cnt < 32) {
		curr = 0;
		end = index;
	} else {
		curr = index;
		end = index - 1;
	}
	if (fprintf(fp, "%s\n", "--Last 32 Values--") < 0) {
		LOG_MSG(ERR, STD_ERR, "error in writing to file");
		return;
	}
	while (curr != end) {
		if (fprintf(fp, "%d\n", last_32.vals[curr]) < 0)
			LOG_MSG(ERR, STD_ERR, "Unable to write to output file");
		curr = update_index(curr);
	}
	if (last_32.cnt >= 32)
		fprintf(fp, "%d\n", last_32.vals[curr]);
}


