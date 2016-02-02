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
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		char HtVertex;
		string edge;
		scanf("%c", &HtVertex);
		n = HtVertex - 'A';
		vi pset(n, -1);
		vvii AdjList(n);
		while (getline(cin, edge) && edge != "")
			AdjList[edge[0]-'A'].push_back(pair<int,int>::((edge[1]-'A'), 1));
		cout << getConnected(AdjList, pset) << endl;

	}
	return 0;
}
