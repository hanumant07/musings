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

int findSet(int i)
{
	if (pset[i] == i) return i;
	return pset[i] = findSet(pset[i]);
}

void unionSet(int i, int j)
{
	cout << "performing union of " << char(i + 'A') << " " << char(j + 'A') << endl;
	pset[findSet(i)] = findSet(j);
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
	for(int i = 0; i < n; i++)
		pset[i] = i;
	for(int i = 0; i < AdjList.size(); i++) {
		int numEdges = AdjList[i].size();
		for(int j = 0; j < numEdges; j++) {
			if (!isSameSet(i, j))
				unionSet(i, j);
		}
	}
	return numOfSet();
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		char HtVertex;
		string edge;
		cin >> HtVertex;
		n = HtVertex - 'A' + 1;
		cout << "n is " << n << endl;
		vvi AdjList(n);
		while(1) {
			getline(cin, edge);
			getline(cin, edge);
			if (edge == "")
				break;
			cout << "Edge " << edge[0] << " " << edge[1] << endl;
			AdjList[edge[0]-'A'].push_back((edge[1]-'A'));
		}
		for (int i = 0; i < AdjList.size(); i++) {
			int  numEdges = AdjList[i].size();
			cout << "Adj for " << char(i + 'A') << endl;
			for(int j = 0; j < numEdges; j++)
				cout << char(AdjList[i][j] + 'A') << " ";
		}
		cout << getConnected(AdjList, n) << endl;

	}
	return 0;
}
