/*
 * Given a time in AM/PM format, convert it to military (24-hour) time.
 *
 * Note: Midnight is 12:00:00AM on a 12-hour clock and 00:00:00 on a 24-hour
 * clock. Noon is 12:00:00PM on a 12-hour clock and 12:00:00 on a 24-hour clock.
 *
 * Input Format
 *
 * A time in 12-hour clock format (i.e.: hh:mm:ssAM or hh:mm:ssPM), where
 * 01≤hh≤12.
 *
 * Output Format
 *
 * Convert and print the given time in 24-hour format, where 00≤hh≤23.
 *
 * Author: Hanumant Singh <hanumant07@gmail.com>
 *
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string time;
    cin >> time;
    int out;
    size_t ind = time.rfind("PM");
    string hh = time.substr(0,2);
    out = stoi(hh, nullptr, 10);
    if ((ind != string::npos && out != 12) || (out == 12 && ind == string::npos))
       out += 12;
    out %= 24;
    string hh_out = to_string(out);
    if (out < 10)
       hh_out = "0" + hh_out;
    cout << hh_out + time.substr(2, time.length() - 4) << endl;
    return 0;
}

