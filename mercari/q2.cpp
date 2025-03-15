//
// Created by Gaurav Kesh Roushan on 15/03/25.
//

/*This question was asked in the Mercari SWE intern role technical screening round. \n
 * I couldn't solve it at that time, but\n
 * I recently came up with a basic approach. I think it's not optimal, but it's my first attempt.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
	vector<int> ttl_cache(int n, vector<vector<int>>& data, int q, vector<int>& queries) {
		vector<int> end_times;
		vector<int> result;
		for (auto& entry : data) {
			end_times.push_back(entry[0] + entry[1]);
		}
		sort(end_times.begin(), end_times.end());
		for (int query : queries) {
			int expired_count = lower_bound(end_times.begin(), end_times.end(), query) - end_times.begin();
			int active_count = n - expired_count;
			result.push_back(active_count);
		}

		return result;
	}
};


int main() {
	int n = 3;
	vector<vector<int>> data = {{105231, 183}, {105334, 34}, {105198, 543}};
	int q = 2;
	vector<int> queries = {105338, 105410};
	Solution sol;
	vector<int> result = sol.ttl_cache(n, data, q, queries);

	for (int count : result) {
		cout << count << " ";
	}
	cout << endl;

	return 0;
}