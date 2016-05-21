
			Sensor parser
			============

About:
=====

Software provides a tool for parsing 12 bit sensor values stored in a binary
file. It generates an output file containing the 32 highet values and the
last 32 values.
The implementation is optimized for a low memory footprint.


Algorithm:
==========

The implementation uses O(1) extra memory.

a) Parsing values from input
	Value are read 3 bytes at a time. This should correspond to 2, 12 bit
	values. After performing appropriate bit operations values are unpacked

a) Tracking last 32 values
	This is achieved by implementing a circular buffer of 32 entries.
	As a new value is encountered it is inserted in its appropriate location.
	While flushin the circular buffer to output, the values are written oldest
	to most recent.

	Extra Memory: Only 32 entry array

b) Tracking max 32 values
	This is achieved by maintaining a min heap of 32 entries.
	A min heap is a binary tree with a property, that for every node other
	than the root, the value of the node is greater than that of its parent.
	This implies that the root of the tree has a minimum value.
	Retrieving the minimum value is done O(1) time.
	Inserting a new value takes O(lgn).

	1) The first 32 values are recorded as is.
	2) Once 32 values are recorded, a min heap is constructed.
	3) Every new incoming value is compared with the minimum value.
	   If its greater, the minimum value is swapped with the new value.
	4) This swap destroys the heap property described above. We repair it
	   in O(lgn) time to bring the new minimum value back to the root.
	5) While writing to output, we perform heapsort on the heap O(nlgn)
	   and write the values to the output file.

	Extra Memory: Only 32 entry array

Usage:
======
	1) Run make in /src directory this will generate parser binary

	2) From scripts directory run bash script
		./invoke_parser -i <input_file> -o <output_file> 
	
	(You may need to make parser script executable
		chmod 777 invoke_parser.sh)
	  
	
Source Tree
===========
	/
	|
	|----src/                  ( C based parser implementation)
	|     |
	|     |--parser.c 	   (Parse input file to retrieve 12 bit values)
	|     |
	|     |--record_last_val.c (Ciruclar buffer implementation for last 32
	|     |			    values)
	|     |--record_max_val.c  (Min heap implementation for max 32 values)
	|     |
        |     |--Makefile
	|     |
        |     |--obj/		   (Directory to store compiled objects)
	|     |
	|----include/
	|     |
	|     |--debug.h	   (Macros for logging errors, debug information
	|     |			    used by implemenation)
	|     |
	|     |--recval.h	   (function prototypes)
	|     |
	|     |
	|----scripts/              
	|     |
	|     |--invoke_parser.sh  (bash script for using parser tool.
	|     |			    Check usage above)


Testing
=======
	Code was implemented and tested on a Ubuntu 14.04 machine.
	

