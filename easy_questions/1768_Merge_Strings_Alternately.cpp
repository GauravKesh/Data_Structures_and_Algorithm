//
// Created by Gaurav Kesh Roushan on 21/11/24.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	static string mergeAlternately(string word1, string word2) {
		int i = 0;
		int j = 0;
		string k;
		while(i<word1.size() || j<word2.size()){
			if(i<word1.size() && j<word2.size()){
				k+=word1[i++];
				k+=word2[j++];
			}
			else if(i<word1.size()){
				k+=word1[i++];
			}
			else if(j<word2.size()){
				k+=word2[j++];
			}else{

				i++;j++;
			}
		}
		return k;
	}
};


int main(){
	string a = "ab";
	string b = "pqrs";
	cout<<Solution::mergeAlternately(a,b);
}