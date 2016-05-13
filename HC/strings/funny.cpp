#include <cmath>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d\n", &n);
	while (n--) {
		string input;
		getline(cin, input);
		if (input.length() <= 2) {
			cout << "Funny" << endl;
			continue;
		}
		int lleft = 0;
		int lright = lleft + 1;
		int rright = input.length() - 1;
		int rleft = rright - 1;
		int ldiff = 0;
		int rdiff = 0;
		while (lright <= rleft && ldiff == rdiff ) {
			ldiff = abs(input[lright] - input[lleft]);
			rdiff = abs(input[rright] - input[rleft]);
			lleft++;
			lright++;
			rright--;
			rleft--;
		}
		if (ldiff == rdiff)
			cout << "Funny" << endl;
		else
			cout << "Not Funny" << endl;
	}
	return 0;
}

