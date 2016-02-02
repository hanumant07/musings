/*
 * Write a program to determine the number of maximal connected subgraphs of a
 * given graph.
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=400
 *
 * Author: Hanumant Singh <hanumant07@gmail.com>
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi pset;
vi prank;

int findSet(int i)
{
	if (pset[i] == i) return i;
	return pset[i] = findSet(pset[i]);
}

void unionSet(int i, int j)
{
	int pi = findSet(i);
	int pj = findSet(j);

	if (prank[pi] < prank[pj]) {
		pset[pi] = pj;
		prank[pj] += 1;
	}
	else {
		pset[pj] = pset[pi];
		prank[pi] += 1;
	}
}

bool isSameSet(int i, int j)
{
	return findSet(i) == findSet(j);
}

int numOfSet()
{
	int count = 0;
	for(int i = 0; i < pset.size(); i++)
		if (pset[i] == i)
			count++;
	return count;
}

int getConnected(vvi& AdjList, int n)
{
	pset.clear();
	pset.resize(n);
	prank.clear();
	prank.resize(n);
	for(int i = 0; i < n; i++) {
		pset[i] = i;
		prank[i] = 0;
	}
	for(int i = 0; i < AdjList.size(); i++) {
		int numEdges = AdjList[i].size();
		for(int j = 0; j < numEdges; j++) {
			if (!isSameSet(i, AdjList[i][j]))
				unionSet(i, AdjList[i][j]);
		}
	}
	return numOfSet();
}

int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n;
		char HtVertex;
		string edge;
		cin >> HtVertex;
		n = HtVertex - 'A' + 1;
		getline(cin, edge);
		vvi AdjList(n);
		while(1) {
			getline(cin, edge);
			if (edge == "")
				break;
			AdjList[edge[0]-'A'].push_back((edge[1]-'A'));
			AdjList[edge[1]-'A'].push_back((edge[0]-'A'));
		}
		cout << getConnected(AdjList, n) << endl;
		if (t) cout << endl;
	}
	return 0;
}
