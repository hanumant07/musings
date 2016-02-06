/*
 * Bob, who is a network administrator, supervises a network of computers. He is
 * keeping a log connections
 * between the computers in the network. Each connection is bi–directional. Two
 * computers
 * are interconnected if they are directly connected or if they are
 * interconnected with the same computer.
 * Occasionally, Bob has to decide, quickly, whether two given computers are
 * connected, directly
 * or indirectly, according to the log information.
 * Write a program which based on information input from a text file counts the
 * number of successful
 * and the number of unsuccessful answers to the questions of the kind:
 * is computeri
 * interconnected with computerj ?
 *
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=9&page=show_problem&problem=734
 *
 * Author: Hanumant Singh <hanumant07@gmail.com>
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

#define vi vector<int>

vi pset;
vi prank;

void initSet(int n)
{
	pset.clear();
	prank.clear();
	pset.resize(n);
	prank.resize(n);
	for(int i = 0; i < n; i++) {
		pset[i] = i;
		prank[i] = 0;
	}
}

int findSet(int i)
{
	if (pset[i] == i)
		return i;
	return pset[i] = findSet(pset[i]);
}

void unionSet(int i, int j)
{
	int pi = findSet(i);
	int pj = findSet(j);

	if (prank[pi] < prank[pj]) {
		pset[pi] = pj;
		prank[pj]++;
	} else {
		pset[pj] = pi;
		prank[pi]++;
	}
}

bool isSameSet(int i, int j)
{
	return findSet(i) == findSet(j);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		string input;
		cin >> n;
		getchar();
		initSet(n);
		int success = 0;
		int unsuccessful = 0;
		int ci, cj;
		while (1) {
			char comm;
			getline(cin, input);
			if (input == "") {
				printf("%d,%d\n", success, unsuccessful);
				break;
			}
			sscanf(&input[0], "%c %d %d", &comm, &ci, &cj);
			if (comm == 'c')
				unionSet(ci - 1, cj - 1);
			if (comm == 'q') {
				if (isSameSet(ci - 1, cj - 1))
					success++;
				else
					unsuccessful++;
			}
		}
		if (t) printf("\n");

	}
	return 0;
}
