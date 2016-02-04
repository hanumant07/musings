/*
 * At an open-source fair held at a major university,
 * leaders of open-source projects put sign-up
 * sheets on the wall, with the project name at the
 * top in capital letters for identification.
 * Students then signed up for projects using
 * their userids. A userid is a string of lower-case
 * letters and numbers starting with a letter.
 * The organizer then took all the sheets off the
 * wall and typed in the information.
 * Your job is to summarize the number of
 * students who have signed up for each project.
 * Some students were overly enthusiastic and put
 * their name down several times for the same
 * project. That’s okay, but they should only count
 * once. Students were asked to commit to a single
 * project, so any student who has signed up for more than one project should
 * not count for any project.
 * There are at most 10,000 students at the university, and at most 100 projects
 * were advertised.
 *
 * Input
 * The input contains several test cases, each one ending with a line that
 * starts with the digit 1. The last
 * test case is followed by a line starting with the digit 0.
 * Each test case consists of one or more project sheets. A project sheet
 * consists of a line containing
 * the project name in capital letters, followed by the userids of students, one
 * per line.
 * Output
 * For each test case, output a summary of each project sheet. The summary is
 * one line with the name
 * of the project followed by the number of students who signed up. These lines
 * should be printed in
 * decreasing order of number of signups. If two or more projects have the same
 * number of signups, they
 * should be listed in alphabetical order
 *
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2180
 * Author: Hanumant Singh <hanumant07@gmail.com>
 *
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <set>

map<string,unordered_set<string>> projects;
map<string,string> studentList;
map<int,unordered_set<string>> result;

int main()
{
	string name;
	string curr_proj;
	do {
		while(getline(cin, name) && name != "1" && name != "0") {
			if (isupper(name[0])) {
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
				projects[project].erase(name);
				continue;
			}
			studentList.insert(name);
			if (newProj) {
				projects[curr_proj] =
						unordered_set<string>(name);
				newProj = false;
			} else
				project[curr_proj].insert(name);
		}
		if (name == "1") {
			tr(projects, it) {
				int cnt = it->second.count();
				if (present(result, cnt))
					result[cnt].insert(it->first);
				else
					result[cnt] = unordered_set<string>(it->first);
			}
			tr(results, it) {
				if (it->second.count() > 1)
					

			}
			}
			studentList.clear();
			projects.clear();
			curr_proj = "";
		}
	} while(name != "0");

}
