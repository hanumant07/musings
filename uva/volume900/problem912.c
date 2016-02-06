/*
 * A mutant DNA sequence is composed by the usual DNA elements, say, for the
 * sake of simplicity,
 * A, B, C, and D and by mutant elements 1, 2, 3, 4, 5, and so on . . .
 * Only the mutant elements can mutate, and they mutate only once to A, B, C or
 * D. Then, a mutation
 * is a process that takes a mutant DNA sequence and transforms some (eventually
 * all) mutant elements
 * to normal elements.
 * For instance, let be DNA1 the following mutant DNA sequence A1CD1A2D3B2C5 and
 * MUT the
 * following mutation [(1,A),(2,B),(3,C),(4,A)] (which means mutate all
 * occurrences of 1 into A, 2
 * into B, 3 into C and 4 into A). MUT transforms DNA1 into DNA2: AACDAABDCBBC5.
 * In this case, we
 * say that DNA2 is a descendant of DNA1.
 * Two mutant DNA sequences of length n, x1, x2, . . . , xn and y1, y2, . . . ,
 * yn are equivalent under
 * mutation if, for all i such that 1 ≤ i ≤ n, xi and yi are both normal DNA
 * elements and are equal, or
 * xi and yi are both mutant DNA elements (and it is not required in this case
 * that xi and yi are equal)
 * Let DNA1 and DNA2 be two mutant DNA sequences of the same length. The
 * shortest common
 * mutation of DNA1 and DNA2, say MUT, is the shortest mutation that transforms
 * DNA1 and DNA2
 * into descendants which are equivalent under mutation. MUT is the shortest in
 * the sense that it implies
 * the transformation of the smallest number of mutant elements. Note that MUT
 * may not exist.
 * So, your work is to provide a program that reads two mutant DNA sequences and
 * replies
 * • NO, if there is no descendents of these two sequences that are equivalent
 * by mutation. In other
 * words, if there is no common mutations. Otherwise,
 * • YES and a print of the shortest common mutation, if there exists such a
 * mutation.
 * Input
 * The input will contain several test cases, each of them as described below.
 * Consecutive
 * test cases are separated by a single blank line.
 * The input for the program is structured as follow:
 * • the first line of the input contains the length m (with m ≤ 200) of the
 * considered DNA sequences
 * • the next m lines contain one mutant DNA element (A,B,C,D or a natural
 * number). They code the
 * first mutant DNA sequence.
 * • the last m lines contain one mutant DNA element (A,B,C,D or a natural
 * number). They code the
 * second mutant DNA sequence.
 * Output
 * For each test case, the output must follow the description below. The outputs
 * of two
 * consecutive cases will be separated by a blank line.
 * The output for the program is structured as follow: in case of failure (no
 * mutations were found) the
 * program simply display NO. In the other case, a mutation involving n mutant
 * elements was found and
 * so:
 * • the first line is the string ‘YES’;
 * • the n following lines describe the shortest common mutation; each line has
 * the form m d where m
 * is a mutant element (a natural number) and d the name of the associated
 * normal DNA element
 * (A, B, C or D). Note that m and d are separated by a single space. The
 * elements of the mutation
 * are sorted by the first component (the mutant element). Thus, the mutation
 * involving 1 will be
 * displayed before 2.
 *
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=11&page=show_problem&problem=853
 *
 * Author Hanumant Singh <hanumant07@gmail.com>
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUM_MUTANTS	9
int pset[NUM_MUTANTS];
char mut[NUM_MUTANTS];

void initSet()
{
	int i;
	for (i = 0; i < NUM_MUTANTS; i++) {
		pset[i] = i;
		mut[i] = 'u';
	}
}

int findSet(int i)
{
	if (pset[i] == i)
		return i;
	return pset[i] = findSet(pset[i]);
}

bool unionSet(int i, int j)
{
	int pi = findSet(i);
	int pj = findSet(j);
	if (mut[pi] != 'u' && mut[pj] != 'u' && mut[pi] != mut[pj])
		return false;
	if (mut[pi] == 'u' && mut[pj] != 'u') {
		pset[pi] = pj;
		mut[pi] = mut[pj];
		return true;
	}
	if (mut[pi] != 'u' && mut[pj] == 'u') {
		pset[pj] = pi;
		mut[pj] = mut[pi];
		return true;
	}
	return true;
}

bool isSameSet(int i, int j)
{
	return findSet(i) == findSet(j);
}

bool isNumber(char c)
{
	if (c >= '1' && c <= '9')
		return true;
	return false;
}

bool processSeq(char *S1, char *S2, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		if (S1[i] != S2[i]) {
			if (isupper(S1[i]) && isupper(S2[i]))
				return false;
			if (isNumber(S1[i]) && isNumber(S2[i])) {
				if (isSameSet(S1[i] - '1', S2[i] - '1'))
					continue;
				if (!unionSet(S1[i] - '1', S2[i] - '1'))
					return false;
				continue;
			}
			int mutant = isNumber(S1[i]) ? S1[i] - '1' :
							S2[i] - '1';
			char gene = isNumber(S1[i]) ? S2[i] : S1[i];
			int p = findSet(mutant);
			if (mut[p] == 'u')
				mut[p] = gene;
			else if (mut[p] != gene)
				return false;
		}
	}
	return true;
}

void printMut()
{
	int i;
	char gene;
	printf("YES\n");
	for (i = 0; i < NUM_MUTANTS; i++) {
		int p = findSet(i);
		gene = mut[p];
		if (gene == 'u')
			continue;
		else
			printf("%d %c\n", i + 1, gene);
	}
}

char *input = NULL;

int main()
{
	size_t t = 3;
	bool printBlank = false;
	while (1) {
		if (getline(&input, &t, stdin) == -1)
			break;
		if (input[0] == '\n')
			continue;
		if (printBlank)
				printf("\n");
		int n = atoi(input);
		int in_size = 2 * n;
		char *S1 = malloc(in_size*sizeof(char));
		char *S2 = S1 + n;
		char *iter = S1;
		initSet();
		int len;
		while (in_size--) {
			char *gene = NULL;
			if (getline(&gene, &len, stdin) == -1)
				printf("No Line\n");
			else {
				*iter = *gene;
				iter++;
				free(gene);
			}
		}
		if (!processSeq(S1, S2, n))
			printf("NO\n");
		else
			printMut();
		free(S1);
		printBlank = true;

	}
	return 0;
}

