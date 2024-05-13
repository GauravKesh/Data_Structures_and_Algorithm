//
// Created by Gaurav Kesh Roushan on 12/05/24.
//

#include <iostream>
#include <string>

using namespace std;




class Solution {
public:
	static string frequencySort(string s) {
		sort(s.begin(),s.end());
		return s;
	}
};


int main(){
	string  s= "AAbbbb";
	string k = Solution::frequencySort(s);
			cout<<k;
}