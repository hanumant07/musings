/*
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1167
 *
 * Author: Hanumant Singh <hanumant07@gmail.com>
 */


#include <algorithm>
#include <map>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

typedef map<string,double>::iterator map_it;

#define present(c,x) ((c).find(x) != (c).end())


int main() {
	int t;
	string tree;
	double cnt = 0.0;
	cin >> t;
	getline(cin, tree);
	getline(cin, tree);
	while(t--) {
		map<string,double> forestMap;
		while(getline(cin, tree) && !tree.empty()) {
			if (tree == "")
				break;
			cnt++;
			if (present(forestMap, tree))
				forestMap[tree] += 1.0;
			else
				forestMap[tree] = 1.0;
		}
		map_it it = forestMap.begin();
		while(it != forestMap.end()) {
			cout << it->first << " ";
			printf("%.4f\n", (it->second/cnt)*100);
			++it;
		}
		forestMap.clear();
		cnt = 0.0;
		if (t)
			cout << endl;
	}
	return 0;
}
