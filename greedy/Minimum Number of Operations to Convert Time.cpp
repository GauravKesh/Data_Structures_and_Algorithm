//
// Created by Gaurav Kesh Roushan on 28/05/25.
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
	/*
 *  1. Purpose:
			Minimize operations to convert time using fixed steps: 60, 15, 5, 1 minutes.

			Steps Used:
			{60, 15, 5, 1} – always used in descending order for greedy strategy.

			Loop Logic:

			for (int step : {60, 15, 5, 1}) {
			    operations += diff / step;
			    diff %= step;
			}
		2. Intuition:

			Take as many largest steps as possible first.

			Update diff with remainder using %.

			Repeat for smaller steps.

		3.Why Greedy Works:

			All steps are multiples of each other (60 % 15 == 0, etc.).

			No benefit in using smaller steps before bigger ones.

		4.Time Complexity:
			O(1) – Constant-time loop (only 4 iterations).

		5.Example:
			For diff = 87 → 60 (1x) + 15 (1x) + 5 (2x) + 1 (2x) → 6 ops total.

*/
public:
	// Helper function to convert "HH:MM" format to total minutes
	int getTimeInMinutes(const string& timeStr) {
		int hour = stoi(timeStr.substr(0, 2));
		int minute = stoi(timeStr.substr(3, 2));
		return hour * 60 + minute;
	}

	int convertTime(string current, string correct) {
		int currentMinutes = getTimeInMinutes(current);
		int correctMinutes = getTimeInMinutes(correct);
		int diff = correctMinutes - currentMinutes;

		int operationsCount = 0;
		for (int operationStep : {60, 15, 5, 1}) {
			operationsCount += diff / operationStep;
			diff %= operationStep;
		}

		return operationsCount;
	}



};
int main(){

    return 0;
 }