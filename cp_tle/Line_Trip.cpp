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
public:
	static void lineTrip(){
	long long n,x;
	cin>>n>>x;
	vector<long long>points_array;
	points_array.push_back(0);
	while(n--){
		int points;
		cin>>points;
		points_array.push_back(points);
	}
	points_array.push_back(x);
	n = points_array.size();
	long long capacity = INT_MIN;
	for(int i=1;i<n;i++){
		if(i==n-1){
			capacity = max(capacity,(points_array[i]-points_array[i-1])*2);
		}else{
		capacity = max(capacity,(points_array[i]-points_array[i-1]));
		}
	}
	cout<<capacity<<endl;
}

};
int main(){
	int t;
	cin>>t;
	while(t--){
		Solution::lineTrip();
	}

    return 0;
 }