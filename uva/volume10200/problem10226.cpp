#include <algorithm>
#include <map>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

typedef map<string,double>::iterator map_it;




#define present(c,x) ((c).find(x) != (c).end())
#define tr(c, it)	\
	for(map_it it = (c).begin(); it != (c).end(); ++it)


int main() {
	int t;
	string tree;
	int cnt = 0;
	scanf("%d", &t);
	getline(cin, tree);
	while(t--) {
		map<string,double> forestMap;
		getline(cin, tree);
		while(1) {

			getline(cin, tree);
			if (tree == "")
				break;
			cnt++;
//			cout << "Adding Tree " << tree << endl;
			if (present(forestMap, tree))
				forestMap[tree] += 1.0;
			else
				forestMap[tree] = 1.0;
		}
//		cout << "Processing Map"<< endl;
		map_it it = forestMap.begin();
		while(it != forestMap.end()) {
			cout << it->first << " ";
			printf("%.4f\n", (it->second/count)*100);
			++it;
		}
		forestMap.erase(forestMap.begin(), forestMap.end());
		cnt = 0;
//		if (t)
//			cout << endl;
	}
	return 0;
}
