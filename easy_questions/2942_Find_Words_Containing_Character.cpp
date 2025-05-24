//
// Created by Gaurav Kesh Roushan on 24/05/25.
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

class Solution {
public:
	static vector<int> findWordsContaining(vector<string>& words, char x) {
		vector<int> arr;
		int n = words.size();
		for(int i=0;i<n;i++){
			if(words[i].find(x)!=string::npos){
/*
				if no position found this ois the output "string::npos"
*/
				arr.push_back(i);
			}
		}
		return arr;
	}
};
int main(){
	 vector<string>words = {"leet","code"} ;char  x = 'e';
	vector<int> arr = Solution::findWordsContaining(words,x);
	cout<<"[";
	for(auto i: arr){
		cout<<i<<",";
	}
	cout<<"]";
    return 0;
 }