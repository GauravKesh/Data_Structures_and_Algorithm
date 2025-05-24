//
// Created by Gaurav Kesh Roushan on 25/05/25.
//
#include <iostream>         // cin, cout, endl
#include <vector>           // vector
#include <algorithm>        // sort, reverse, lower_bound, upper_bound
#include <string>           // string, getline
#include <cmath>            // abs, sqrt, pow, ceil, floor, log
#include <set>              // set, multiset
#include <map>              // map, multimap
#include <unordered_map>    // unordered_map
#include <unordered_set>    // unordered_set
#include <stack>            // stack
#include <queue>            // queue, priority_queue
#include <deque>            // deque
#include <numeric>          // accumulate, iota, gcd, lcm
#include <limits>           // numeric_limits
#include <bitset>           // bitset
#include <sstream>          // stringstream
#include <iomanip>          // setprecision, fixed

using namespace std;

class Solution{
private:
protected:
public:
	int minTimeToType(string word) {
		int minimum_time = 0;
		int pointer_start = 97;
		int pointer_end = 122;

		for (auto ch : word) {
			int diff = abs(ch - pointer_start);
			minimum_time += min(diff, 26 - diff) + 1;
			pointer_start = ch;
		}

		return minimum_time;
	}


};
int main(){

    return 0;
 }