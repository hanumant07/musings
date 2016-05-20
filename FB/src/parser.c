#include <errno.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "recval.h"
#include "debug.h"

/*
 * We can read in 3 bytes from the file at a time.
 * This should correspond to 2, 12 bit values.
 */
#define BUF_SIZE	3
static uint8_t buf[BUF_SIZE];
/**
 * process(): Decipher and track the 2 possible values read from input.
 * @cnt: Number of bytes populated by file read
 */
static void process(size_t cnt)
{
	uint16_t first_val, second_val;
	/*
	 * Most significant byte of first val = buf[0]
	 * Least significant Nibble of first val = Most Significant
	 *						 Nibble of buf[1]
	 */
	first_val = buf[0];
	first_val = (first_val << 4) | (buf[1] >> 4);
	record_last_val(first_val);
	record_max_val(first_val);
	/* The second value is possible only if 3 bytes were actually read */
	if (cnt == 3) {
		/*
		 * Most significant Nibble of second val = Least significant
		 *					 Nibble of buf[1]
		 * Least significant byte of second val = buf[2]
		 */
		second_val = ((buf[1] & 0xF) << 8) | buf[2];
		record_last_val(second_val);
		record_max_val(second_val);
	}
}

int main(int argc, char **args)
{
	FILE *fp, *out_fp;
	bool err = false;
	size_t cnt;
	if (argc != 3) {
		printf("argc is %d\n", argc);
		LOG_MSG(ERR, STD_ERR, "invalid args\n");
		return EINVAL;
	}
	char *fname = args[1];
	fp = fopen(fname, "rb");
	if (!fp) {
		LOG_MSG(ERR, STD_ERR, "unable to open input file");
		return EIO;
	}

	out_fp = fopen(args[2], "w");
	if (!out_fp) {
		LOG_MSG(ERR, STD_ERR, "unable to open out file");
		return EIO;
	}

	init_max_record_val();
	while (1) {
		cnt = fread(buf, sizeof(uint8_t), BUF_SIZE, fp);
		if (ferror(fp)) {
			LOG_MSG(ERR, STD_ERR, "Error in reading file\n");
			err = true;
			break;
		}
		if (cnt == 0)
			break;
		process(cnt);
		/* Reached end of file */
		if (cnt < BUF_SIZE)
			break;
		if (feof(fp))
			break;
	}
	fclose(fp);
	if (err) {
		fclose(out_fp);
		return EIO;
	}
	write_max_vals(out_fp);
	write_last_vals(out_fp);
	fclose(out_fp);
	return 0;
}
