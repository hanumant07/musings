#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_set>
using namespace std;

#define s_it set<string>::iterator
#define present(c, x) (c).find(x) != (c).end()
#define tr(c, it)	\
	for(decltype((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define rtr(c, it)	\
	for(decltype((c).rbegin()) it = (c).rbegin(); it != (c).rend(); ++it)

int main()
{
	string name;
	map<string,unordered_set<string>> projects;
	map<string,string> studentList;
	map<int,set<string>> result;
	set<string> banList;
	string curr_proj;
	bool newProj = false;
	do {

		getline(cin, name);
		if (name == "0")
			break;
		if (name == "1") {
			if (newProj) {
				unordered_set<string> s;
				projects[curr_proj] = s;
			}
			tr(projects, it) {
				int cnt = it->second.size();
				if (present(result, cnt))
					result[cnt].insert(it->first);
				else
					result[cnt] = set<string>({it->first});
			}
			rtr(result, it) {
				int setSize = it->second.size();
				if (setSize <= 1) {
					cout << *(it->second.begin()) << " " <<
							it->first << endl;
					continue;
				}
				s_it it_p = it->second.begin();
				while(it_p != it->second.end()) {
					cout << *it_p << " " <<
						it->first << endl;
					++it_p;
				}

			}
			studentList.clear();
			projects.clear();
			result.clear();
			banList.clear();
			curr_proj = "";
			newProj = false;
			continue;
		}

		if (isupper(name[0])) {
			if (newProj && curr_proj != name) {
				unordered_set<string> s;
				projects[curr_proj] = s;
			}
			curr_proj = name;
			if (present(projects, name))
				continue;
			newProj = true;
			continue;
		}
		if (present(banList, name))
			continue;
		if (present(studentList, name)) {
			string project = studentList[name];
			if (project == curr_proj)
				continue;
			projects[project].erase(name);
			banList.insert(name);
			continue;
		}
		studentList[name] = curr_proj;
		if (newProj) {
			projects[curr_proj] = unordered_set<string>({name});
			newProj = false;
		} else
			projects[curr_proj].insert(name);
	} while(name != "0");
	return 0;
}
