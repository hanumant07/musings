				Parser
				======

ABOUT:
======
	A software parser to evaluate mathematical addition expressions

ALGORITHM:
==========
	Maintains a hashtable (unordered_map) of equations indexed by Left
	handside variable, that are still not evaluated
	Maintains a hashtable (unordered_map) of variables that have been
	evaluated.
	The use of the unordered_map<> allows us to look up the corresponding 
	associated value or equation string in O(1) time.
	A map<> maintains the keys in a tree form and provides O(logn)
	access time.
	All unsolved equations are repeatedly processed, until all variables
	have been evaluated.
	To finally sort the evaluated variables, we copy them to a map
	that sorts the input variable names.
USAGE:
======
	make
	./parser <input file>
	make clean (to delete .o)

SRCTREE:
========

		/
	        |
		|----- parser.cpp	
		|----- Makefile	
		|----- example.txt    	(sample input)
		|----- example_out.txt 	(sample output)
		|
		|-----obj/ (conatined for .o)
		|
		|	
