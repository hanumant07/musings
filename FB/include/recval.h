#ifndef __RECVAL_H__
#define __RECVAL_H__
/* Track last values */
void record_last_val(uint16_t);
/* Write last values to file */
void write_last_vals(FILE *);

/* init max val tracker */
void init_max_record_val(void);
/* Track max values */
void record_max_val(uint16_t);
/* Write max values to file */
void write_max_vals(FILE *);
/* test apis */

#ifdef TEST
void test_sort_heap(void);
uint16_t get_heap_val(int);
void dump_sort_heap(void);
#endif

#endif
